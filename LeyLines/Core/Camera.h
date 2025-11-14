//
// Created by stan on 11/12/25.
//

#ifndef RAWENGINE_CAMERA_H
#define RAWENGINE_CAMERA_H
#include <glm/fwd.hpp>

#include "Component.h"


class Camera : public Component {
public:
    static Camera* GetActive();

    glm::mat4 GetViewMatrix();
    glm::mat4 GetProjectionMatrix();

    void Awake() override;

private:
    static Camera* activeCam;
};


#endif //RAWENGINE_CAMERA_H