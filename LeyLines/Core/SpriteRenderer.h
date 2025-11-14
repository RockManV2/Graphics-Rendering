//
// Created by stan on 11/12/25.
//

#ifndef RAWENGINE_SPRITERENDERER_H
#define RAWENGINE_SPRITERENDERER_H

#include <glm/vec4.hpp>
#include "Component.h"
#include "Shader.h"
#include "../../RawEngine/texture.h"


class SpriteRenderer : public Component {
public:
    core::Texture texture;
    glm::vec4 color;

    SpriteRenderer(Shader &shader);
    ~SpriteRenderer();

    void Awake() override;
    void Render() override;


private:
    Shader shader;
};


#endif //RAWENGINE_SPRITERENDERER_H