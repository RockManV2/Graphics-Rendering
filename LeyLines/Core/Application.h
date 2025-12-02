
#ifndef RAWENGINE_APPLICATION_H
#define RAWENGINE_APPLICATION_H

#include "Editor/Editor.h"
#include "Editor/EditorContext.h"
#include "Editor/HierarchyWindow.h"
#include "Editor/InspectorWindow.h"
#include "Editor/SceneWindow.h"
#include "Editor/ProjectWindow.h"


class RenderWindow;

class Application {
public:
    Application();
    ~Application();

    void Run();
    void Temp();

private:
    void Init();
    void Update(float deltaTime);
    void Render();
    void ShutDown();

private:
    RenderWindow* renderWindow  = nullptr;

    Editor* editor = nullptr;
    EditorContext editorContext;

    HierarchyWindow* hierarchyWindow = nullptr;
    SceneWindow* sceneWindow  = nullptr;
    InspectorWindow* inspectorWindow  = nullptr;
    ProjectWindow* projectWindow = nullptr;

    double lastFrameTime = 0.0;
};

#endif //RAWENGINE_APPLICATION_H
