
#include "../Game/Movement.h"

#include <GLFW/glfw3.h>

#include "../Core/Camera.h"
#include "../Core/Transform.h"

GLFWwindow* Movement::activeWindow = nullptr;

void Movement::SetActiveWindow(GLFWwindow* window) {
    activeWindow = window;
}

void Movement::Update() {

    if (glfwGetKey(activeWindow, GLFW_KEY_W) == GLFW_PRESS) {
        Camera::GetActive()->transform->Position.z -= 0.1f;
    }
    if (glfwGetKey(activeWindow, GLFW_KEY_S) == GLFW_PRESS) {
        Camera::GetActive()->transform->Position.z += 0.1f;
    }
    if (glfwGetKey(activeWindow, GLFW_KEY_A) == GLFW_PRESS) {
        Camera::GetActive()->transform->Position.x -= 0.1f;
    }
    if (glfwGetKey(activeWindow, GLFW_KEY_D) == GLFW_PRESS) {
        Camera::GetActive()->transform->Position.x += 0.1f;
    }

}