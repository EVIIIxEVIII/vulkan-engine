#pragma once

#include <GLFW/glfw3.h>
#include <iostream>
#include <stdexcept>

class Window {

public:
    Window(int width, int height, std::string title);
    virtual ~Window();

    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

    GLFWwindow* getGLFWwindow() const;
    bool isFramebufferResized() const;

    void resetFramebufferResized();

private:
    int width, height;
    std::string title;
    GLFWwindow* window;
    bool frameBufferResized;

    static void framebufferResizeCallback(GLFWwindow* window, int width, int height);
    void onFramebufferResize(int width, int height);
};
