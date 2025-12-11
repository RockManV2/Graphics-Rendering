#version 400 core
out vec4 FragColor;
in vec3 fPos;
in vec3 fNor;
in vec2 uv;

in vec3 fWorldNor;
in vec3 fWorldPos;


out vec4 fragColor;

struct Light {
    vec3 color;
    vec3 position;
    vec3 direction;
};

uniform int size;
uniform Light lights[20];

float ambientIntensity = 0.1;
vec3 ambientLightColor = vec3(1, 1, 1);
vec3 diffuseColor = vec3(1, 1, 1);

vec3 ambient()
{
    return ambientIntensity * ambientLightColor * diffuseColor;
};

vec3 diffuse(Light light)
{
     return max(dot(normalize(fWorldNor), normalize(light.position - fPos)), 0.0) * light.color * diffuseColor;
};



void main()
{
    vec3 result = vec3(0,0,0);

    for (int i = 0; i < size; i++) {
        result += diffuse(lights[i]);
    }

    result = result + ambient();
    fragColor = vec4(result.x, result.y, result.z, 1);
}