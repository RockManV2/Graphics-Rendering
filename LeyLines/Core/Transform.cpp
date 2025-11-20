
#include "Transform.h"


#define GLM_ENABLE_EXPERIMENTAL
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtx/matrix_decompose.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

void Transform::Translate(glm::vec3 translation) {
    modelMatrix = glm::translate(modelMatrix, translation);
}

glm::vec3 Transform::GetPosition() {
    return modelMatrix[3];
}

glm::vec3 Transform::GetRotation() {
    glm::quat rotation;
    glm::vec3 z, t , s;
    glm::vec4 p;
    glm::decompose(modelMatrix, z, rotation, t,s, p);
    return glm::eulerAngles(rotation);
}

glm::vec3 Transform::GetScale() {
    glm::vec3 scale;
    glm::vec3 t , s;
    glm::quat r;
    glm::vec4 p;
    glm::decompose(modelMatrix, scale, r, t,s, p);
    return scale;
}

void Transform::SetPosition(glm::vec3 position) {
    modelMatrix[3].x = position.x;
    modelMatrix[3].y = position.y;
    modelMatrix[3].z = position.z;
}

void Transform::Rotate(glm::vec3 axis, float radians) {
    modelMatrix = glm::rotate(modelMatrix, radians, axis);
}

void Transform::SetRotation(glm::vec3 newRotation) {
    glm::quat rotation;
    glm::vec3 scale, translation, skew;
    glm::vec4 perspective;

    glm::decompose(modelMatrix, scale, rotation, translation, skew, perspective);

    // from the viewpoint of world space operations, the order (see Unity inspector) is scale, rotate, translate: combined M = TRS
    //  glm methods use "local space operation" viewpoint
    // Also, if the argument here is Euler angles, you need to make 3 rotation matrices: pitch, heading, bank.
    //glm::mat4 newMatrix = glm::translate(glm::mat4(1.0f), translation)
    //                     * glm::scale(glm::mat4(1.0f), scale);

    //modelMatrix = glm::rotate(newMatrix, new)
}

void Transform::Scale(glm::vec3 scale) {
    modelMatrix = glm::scale(modelMatrix, scale);
}

glm::mat4 Transform::GetModelMatrix() const {
    return this->modelMatrix;
}