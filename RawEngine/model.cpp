#include "../RawEngine/model.h"
#include "../RawEngine/mesh.h"
#include <glm/gtc/matrix_transform.hpp>

namespace core {
    void Model::render() {
        for (int i = 0; i < meshes.size(); ++i) {
            meshes[i].render();
        }
    }
}