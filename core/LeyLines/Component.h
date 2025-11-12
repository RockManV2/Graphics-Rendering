
#ifndef RAWENGINE_COMPONENT_H
#define RAWENGINE_COMPONENT_H


class Transform;
class GameObject;

class Component {

public:
    GameObject* gameObject;
    Transform* transform;

    void SetOwner(GameObject* gameObject);

    virtual void Awake();
    virtual void Start();
    virtual void OnEnable();
    virtual void OnDisable();
    virtual void Update();
    virtual void Render();
};


#endif //RAWENGINE_COMPONENT_H