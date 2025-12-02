//
// Created by chaoscatalyst on 02-12-2025.
//

#ifndef RAWENGINE_PROJECTWINDOW_H
#define RAWENGINE_PROJECTWINDOW_H

#include "EditorWindow.h"

struct EditorContext;

class ProjectWindow : public EditorWindow {
public:
    ProjectWindow(EditorContext& pContext) : editorContext(pContext) {}

    const char* GetName() override { return "Project"; }
    void OnImGuiRender() override;

private:
    EditorContext& editorContext;
};



#endif //RAWENGINE_PROJECTWINDOW_H