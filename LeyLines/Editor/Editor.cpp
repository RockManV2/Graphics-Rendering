//
// Created by chaoscatalyst on 01-12-2025.
//

#include "Editor.h"
#include "imgui.h"
#include "imgui_internal.h"

struct ImGuiDockNode;

void Editor::Render() {
    BeginDockSpace();

    for (EditorWindow* window : editorWindows)
        window->Draw();

    EndDockSpace();
}

void Editor::BeginDockSpace() {
    static bool dockspaceOpen = true;
    ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoCollapse |
                                    ImGuiWindowFlags_NoResize |
                                    ImGuiWindowFlags_NoMove;

    ImGuiViewport* viewport = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(viewport->WorkPos);
    ImGui::SetNextWindowSize(viewport->WorkSize);
    ImGui::SetNextWindowViewport(viewport->ID);

    window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoBringToFrontOnFocus;

    ImGui::Begin("DockSpace Window", &dockspaceOpen, window_flags);

    ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
    ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f));

    ImGui::End();
}


void Editor::EndDockSpace() {

}