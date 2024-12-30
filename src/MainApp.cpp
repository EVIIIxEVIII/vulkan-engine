// #include "MainApp.hpp"
#include "engine/backend/VulkanPipeline.hpp"
#include "engine/backend/VulkanSceneObject.hpp"
#include "engine/backend/VulkanSimpleRenderSystem.hpp"

// #include <GLFW/glfw3.h>
// #include <glm/ext/matrix_float2x2.hpp>
// #include <memory>
// #include <array>
// #include <stdexcept>
// #include <vulkan/vulkan_core.h>
// #include <glm/gtc/constants.hpp>
//
// namespace Application {
//
// MainApp::MainApp() {
//     loadSceneObjects();
// }
//
// MainApp::~MainApp() {}
//
// void MainApp::run() {
//     SimpleRenderSystem simpleRenderSystem{device, renderer.getSwapChainRenderPass()};
//
//     while (!window.shouldClose()) {
//         glfwPollEvents();
//         if (auto commandBuffer = renderer.beginFrame()) {
//             renderer.beginSwapChainRenderPass(commandBuffer);
//             simpleRenderSystem.renderSceneObjects(commandBuffer, sceneObjects);
//             renderer.endSwapChainRenderPass(commandBuffer);
//             renderer.endFrame();
//         }
//     }
//
//     vkDeviceWaitIdle(device.device());
// };
//
// void MainApp::loadSceneObjects() {
//     std::vector<Model::Vertex> vertices {
//         {{ 0.0f, -0.5f }, { 1.0f, 0.0f, 0.0f }},
//         {{ 0.5f,  0.5f }, { 0.0f, 1.0f, 0.0f }},
//         {{-0.5f,  0.5f }, { 0.0f, 0.0f, 1.0f }}
//     };
//     auto model = std::make_shared<Model>(device, vertices);
//
//     auto triangle = SceneObject::createSceneObject();
//     triangle.model = model;
//     triangle.color = {.1f, .8f, .1f};
//     triangle.transform2d.translation.x = .2f;
//     triangle.transform2d.scale = {2.f, .5f};
//     triangle.transform2d.rotation = .25f * glm::two_pi<float>();
//
//     sceneObjects.push_back(std::move(triangle));
// }
//
// }
