#pragma once

#include <vector>
#include "mesh.h"


class Model {
private:
    std::vector<Mesh> meshes;
public:
    Model(std::vector<Mesh> meshes) : meshes(meshes) {}

    void render();
};
