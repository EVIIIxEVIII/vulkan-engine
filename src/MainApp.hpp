#pragma once

#include "engine/backend/Window.hpp"
#include "engine/backend/VulkanDevice.hpp"
#include "engine/backend/VulkanRenderer.hpp"
#include "engine/backend/VulkanSceneObject.hpp"
#include "engine/backend/VulkanDescriptors.hpp"

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
    void loadSceneObjects();

    Window window{WIDTH, HEIGHT, "Vulkan App"};
    Device device{window};
    Renderer renderer{window, device};

    std::unique_ptr<DescriptorPool> globalPool{};
    std::vector<SceneObject> sceneObjects;
};

}

