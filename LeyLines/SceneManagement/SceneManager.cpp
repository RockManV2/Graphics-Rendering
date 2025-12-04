//
// Created by stano on 11/14/25.
//

#include "SceneManager.h"

std::unordered_map<std::string, Scene*> SceneManager::scenes{};
Scene* SceneManager::activeScene = nullptr;

SceneManager::~SceneManager() {
    for (auto it = scenes.begin(); it != scenes.end(); it++) {
        delete it->second;
    }
}

void SceneManager::LoadScene(std::string name) {
    if (scenes[name] != nullptr) {
        activeScene = scenes[name];
    }
}

Scene* SceneManager::GetActiveScene() {
    return activeScene;
}

void SceneManager::AddScene(Scene* newScene) {
    scenes[newScene->name] = newScene;
}

void SceneManager::InitializeScene() {
    activeScene->Awake();
    activeScene->Start();
    activeScene->OnEnable();
}

void SceneManager::UpdateScene(float deltaTime) {
    activeScene->Update(deltaTime);
}

void SceneManager::RenderScene() {
    activeScene->Render();
}