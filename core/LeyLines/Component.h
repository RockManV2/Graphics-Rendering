
#ifndef RAWENGINE_COMPONENT_H
#define RAWENGINE_COMPONENT_H


class GameObject;

class Component {

public:
    GameObject* gameObject;
    // Transform transform

    virtual void Awake();
    virtual void Start();
    virtual void OnEnable();
    virtual void OnDisable();
    virtual void Update();
    virtual void Render();
};


#endif //RAWENGINE_COMPONENT_H