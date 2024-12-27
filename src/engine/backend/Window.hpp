#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <iostream>
#include <stdexcept>

namespace Vulkan {

class Window {

public:
    Window(int width, int height, std::string title);
    ~Window();

    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

    GLFWwindow* getGLFWwindow() const;
    bool isFramebufferResized() const;

    void resetFramebufferResized();
    bool shouldClose() { return glfwWindowShouldClose(window); }

private:
    int width, height;
    std::string title;
    GLFWwindow* window;
    bool frameBufferResized;

    static void framebufferResizeCallback(GLFWwindow* window, int width, int height);
};

}
