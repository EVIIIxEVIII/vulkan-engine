#pragma once

#include <vector>
#include <memory>

#include "engine/backend/Window.hpp"
#include "engine/backend/VulkanPipeline.hpp"
#include "engine/backend/VulkanDevice.hpp"
#include "engine/backend/VulkanSwapChain.hpp"
#include "engine/backend/VulkanModel.hpp"

using namespace Vulkan;

namespace Application {

class MainApp {

public:
    static constexpr int WIDTH = 800;
    static constexpr int HEIGHT = 600;

    MainApp();
    ~MainApp();

    MainApp(const MainApp&) = delete;
    MainApp operator=(const MainApp&) = delete;

    void run();

private:
    void loadModels();
    void createPipelineLayout();
    void createPipeline();
    void createCommandBuffers();
    void drawFrame();

    Window window{WIDTH, HEIGHT, "Vulkan App"};
    Device device{window};
    SwapChain swapChain{device, window.getExtent()};
    std::unique_ptr<Pipeline> pipeline;
    VkPipelineLayout pipelineLayout;
    std::vector<VkCommandBuffer> commandBuffers;
    std::unique_ptr<Model> model;
};

}

