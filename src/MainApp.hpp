#pragma once

#include "engine/backend/Window.hpp"
#include "engine/backend/VulkanPipeline.hpp"
#include "engine/backend/VulkanDevice.hpp"

using namespace Vulkan;

namespace Application {

class MainApp {

public:
    static constexpr int WIDTH = 800;
    static constexpr int HEIGHT = 800;

    void run();

private:
    Window window{WIDTH, HEIGHT, "Vulkan App"};
    Device device{window};
    GraphicsPipeline graphicsPipeline{
        device,
        "./src/shaders/vert.spv",
        "./src/shaders/frag.spv",
        GraphicsPipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT)
    };
};

}

