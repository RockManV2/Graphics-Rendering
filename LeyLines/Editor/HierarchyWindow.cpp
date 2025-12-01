//
// Created by chaoscatalyst on 01-12-2025.
//

#include "HierarchyWindow.h"

#include "EditorContext.h"

void HierarchyWindow::OnImGuiRender() {
    if (!editorContext.activeScene) return;

    auto& sceneObjects = editorContext.activeScene->GetGameObjects();

    for (size_t i = 0; i < sceneObjects.size(); i++) {
        if (!sceneObjects[i]) continue;

        const char* name = sceneObjects[i]->name.c_str();
        if (!name) continue;

        bool selected = (editorContext.selectedEntity == i);
        if (ImGui::Selectable(name, selected))
            editorContext.selectedEntity = static_cast<uint32_t>(i);
    }
}