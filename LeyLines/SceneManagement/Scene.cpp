
#include "Scene.h"

Scene::Scene(std::string pName) {
    name = pName;
}

Scene::~Scene() {
    for (GameObject* go : gameObjects)
        delete go;
}

void Scene::Add(GameObject* newObject) {
    gameObjects.push_back(newObject);
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

void Scene::Update(float deltaTime) {
    for (auto & gameObject : gameObjects) {
        gameObject->Update(deltaTime);
    }
}

void Scene::Render() {
    for (auto & renderable : renderables) {
        renderable->Render();
    }
}

void Scene::RegisterRenderable(IRenderable* renderable) {
    renderables.push_back(renderable);
}

