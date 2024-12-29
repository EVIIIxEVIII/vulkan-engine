#include "Window.hpp"
#include <GLFW/glfw3.h>
#include <stdexcept>
#include <vulkan/vulkan_core.h>

Vulkan::Window::Window(int width, int height, std::string title):
    width(width), height(height), title(title), frameBufferResized(false)
{
    if(!glfwInit()) {
        throw std::runtime_error("Failed to init GLFW!");
    }

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(width, height, title.data(), nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window!");
    }

    glfwSetWindowUserPointer(window, static_cast<void*>(this));
    glfwSetFramebufferSizeCallback(window, framebufferResizeCallback);
}

GLFWwindow* Vulkan::Window::getGLFWwindow() const {
    return window;
}

bool Vulkan::Window::isFramebufferResized() const {
    return frameBufferResized;
}

void Vulkan::Window::createWindowSurface(VkInstance instance, VkSurfaceKHR *surface) {
    if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS) {
        throw std::runtime_error("failed to create window surface");
    }
}

void Vulkan::Window::resetFramebufferResized() {
    frameBufferResized = false;
}

Vulkan::Window::~Window() {
    glfwDestroyWindow(window);
    glfwTerminate();
};

void Vulkan::Window::framebufferResizeCallback(GLFWwindow* window, int width, int height) {
    auto windowInstance = static_cast<Window*>(glfwGetWindowUserPointer(window));
    if (windowInstance) {
        windowInstance->frameBufferResized = true;
        windowInstance->width = width;
        windowInstance->height = height;
    }
}
