//
// Created by chaoscatalyst on 01-12-2025.
//

#ifndef RAWENGINE_EDITORWINDOW_H
#define RAWENGINE_EDITORWINDOW_H

#include "imgui.h"


class EditorWindow {
public:
    EditorWindow() = default;
    virtual ~EditorWindow() = default;

    virtual const char* GetName() = 0;
    virtual void OnImGuiRender() = 0;

    bool open = true;

    void Draw() {
        if (!open)
            return;

        if (ImGui::Begin(GetName(), &open)) {
            OnImGuiRender();
        }
        ImGui::End();
    }
};


#endif //RAWENGINE_EDITORWINDOW_H