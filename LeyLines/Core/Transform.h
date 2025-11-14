
#ifndef RAWENGINE_TRANSFORM_H
#define RAWENGINE_TRANSFORM_H

#include <glm/glm.hpp>

#include "Component.h"

class Transform : public Component {
public:
    glm::vec3 Position;
    glm::vec3 Origin;
    glm::vec3 Scale;
    glm::vec3 Rotation;

    void Start() override;
};


#endif //RAWENGINE_TRANSFORM_H