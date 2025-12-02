//
// Created by chaoscatalyst on 02-12-2025.
//

#include "MonkeyRotator.h"

#include "Core/Transform.h"

void MonkeyRotator::Update(float deltaTime) {
    transform->Rotate(
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::radians(100.0f) * deltaTime
        );
}
