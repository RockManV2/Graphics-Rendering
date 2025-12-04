//
// Created by stano on 11/14/25.
//

#ifndef RAWENGINE_SCENEMANAGER_H
#define RAWENGINE_SCENEMANAGER_H
#include <string>
#include <unordered_map>

#include "Scene.h"


class SceneManager {
public:
    SceneManager() = default;
    ~SceneManager();

    static void LoadScene(std::string name);
    static Scene* GetActiveScene();
    static void InitializeScene();
    static void UpdateScene(float deltaTime);
    static void RenderScene();
    static void AddScene(Scene* newScene);

private:
    static Scene* activeScene;
    static std::unordered_map<std::string, Scene*> scenes;
};


#endif //RAWENGINE_SCENEMANAGER_H