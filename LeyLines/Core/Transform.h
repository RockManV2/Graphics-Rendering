
#ifndef RAWENGINE_TRANSFORM_H
#define RAWENGINE_TRANSFORM_H

#include <glm/glm.hpp>

#include "Component.h"

class Transform : public Component {
public:
    Transform() {
        modelMatrix = glm::mat4(1.0f);
    }

    glm::vec3 GetPosition();
    glm::vec3 GetRotation();
    glm::vec3 GetScale();

    void Translate(glm::vec3 translation);
    void SetPosition(glm::vec3 position);

    void Rotate(glm::vec3 axis, float radians);
    void SetRotation(glm::vec3 rotation);

    void Scale(glm::vec3 scale);

    glm::mat4 GetModelMatrix() const;

private:
    glm::mat4 modelMatrix;
};


#endif //RAWENGINE_TRANSFORM_H