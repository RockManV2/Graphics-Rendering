//
// Created by chaoscatalyst on 01-12-2025.
//

#ifndef RAWENGINE_SCENEWINDOW_H
#define RAWENGINE_SCENEWINDOW_H
#include "EditorWindow.h"

#include "EditorContext.h"
#include <glad/gl.h>

class SceneWindow : public EditorWindow {
public:
    SceneWindow(EditorContext& pContext, int width, int height);
    ~SceneWindow();

    const char* GetName() override { return "Scene"; }
    void OnImGuiRender() override;

    // Call this each frame instead of SceneManager::RenderScene()
    void RenderToFramebuffer();

private:
    void CreateFramebuffer(int width, int height);
    void ResizeIfNeeded(int width, int height);

    EditorContext& editorContext;

    GLuint framebuffer = 0;
    GLuint colorTexture = 0;
    GLuint depthRbo = 0;

    int fbWidth;
    int fbHeight;
};



#endif //RAWENGINE_HIERARCHY_H
