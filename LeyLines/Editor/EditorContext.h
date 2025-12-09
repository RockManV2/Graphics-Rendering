//
// Created by chaoscatalyst on 01-12-2025.
//

#ifndef RAWENGINE_EDITORCONTEXT_H
#define RAWENGINE_EDITORCONTEXT_H
#include <glm/fwd.hpp>
#include "../SceneManagement/Scene.h"

struct EditorContext
{
    GameObject* selectedEntity = nullptr;
    Scene* activeScene = nullptr;
};



#endif //RAWENGINEwin_EDITORCONTEXT_H