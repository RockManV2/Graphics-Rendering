
#ifndef RAWENGINE_MOUSEMOVEMENT_H
#define RAWENGINE_MOUSEMOVEMENT_H
#include <GLFW/glfw3.h>

#include "../Core/Component.h"

class Movement : public Component {

public:
    void Update() override;
};


#endif //RAWENGINE_MOUSEMOVEMENT_H