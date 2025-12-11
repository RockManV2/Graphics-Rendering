
#include "Transform.h"


#define GLM_ENABLE_EXPERIMENTAL
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtx/matrix_decompose.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

glm::mat4 Transform::GetModelMatrix() const {
    return this->modelMatrix;
}

void Transform::Translate(glm::vec3 translation) {
    position += translation;
}

void Transform::Update(float deltaTime) {
    glm::mat4 matrix = glm::mat4(1.0f);
    matrix = glm::scale(matrix, scale);
    matrix = glm::rotate(matrix, glm::radians(rotation.x), glm::vec3(1, 0, 0));
    matrix = glm::rotate(matrix, glm::radians(rotation.y), glm::vec3(0, 1, 0));
    matrix = glm::rotate(matrix,  glm::radians(rotation.z), glm::vec3(0, 0, 1));

    matrix =

    matrix = glm::translate(matrix, position);
    modelMatrix = matrix;
}
