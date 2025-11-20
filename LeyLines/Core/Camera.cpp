//
// Created by stan on 11/12/25.
//

#include "Camera.h"
#include "Transform.h"

#include <glm/fwd.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>


Camera* Camera::activeCam = nullptr;

Camera* Camera::GetActive() {
    return activeCam;
}

glm::mat4 Camera::GetViewMatrix() {
    glm::mat4 cameraMatrix = glm::mat4(1.0f);
    cameraMatrix = glm::translate(cameraMatrix, transform->GetPosition());
    return glm::inverse(cameraMatrix);

}

glm::mat4 Camera::GetProjectionMatrix() {
    int g_width = 800;
    int g_height = 600;
    return glm::perspective(glm::radians(45.0f), static_cast<float>(g_width) / static_cast<float>(g_height), 0.1f, 100.0f);
}

void Camera::Awake() {
    if (activeCam == nullptr)
        activeCam = this;

    transform->GetPosition() = glm::vec3(0.0f, 0.0f, 10.0f);
}