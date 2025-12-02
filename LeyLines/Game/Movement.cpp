
#include "../Game/Movement.h"

#include <GLFW/glfw3.h>

#include "../Core/Camera.h"
#include "../Core/Transform.h"
#include "../Core/Input.h"


void Movement::Update(float deltaTime) {

    if (Input::GetKeyDown(GLFW_KEY_W)) {
        Camera::GetActive()->transform->Translate(glm::vec3(0.0f, 0.0f, -0.1f));
    }
    if (Input::GetKeyDown(GLFW_KEY_S)) {
        Camera::GetActive()->transform->Translate(glm::vec3(0.0f, 0.0f, 0.1f));
    }
    if (Input::GetKeyDown(GLFW_KEY_A)) {
        Camera::GetActive()->transform->Translate(glm::vec3(-0.1f, 0.0f, 0.0f));
    }
    if (Input::GetKeyDown(GLFW_KEY_D)) {
        Camera::GetActive()->transform->Translate(glm::vec3(0.1f, 0.0f, 0.0f));
    }

}