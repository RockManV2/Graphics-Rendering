//
// Created by chaoscatalyst on 01-12-2025.
//

#ifndef RAWENGINE_EDITORCONTEXT_H
#define RAWENGINE_EDITORCONTEXT_H
#include <glm/fwd.hpp>
#include "../SceneManagement/Scene.h"

struct EditorContext
{
    glm::uint32_t selectedEntity = 0;
    Scene* activeScene = nullptr;
};



#endif //RAWENGINE_EDITORCONTEXT_H