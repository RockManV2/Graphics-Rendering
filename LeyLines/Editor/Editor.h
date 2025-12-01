//
// Created by chaoscatalyst on 01-12-2025.
//

#ifndef RAWENGINE_EDITOR_H
#define RAWENGINE_EDITOR_H
#include <vector>

#include "EditorWindow.h"


class Editor {
public:
    Editor() = default;
    ~Editor() = default;

    void AddWindow(EditorWindow* window) {
        editorWindows.push_back(window);
    }

    void Render();

private:
    void BeginDockSpace();
    void EndDockSpace();
    std::vector<EditorWindow*> editorWindows;
};


#endif //RAWENGINE_EDITOR_H