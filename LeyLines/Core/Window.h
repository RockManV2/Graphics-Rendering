
#ifndef RAWENGINE_WINDOW_H
#define RAWENGINE_WINDOW_H

#include <GLFW/glfw3.h>
#include <functional>
#include <string>

class Window {
public:
    GLFWwindow* window;
    int width, height;

    Window(int width, int height, std::string name);
    ~Window();

    void SetFrameBufferCallback(std::function<void(GLFWwindow*, int, int)> callback);
};


#endif //RAWENGINE_WINDOW_H