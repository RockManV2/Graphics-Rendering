
#include "Scene.h"

Scene::Scene(std::string pName) {
    name = pName;
}

void Scene::Add(GameObject* newObject) {
    gameObjects.insert(gameObjects.end(), newObject);
}

void Scene::Remove(GameObject* object) {
    for (int i = 0; i < gameObjects.size(); i++) {
        if (gameObjects[i] == object) {
            gameObjects.erase(gameObjects.begin() + i);
        }
    }
}

void Scene::Awake() {
    for (auto & gameObject : gameObjects) {
        gameObject->Awake();
    }
}

void Scene::Start() {
    for (auto & gameObject : gameObjects) {
        gameObject->Start();
    }
}

void Scene::OnEnable() {
    for (auto & gameObject : gameObjects) {
        gameObject->OnEnable();
    }
}

void Scene::OnDisable() {
    for (auto & gameObject : gameObjects) {
        gameObject->OnDisable();
    }
}

void Scene::Update() {
    for (auto & gameObject : gameObjects) {
        gameObject->Update();
    }
}

void Scene::Render() {
    for (auto & gameObject : gameObjects) {
        gameObject->Render();
    }
}
