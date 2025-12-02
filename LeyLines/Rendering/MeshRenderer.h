
#ifndef RAWENGINE_MESHRENDERER_H
#define RAWENGINE_MESHRENDERER_H

#include "model.h"
#include "../Core/Component.h"
#include "IRenderable.h"

class MeshRenderer : public Component, public IRenderable {
public:
    Model* model = nullptr;
    GLuint shaderId = 0;
    GLuint textureId = 0;

    GLuint mvpLocation = -1;
    GLuint textureLocation = -1;

    void Start() override;
    void Render() override;
};


#endif //RAWENGINE_MESHRENDERER_H