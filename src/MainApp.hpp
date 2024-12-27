#pragma once

#include "engine/backend/Window.h"

namespace Application {

class MainApp {

public:
    static constexpr int WIDTH = 800;
    static constexpr int HEIGHT = 800;

    void run();

private:
    Vulkan::Window window{WIDTH, HEIGHT, "Vulkan App"};

};

}

