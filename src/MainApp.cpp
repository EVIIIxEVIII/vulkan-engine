#include "MainApp.hpp"
#include <GLFW/glfw3.h>

namespace Application {

void MainApp::run() {
    while (!window.shouldClose()) {
        glfwPollEvents();
    }

};


}
