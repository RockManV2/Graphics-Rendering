//
// Created by chaoscatalyst on 01-12-2025.
//

#include "InspectorWindow.h"
#include "EditorContext.h"


void InspectorWindow::OnImGuiRender() {
    ImGui::Begin("Inspector");

    if (editorContext.selectedEntity != nullptr)
    {
        for (Component* c : editorContext.selectedEntity->GetAllComponents())
        {
            if (auto* insp = dynamic_cast<IInspectable*>(c))
            {
                if (ImGui::CollapsingHeader(c->GetName()))
                    insp->DrawInspector();
            }
        }
    }
    else
    {
        ImGui::Text("No object selected.");
    }

    ImGui::End();

}