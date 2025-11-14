
#ifndef RAWENGINE_GAMEOBJECT_H
#define RAWENGINE_GAMEOBJECT_H

#include <string>
#include <vector>
#include <utility>
#include "Component.h"
#include "Transform.h"

class GameObject{
private:
    std::vector<Component*> components;

public:
    std::string name;
    Transform* transform;

    GameObject(std::string name);
    ~GameObject();

    GameObject Find(std::string);
    GameObject Instantiate();
    std::vector<GameObject> FindObjectsWithTag(std::string);

    template <typename T, typename... Args>
    T* AddComponent(Args&&... args) {
        T* newComponent = new T(std::forward<Args>(args)...);

        newComponent->SetOwner(this);
        newComponent->transform = GetComponent<Transform>();

        components.push_back(newComponent);
        return newComponent;
    }

    template <typename T>
    T* GetComponent() {
        static_assert(std::is_base_of<Component, T>::value);

        for (Component* c : components) {
            if (T* casted = dynamic_cast<T*>(c)) {
                return casted;
            }
        }
        return nullptr;
    }

    virtual void Awake();
    virtual void Start();
    virtual void OnEnable();
    virtual void OnDisable();
    virtual void Update();
    virtual void Render();
};


#endif //RAWENGINE_GAMEOBJECT_H