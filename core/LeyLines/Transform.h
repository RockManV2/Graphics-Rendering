
#ifndef RAWENGINE_TRANSFORM_H
#define RAWENGINE_TRANSFORM_H

#include <glm/glm.hpp>

#include "Component.h"

class Transform : Component {
public:
    glm::vec2 Position;
    glm::vec2 Origin;
    glm::vec2 Scale;
    glm::vec2 Rotation;

    void Start() override;
};


#endif //RAWENGINE_TRANSFORM_H