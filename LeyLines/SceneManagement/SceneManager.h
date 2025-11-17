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
    static std::unordered_map<std::string, Scene*> scenes;

    static void LoadScene(std::string name);
    static Scene* GetActiveScene();
    static void InitializeScene();
    static void UpdateScene();
    static void RenderScene();
    static void AddScene(Scene* newScene);

private:
    static Scene* activeScene;
};


#endif //RAWENGINE_SCENEMANAGER_H