
#include <glad/glad.h>
#include "RenderWindow.h"
#include <stdexcept>


RenderWindow::RenderWindow(std::string name) {
    if (!glfwInit()) {
        throw std::runtime_error("Failed to initialize GLFW");
    }

    GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* mode = glfwGetVideoMode(primaryMonitor);

    width = mode->width;
    height = mode->height;

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    glWindow = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);
    if (!glWindow) {
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window");
    }

    glfwMakeContextCurrent(glWindow);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        glfwDestroyWindow(glWindow);
        glfwTerminate();
        throw std::runtime_error("Failed to initialize GLAD");
    }

    glEnable(GL_DEPTH_TEST);
    glFrontFace(GL_CCW);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

RenderWindow::~RenderWindow() {
    if (glWindow) {
        glfwDestroyWindow(glWindow);
    }
    glfwTerminate();
}

void RenderWindow::SetFrameBufferCallback(std::function<void(GLFWwindow *, int, int)> callback) {
    glfwSetFramebufferSizeCallback(glWindow, [](GLFWwindow* win, int w, int h) {
        auto func = reinterpret_cast<std::function<void(GLFWwindow*, int, int)>*>(glfwGetWindowUserPointer(win));
        if (func) (*func)(win, w, h);
    });
    glfwSetWindowUserPointer(glWindow, &callback);
}

