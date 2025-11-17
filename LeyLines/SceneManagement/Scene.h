
#ifndef RAWENGINE_SCENE_H
#define RAWENGINE_SCENE_H

#include <string>
#include <vector>
#include "../Core/GameObject.h"
#include "../Core/IRenderable.h"

class Scene {
public:
    Scene(std::string name);
    ~Scene();

    std::string name;
    int Id;

    void Add(GameObject*);
    void Remove(GameObject*);
    void Destroy();

    void Awake();
    void Start();
    void OnEnable();
    void OnDisable();
    void Update();
    void Render();
    void RegisterRenderable(IRenderable*);
    void CheckCollisions();

private:
    std::vector<GameObject*> gameObjects;
    std::vector<IRenderable*> renderables;
};


#endif //RAWENGINE_SCENE_H