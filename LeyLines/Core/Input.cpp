
#include "Input.h"

GLFWwindow* Input::window = nullptr;


void Input::SetWindow(GLFWwindow *newWindow) {
    window = newWindow;
}

bool Input::GetKeyDown(int key) {
    if (glfwGetKey(window, key) == GLFW_PRESS) {
        return true;
    }
    return false;
}
