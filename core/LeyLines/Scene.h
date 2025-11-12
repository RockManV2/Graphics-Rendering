
#ifndef RAWENGINE_SCENE_H
#define RAWENGINE_SCENE_H

#include <string>
#include <vector>
#include "GameObject.h"

class Scene {
public:
    Scene(std::string name);

    std::string name;
    int Id;
    std::vector<GameObject*> gameObjects;

    void Add(GameObject*);
    void Remove(GameObject*);
    void Destroy();

    void Awake();
    void Start();
    void OnEnable();
    void OnDisable();
    void Update();
    void Render();
    void CheckCollisions();
};


#endif //RAWENGINE_SCENE_H