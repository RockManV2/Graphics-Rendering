//
// Created by chaoscatalyst on 01-12-2025.
//

#ifndef RAWENGINE_INSPECTORWINDOW_H
#define RAWENGINE_INSPECTORWINDOW_H
#include "EditorWindow.h"


struct EditorContext;

class InspectorWindow : public EditorWindow {
public:
    InspectorWindow(EditorContext& pContext) : editorContext(pContext) {}

    const char* GetName() override { return "Inspector"; }
    void OnImGuiRender() override;

private:
    EditorContext& editorContext;
};


#endif //RAWENGINE_INSPECTORWINDOW_H