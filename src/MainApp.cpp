#include "MainApp.hpp"
#include "engine/backend/VulkanSceneObject.hpp"
#include "engine/backend/VulkanSimpleRenderSystem.hpp"
#include "engine/backend/VulkanCamera.hpp"
#include "engine/backend/VulkanMovementController.hpp"

#include <GLFW/glfw3.h>
#include <glm/ext/matrix_float2x2.hpp>
#include <glm/trigonometric.hpp>
#include <memory>
#include <vulkan/vulkan_core.h>
#include <glm/gtc/constants.hpp>
#include <chrono>

namespace Application {

MainApp::MainApp() {
    loadSceneObjects();
}

MainApp::~MainApp() {}

void MainApp::run() {
    SimpleRenderSystem simpleRenderSystem{device, renderer.getSwapChainRenderPass()};
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
            renderer.beginSwapChainRenderPass(commandBuffer);
            simpleRenderSystem.renderSceneObjects(commandBuffer, sceneObjects, camera);
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
