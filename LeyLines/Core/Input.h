//
// Created by stan on 11/17/25.
//

#ifndef RAWENGINE_INPUT_H
#define RAWENGINE_INPUT_H
#include <GLFW/glfw3.h>


class Input {
public:
    static void SetWindow(GLFWwindow* newWindow);
    static bool GetKeyDown(int key);

private:
    static GLFWwindow *window;
};


#endif //RAWENGINE_INPUT_H