//
// Created by chaoscatalyst on 01-12-2025.
//

#ifndef RAWENGINE_HIERARCHY_H
#define RAWENGINE_HIERARCHY_H
#include "EditorWindow.h"



struct EditorContext;

class HierarchyWindow : public EditorWindow {
public:
    HierarchyWindow(EditorContext& pContext) : editorContext(pContext) {}

    const char* GetName() override { return "Hierarchy"; }
    void OnImGuiRender() override;

private:
    EditorContext& editorContext;
};


#endif //RAWENGINE_HIERARCHY_H