#version 400 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNor;

out vec3 fNor;

uniform mat4 mvpMatrix;

void main()
{
    fNor = aNor;
    gl_Position = mvpMatrix * vec4(aPos, 1.0);
}