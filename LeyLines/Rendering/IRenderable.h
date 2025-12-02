
#ifndef RAWENGINE_IRENDERABLE_H
#define RAWENGINE_IRENDERABLE_H


class IRenderable {
public:
    virtual ~IRenderable() = default;
    virtual void Render() = 0;
};


#endif //RAWENGINE_IRENDERABLE_H