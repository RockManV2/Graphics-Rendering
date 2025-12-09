//
// Created by stano on 12/4/25.
//

#ifndef RAWENGINE_LIGHT_H
#define RAWENGINE_LIGHT_H

#include "Core/Component.h"
#include "SceneManagement/SceneManager.h"
#include <imgui.h>

class Light : public Component, public IInspectable {
public:
     ~Light() = default;

    const char* GetName() override { return "Light"; }

    void Awake() {
        SceneManager::GetActiveScene()->RegisterLight(this);
    }

    glm::vec4 color = glm::vec4(0, 0,0,1);

    void DrawInspector() override {
        ImGui::ColorEdit3("Color", (float*)&color);
    }
};


#endif //RAWENGINE_LIGHT_H