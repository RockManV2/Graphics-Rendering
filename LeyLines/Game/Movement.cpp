
#include "../Game/Movement.h"

#include <GLFW/glfw3.h>

#include "../Core/Camera.h"
#include "../Core/Transform.h"
#include "../Core/Input.h"


void Movement::Update() {

    if (Input::GetKeyDown(GLFW_KEY_W)) {
        Camera::GetActive()->transform->Position.z -= 0.1f;
    }
    if (Input::GetKeyDown(GLFW_KEY_S)) {
        Camera::GetActive()->transform->Position.z += 0.1f;
    }
    if (Input::GetKeyDown(GLFW_KEY_A)) {
        Camera::GetActive()->transform->Position.x -= 0.1f;
    }
    if (Input::GetKeyDown(GLFW_KEY_D)) {
        Camera::GetActive()->transform->Position.x += 0.1f;
    }

}