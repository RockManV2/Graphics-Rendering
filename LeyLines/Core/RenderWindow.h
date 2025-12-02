
#ifndef RAWENGINE_WINDOW_H
#define RAWENGINE_WINDOW_H

#include <GLFW/glfw3.h>
#include <functional>
#include <string>

class RenderWindow {
public:
    GLFWwindow* glWindow;
    int width, height;

    RenderWindow(std::string name);
    ~RenderWindow();

    void SetFrameBufferCallback(std::function<void(GLFWwindow*, int, int)> callback);
};


#endif //RAWENGINE_WINDOW_H