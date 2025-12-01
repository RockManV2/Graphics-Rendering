//
// Created by chaoscatalyst on 01-12-2025.
//

#ifndef RAWENGINE_SCENEWINDOW_H
#define RAWENGINE_SCENEWINDOW_H
#include "EditorWindow.h"


struct EditorContext;

class SceneWindow : public EditorWindow {
public:
    SceneWindow(EditorContext& pContext) : editorContext(pContext) {}

    const char* GetName() override { return "Scene"; }
    void OnImGuiRender() override;

private:
    EditorContext& editorContext;
};


#endif //RAWENGINE_HIERARCHY_H
