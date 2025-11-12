
#include "GameObject.h"


#include "Scene.h"

GameObject::GameObject(std::string pName) {
    name = pName;
}

void GameObject::AddComponent(Component *newComponent) {
    components.insert(components.end(), newComponent);
}


void GameObject::Awake() {
    for (auto & component : components) {
        component->Awake();
    }
}

void GameObject::Start() {
    for (auto & component : components) {
        component->Start();
    }
}

void GameObject::OnEnable() {
    for (auto & component : components) {
        component->OnEnable();
    }
}

void GameObject::OnDisable() {
    for (auto & component : components) {
        component->OnDisable();
    }
}

void GameObject::Update() {
    for (auto & component : components) {
        component->Update();
    }
}

void GameObject::Render() {
    for (auto & component : components) {
        component->Render();
    }
}
