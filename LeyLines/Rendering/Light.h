//
// Created by stano on 12/4/25.
//

#ifndef RAWENGINE_LIGHT_H
#define RAWENGINE_LIGHT_H

#include "Core/Component.h"
#include "SceneManagement/SceneManager.h"


class Light : public Component {
public:
     ~Light() = default;
    void Awake() {
        SceneManager::GetActiveScene()->RegisterLight(this);
    }

    glm::vec4 color = glm::vec4(0, 0,0,1);
};


#endif //RAWENGINE_LIGHT_H