
#ifndef RAWENGINE_SCENE_H
#define RAWENGINE_SCENE_H

#include <string>
#include <vector>
#include "GameObject.h"
#include "../Rendering/IRenderable.h"

class Light;

class Scene {
public:
    Scene(std::string name);
    ~Scene();

    std::string name;
    int Id;

    void Add(GameObject*);
    void Remove(GameObject*);
    void Destroy();
    std::vector<GameObject*>& GetGameObjects() { return gameObjects; }
    std::vector<Light*>& GetLights() { return lights; }

    void Awake();
    void Start();
    void OnEnable();
    void OnDisable();
    void Update(float deltaTime);
    void Render();
    void RegisterRenderable(IRenderable*);
    void RegisterLight(Light*);
    void CheckCollisions();

private:
    std::vector<GameObject*> gameObjects;
    std::vector<IRenderable*> renderables;
    std::vector<Light*> lights;
};


#endif //RAWENGINE_SCENE_H