#include "MainApp.hpp"
#include "engine/backend/VulkanDescriptors.hpp"
#include "engine/backend/VulkanSceneObject.hpp"
#include "engine/backend/VulkanSimpleRenderSystem.hpp"
#include "engine/backend/VulkanCamera.hpp"
#include "engine/backend/VulkanMovementController.hpp"
#include "engine/backend/VulkanBuffer.hpp"
#include "engine/backend/VulkanSwapChain.hpp"

#include <GLFW/glfw3.h>
#include <glm/ext/matrix_float2x2.hpp>
#include <glm/geometric.hpp>
#include <glm/trigonometric.hpp>
#include <memory>
#include <vulkan/vulkan_core.h>
#include <glm/gtc/constants.hpp>
#include <chrono>

namespace Application {

struct GlobalUbo {
    alignas(16) glm::mat4 projectionView{1.f};
    alignas(16) glm::vec3 lightDirection = glm::normalize(glm::vec3{1.f, -3.f, -1.f});
};

MainApp::MainApp() {
    globalPool = DescriptorPool::Builder(device)
        .setMaxSets(SwapChain::MAX_FRAMES_IN_FLIGHT)
        .addPoolSize(VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, SwapChain::MAX_FRAMES_IN_FLIGHT)
        .build();

    loadSceneObjects();
}

MainApp::~MainApp() {}

void MainApp::run() {
    std::vector<std::unique_ptr<Buffer>> uboBuffers(SwapChain::MAX_FRAMES_IN_FLIGHT);
    for (int i = 0; i < uboBuffers.size(); i++) {
        uboBuffers[i] = std::make_unique<Buffer>(
            device,
            sizeof(GlobalUbo),
            1,
            VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT,
            VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT,
            device.properties.limits.minUniformBufferOffsetAlignment
        );

        uboBuffers[i]->map();
    }

    auto globalSetLayout =
        DescriptorSetLayout::Builder(device)
            .addBinding(0, VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, VK_SHADER_STAGE_VERTEX_BIT)
            .build();

    std::vector<VkDescriptorSet> globalDescriptorSets(SwapChain::MAX_FRAMES_IN_FLIGHT);
    for (int i = 0; i < globalDescriptorSets.size(); i++) {
        auto bufferInfo = uboBuffers[i]->descriptorInfo();
        DescriptorWriter(*globalSetLayout, *globalPool)
            .writeBuffer(0, &bufferInfo)
            .build(globalDescriptorSets[i]);
    }

    SimpleRenderSystem simpleRenderSystem{
        device,
        renderer.getSwapChainRenderPass(),
        globalSetLayout->getDescriptorSetLayout()
    };

    Camera camera{};
    // camera.setViewDirection(glm::vec3(0.f), glm::vec3(0.5, 0.f, 1.f));
    camera.setViewTarget(glm::vec3(-1.f, -2.f, 2.f), glm::vec3(0.f, 0.f, 2.5f));

    auto viewerObject = SceneObject::createSceneObject();
    MovementController cameraController{};

    auto currentTime = std::chrono::high_resolution_clock::now();

    while (!window.shouldClose()) {
        glfwPollEvents();

        auto newTime = std::chrono::high_resolution_clock::now();
        float frameTime = std::chrono::duration<float, std::chrono::seconds::period>(newTime - currentTime).count();
        currentTime = newTime;

        cameraController.moveInPlaneXZ(window.getGLFWWindow(), frameTime, viewerObject);
        camera.setViewYXZ(viewerObject.transform.translation, viewerObject.transform.rotation);

        float aspect = renderer.getAspectRatio();
        // camera.setOrthographicProjection(-aspect, aspect, -1, 1, -1, 1);
        camera.setPerspectiveProjection(glm::radians(90.f), aspect, 0.1f, 10.f);

        if (auto commandBuffer = renderer.beginFrame()) {
            int frameIndex = renderer.getFrameIndex();
            FrameInfo frameInfo{
                frameIndex,
                frameTime,
                commandBuffer,
                camera,
                globalDescriptorSets[frameIndex]
            };

            // update data
            GlobalUbo ubo{};
            ubo.projectionView = camera.getProjection() * camera.getView();
            uboBuffers[frameIndex]->writeToBuffer((void*)&ubo);
            uboBuffers[frameIndex]->flush();

            // render
            renderer.beginSwapChainRenderPass(commandBuffer);
            simpleRenderSystem.renderSceneObjects(frameInfo, sceneObjects);
            renderer.endSwapChainRenderPass(commandBuffer);
            renderer.endFrame();
        }
    }

    vkDeviceWaitIdle(device.device());
};

void MainApp::loadSceneObjects() {
    std::shared_ptr<Model> model = Model::createModelFromFile(device, "models/flat_vase.obj");
    auto sceneObj = SceneObject::createSceneObject();
    sceneObj.model = model;
    sceneObj.transform.translation = {.0f, .5f, 2.5f};
    sceneObj.transform.scale = 10.f;

    sceneObjects.push_back(std::move(sceneObj));

    std::shared_ptr<Model> model2 = Model::createModelFromFile(device, "models/flat_vase.obj");
    auto sceneObj2 = SceneObject::createSceneObject();
    sceneObj2.model = model;
    sceneObj2.transform.translation = {2.f, .1f, 3.5f};
    sceneObj2.transform.scale = 5.f;

    sceneObjects.push_back(std::move(sceneObj2));
}

}
