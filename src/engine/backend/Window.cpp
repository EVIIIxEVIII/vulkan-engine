#include "Window.hpp"

#include <stdexcept>

namespace Vulkan {

Window::Window(int w, int h, std::string name) : width{w}, height{h}, windowName{name} {
    initWindow();
}

Window::~Window() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

void Window::initWindow() {
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

    window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
    glfwSetWindowUserPointer(window, this);
    glfwSetFramebufferSizeCallback(window, framebufferResizeCallback);
}

void Window::createWindowSurface(VkInstance instance, VkSurfaceKHR *surface) {
    if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS) {
        throw std::runtime_error("failed to craete window surface");
    }
}

void Window::framebufferResizeCallback(GLFWwindow *window, int width, int height) {
    auto Window = reinterpret_cast<class Window*>(glfwGetWindowUserPointer(window));
    Window->framebufferResized = true;
    Window->width = width;
    Window->height = height;
}

}

