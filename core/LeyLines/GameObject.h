
#ifndef RAWENGINE_GAMEOBJECT_H
#define RAWENGINE_GAMEOBJECT_H

#include <string>
#include <vector>
#include "Component.h"

class GameObject{
    std::string name;
    std::vector<Component*> components; // doesn't work! (slicing) - must be pointers - but then who manages lifetime?

public:
    GameObject(std::string name);

    GameObject Find(std::string);
    GameObject Instantiate();
    std::vector<GameObject> FindObjectsWithTag(std::string);

    void AddComponent(Component* newComponent);
    // public T GetComponent<T>() where T : Component

    virtual void Awake();
    virtual void Start();
    virtual void OnEnable();
    virtual void OnDisable();
    virtual void Update();
    virtual void Render();
};


#endif //RAWENGINE_GAMEOBJECT_H