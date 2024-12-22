#include "Window.h"

Window::Window(int width, int height, std::string title):
    width(width), height(height), title(title), frameBufferResized(false)
{
    if(!glfwInit()) {
        throw std::runtime_error("Failed to init GLFW!");
    }

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    window = glfwCreateWindow(width, height, title.data(), nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window!");
    }

    glfwSetWindowUserPointer(window, static_cast<void*>(this));
    glfwSetFramebufferSizeCallback(window, framebufferResizeCallback);
}

GLFWwindow* Window::getGLFWwindow() const {
    return window;
}

bool Window::isFramebufferResized() const {
    return frameBufferResized;
}

void Window::resetFramebufferResized() {
    frameBufferResized = false;
}

Window::~Window() {
    glfwDestroyWindow(window);
    glfwTerminate();
};

void Window::framebufferResizeCallback(GLFWwindow* window, int width, int height) {
    auto windowInstance = static_cast<Window*>(glfwGetWindowUserPointer(window));
    if (windowInstance) {
        windowInstance->onFramebufferResize(width, height);
    }
}

void Window::onFramebufferResize(int width, int height) {
    frameBufferResized = true;
}
