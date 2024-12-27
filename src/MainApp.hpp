#pragma once

#include "engine/backend/Window.hpp"
#include "engine/backend/VulkanPipeline.hpp"

namespace Application {

class MainApp {

public:
    static constexpr int WIDTH = 800;
    static constexpr int HEIGHT = 800;

    void run();

private:
    Vulkan::Window window{WIDTH, HEIGHT, "Vulkan App"};
    Vulkan::GraphicsPipeline graphicsPipeline{"./src/shaders/vert.spv", "./src/shaders/frag.spv"};
};

}

