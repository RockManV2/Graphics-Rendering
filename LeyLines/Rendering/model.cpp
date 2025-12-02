#include "model.h"

void Model::render() {
    for (int i = 0; i < meshes.size(); ++i) {
        meshes[i].render();
    }
}