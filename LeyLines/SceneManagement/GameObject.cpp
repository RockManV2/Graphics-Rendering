
#include <vector>

#include "GameObject.h"

GameObject::GameObject(std::string pName) {
    name = pName;
    transform = AddComponent<Transform>();
    transform->transform = transform;
}

GameObject::~GameObject() {
    for (Component* c : components)
        delete c;
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

void GameObject::Update(float deltaTime) {
    for (auto & component : components) {
        component->Update(deltaTime);
    }
}
