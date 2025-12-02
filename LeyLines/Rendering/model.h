#pragma once

#include <vector>
#include "mesh.h"
#include <glm/ext/matrix_float4x4.hpp>

namespace core {
    class Model {
    private:
        std::vector<core::Mesh> meshes;
    public:
        Model(std::vector<Mesh> meshes) : meshes(meshes) {}

        void render();
    };
}