#pragma once

#include <glad/glad.h>
#include <string>

class Texture {
private:
    GLuint id;

public:
    Texture(const std::string& path);

    GLuint getId();
};

