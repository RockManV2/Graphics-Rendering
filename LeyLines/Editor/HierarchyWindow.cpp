//
// Created by chaoscatalyst on 01-12-2025.
//

#include "HierarchyWindow.h"

#include "EditorContext.h"
#include <format>

void HierarchyWindow::OnImGuiRender() {
    if (!editorContext.activeScene) return;

    auto& sceneObjects = editorContext.activeScene->GetGameObjects();

    for (size_t i = 0; i < sceneObjects.size(); i++) {
        if (!sceneObjects[i]) continue;

        std::string name = sceneObjects[i]->name;

        if (ImGui::Selectable((name + "##" + std::to_string(i)).c_str()))
            editorContext.selectedEntity = sceneObjects[i];
    }
}