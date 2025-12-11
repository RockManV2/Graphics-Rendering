
#ifndef RAWENGINE_TRANSFORM_H
#define RAWENGINE_TRANSFORM_H

#include <cstdio>
#include <glm/glm.hpp>

#include "Component.h"
#include "imgui.h"
#include "Editor/IInspectable.h"

class Transform : public Component, public IInspectable {
public:
    Transform() {
        modelMatrix = glm::mat4(1.0f);
    }

    glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 rotation = glm::vec3(0.0f, 0.0f, 0.0f);;
    glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f);;

    const char* GetName() override { return "Transform"; }

    void Translate(glm::vec3 translation);

    glm::mat4 GetModelMatrix() const;

    void Update(float deltaTime) override;

    void DrawInspector() override {
        ImGui::InputFloat3("Position", (float*)&position);
        ImGui::InputFloat3("Rotation", (float*)&rotation);
        ImGui::InputFloat3("Scale", (float*)&scale);
    }
private:
    glm::mat4 modelMatrix;
};


#endif //RAWENGINE_TRANSFORM_H