//
// Created by chaoscatalyst on 02-12-2025.
//

#ifndef RAWENGINE_MONKEYROTATOR_H
#define RAWENGINE_MONKEYROTATOR_H
#include "Core/Component.h"


class MonkeyRotator : public Component {
public:
    const char* GetName() override { return "MonkeyRotator"; }

    void Update(float deltaTime) override;
};


#endif //RAWENGINE_MONKEYROTATOR_H