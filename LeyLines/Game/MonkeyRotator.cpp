//
// Created by chaoscatalyst on 02-12-2025.
//

#include "MonkeyRotator.h"

#include "Core/Transform.h"

void MonkeyRotator::Update(float deltaTime) {
    transform->rotation.y += deltaTime * 100.0f;
}
