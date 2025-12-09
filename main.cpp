
#include "Core/Application.h"

#

#include "imgui_impl_glfw.h"

#include "SceneManagement/SceneManager.h"
#include "Rendering/assimpLoader.h"
#include "Rendering/mesh.h"
#include "Rendering/model.h"
#include "Rendering/texture.h"
#include <glad/glad.h>

#include <GLFW/glfw3.h>
#include <glm/gtc/type_ptr.hpp>
#include <fstream>
#include <sstream>
#include <format>

#include "SceneManagement/Scene.h"
#include "Core/Camera.h"
#include "Game/MonkeyRotator.h"
#include "Rendering/MeshRenderer.h"
#include "Game/Movement.h"
#include "Rendering/Light.h"

int g_width = 800;
int g_height = 600;

std::string readFileToString(const std::string &filePath) {
    std::ifstream fileStream(filePath, std::ios::in);
    if (!fileStream.is_open()) {
        printf("Could not open file: %s\n", filePath.c_str());
        return "";
    }
    std::stringstream buffer;
    buffer << fileStream.rdbuf();
    return buffer.str();
}

GLuint generateShader(const std::string &shaderPath, GLuint shaderType) {
    printf("Loading shader: %s\n", shaderPath.c_str());
    const std::string shaderText = readFileToString(shaderPath);
    const GLuint shader = glCreateShader(shaderType);
    const char *s_str = shaderText.c_str();
    glShaderSource(shader, 1, &s_str, nullptr);
    glCompileShader(shader);
    GLint success = 0;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        printf("Error! Shader issue [%s]: %s\n", shaderPath.c_str(), infoLog);
    }
    return shader;
}

void Temp() {
    // Refactor to Shader
    const GLuint modelVertexShader = generateShader("shaders/modelVertex.vs", GL_VERTEX_SHADER);
    const GLuint fragmentShader = generateShader("shaders/fragment.fs", GL_FRAGMENT_SHADER);
    const GLuint textureShader = generateShader("shaders/texture.fs", GL_FRAGMENT_SHADER);

    // Model shader program
    GLuint modelShaderProgram = glCreateProgram();
    glAttachShader(modelShaderProgram, modelVertexShader);
    glAttachShader(modelShaderProgram, fragmentShader);
    glLinkProgram(modelShaderProgram);

    // Texture shader program
    GLuint textureShaderProgram = glCreateProgram();
    glAttachShader(textureShaderProgram, modelVertexShader);
    glAttachShader(textureShaderProgram, textureShader);
    glLinkProgram(textureShaderProgram);

    // Shader objects can be deleted
    glDeleteShader(modelVertexShader);
    glDeleteShader(fragmentShader);
    glDeleteShader(textureShader);




    // Refactor to SceneManager

    Mesh* quad = new Mesh(Mesh::generateQuad());
    Model* quadModel = new Model({*quad});
    Model* suzanne = new Model(AssimpLoader::loadModel("models/nonormalmonkey.obj"));
    Texture cmgtGatoTexture ("textures/CMGaTo_crop.png");


    Scene* scene1 = new Scene("Scene1");

    // Suzanne object
    GameObject* monkeyObj = new GameObject("Suzanne");
    auto* monkeyRenderer = monkeyObj->AddComponent<MeshRenderer>();
    monkeyObj->AddComponent<MonkeyRotator>();
    monkeyRenderer->model = suzanne;
    monkeyRenderer->shaderId = modelShaderProgram;
    scene1->Add(monkeyObj);

    // Quad object
    GameObject* quadObj = new GameObject("Quad");
    auto* quadRenderer = quadObj->AddComponent<MeshRenderer>();
    quadRenderer->model = quadModel;
    quadRenderer->shaderId = textureShaderProgram;
    quadRenderer->textureId = cmgtGatoTexture.getId();
    quadObj->GetComponent<Transform>()->Translate(glm::vec3(0,0,-2.5));
    quadObj->GetComponent<Transform>()->Scale(glm::vec3(5, 5, 1));
    scene1->Add(quadObj);

    // Camera
    GameObject* cameraObj = new GameObject("Camera");
    cameraObj->AddComponent<Camera>();
    cameraObj->AddComponent<Movement>();
    cameraObj->GetComponent<Transform>()->Translate(glm::vec3(0,0,10));
    scene1->Add(cameraObj);

    GameObject* light1 = new GameObject("Lights");
    light1->AddComponent<Light>()->color = glm::vec4( 1,0, 0,1);
    light1->transform->Translate(glm::vec3(0,0,5));
    scene1->Add(light1);

    GameObject* light2 = new GameObject("Lights");
    light2->AddComponent<Light>()->color = glm::vec4(0,1,0,1);
    light2->transform->Translate(glm::vec3(0,0,5));
    scene1->Add(light2);

    // Add to SceneManager
    SceneManager::AddScene(scene1);
    SceneManager::LoadScene("Scene1");
    SceneManager::InitializeScene();
}

int main() {
    Application* application = new Application();

    Temp();

    application->Run();

    return 0;
}