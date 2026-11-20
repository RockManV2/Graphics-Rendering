#pragma once

#include <glad/gl.h>
#include <string>

class Texture {
private:
    GLuint id;

public:
    Texture(const std::string& path);

    GLuint getId();
};

