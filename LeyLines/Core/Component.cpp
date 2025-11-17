
#include "Transform.h"

void Component::SetOwner(GameObject* owner) {
    gameObject = owner;
}

void Component::Awake() {}
void Component::Start() {}
void Component::OnEnable() {}
void Component::OnDisable() {}
void Component::Update() {}
