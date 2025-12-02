#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <fstream>
#include <sstream>
#include <format>

#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "../LeyLines/SceneManagement/Scene.h"
#include "LeyLines/Rendering/assimpLoader.h"
#include "LeyLines/Rendering/model.h"
#include "LeyLines/Rendering/texture.h"
#include "Editor/InspectorWindow.h"
#include "Editor/SceneWindow.h"
#include "LeyLines/Core/Camera.h"
#include "LeyLines/Core/Input.h"
#include "LeyLines/Rendering/MeshRenderer.h"
#include "LeyLines/Core/Window.h"
#include "LeyLines/Editor/Editor.h"
#include "LeyLines/Editor/EditorContext.h"
#include "LeyLines/Editor/HierarchyWindow.h"
#include "LeyLines/Game/Movement.h"
#include "LeyLines/SceneManagement/SceneManager.h"

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

int main() {
    Window window(800,600, "LeyLines");
    Input::SetWindow(window.window);

    const GLuint modelVertexShader = generateShader("shaders/modelVertex.vs", GL_VERTEX_SHADER);
    const GLuint fragmentShader = generateShader("shaders/fragment.fs", GL_FRAGMENT_SHADER);
    const GLuint textureShader = generateShader("shaders/texture.fs", GL_FRAGMENT_SHADER);

    int success;
    char infoLog[512];
    const unsigned int modelShaderProgram = glCreateProgram();
    glAttachShader(modelShaderProgram, modelVertexShader);
    glAttachShader(modelShaderProgram, fragmentShader);
    glLinkProgram(modelShaderProgram);
    glGetProgramiv(modelShaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(modelShaderProgram, 512, NULL, infoLog);
        printf("Error! Making Shader Program: %s\n", infoLog);
    }
    const unsigned int textureShaderProgram = glCreateProgram();
    glAttachShader(textureShaderProgram, modelVertexShader);
    glAttachShader(textureShaderProgram, textureShader);
    glLinkProgram(textureShaderProgram);
    glGetProgramiv(textureShaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(textureShaderProgram, 512, NULL, infoLog);
        printf("Error! Making Shader Program: %s\n", infoLog);
    }

    glDeleteShader(modelVertexShader);
    glDeleteShader(fragmentShader);
    glDeleteShader(textureShader);


    glm::vec4 clearColor = glm::vec4(0.2f, 0.2f, 0.2f, 1.0f);
    glClearColor(clearColor.r,
                 clearColor.g, clearColor.b, clearColor.a);


    core::Mesh quad = core::Mesh::generateQuad();
    core::Model quadModel({quad});

    core::Model suzanne = core::AssimpLoader::loadModel("models/nonormalmonkey.obj");
    core::Texture cmgtGatoTexture("textures/CMGaTo_crop.png");
    // Scene stuff

    Scene* scene1 = new Scene("Scene1");

    GameObject* monkeyObj = new GameObject("Suzanne");
    auto* monkeyRenderer = monkeyObj->AddComponent<MeshRenderer>();
    monkeyRenderer->model = &suzanne;
    monkeyRenderer->shaderId = modelShaderProgram;
    scene1->Add(monkeyObj);

    GameObject* quadObj = new GameObject("Quad");
    auto* quadRenderer = quadObj->AddComponent<MeshRenderer>();

    quadRenderer->model = &quadModel;
    quadRenderer->shaderId = textureShaderProgram;
    quadRenderer->textureId = cmgtGatoTexture.getId();

    quadObj->GetComponent<Transform>()->Translate(glm::vec3(0,0,-2.5));
    quadObj->GetComponent<Transform>()->Scale(glm::vec3(5, 5, 1));

    scene1->Add(quadObj);

    GameObject* newObject = new GameObject("Camera");
    newObject->AddComponent<Camera>();
    newObject->AddComponent<Movement>();
    newObject->GetComponent<Transform>()->Translate(glm::vec3(0,0,10));
    scene1->Add(newObject);

    SceneManager::AddScene(scene1);
    SceneManager::LoadScene("Scene1");


    SceneManager::InitializeScene();

    double currentTime = glfwGetTime();
    double finishFrameTime = 0.0;
    float deltaTime = 0.0f;
    float rotationStrength = 100.0f;


    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

    ImGui_ImplGlfw_InitForOpenGL(window.window, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    ImGui::StyleColorsDark();

    EditorContext context;
    context.activeScene = scene1;

    Editor editor;

    editor.AddWindow(new HierarchyWindow(context));
    editor.AddWindow(new InspectorWindow(context));
    auto sceneWindow = new SceneWindow(context, 400, 250);
    editor.AddWindow(sceneWindow);


    while (!glfwWindowShouldClose(window.window)) {
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        monkeyObj->GetComponent<Transform>()->Rotate(
            glm::vec3(0.0f, 1.0f, 0.0f),
            glm::radians(rotationStrength) * deltaTime
        );

        SceneManager::UpdateScene();
        sceneWindow->RenderToFramebuffer();
        SceneManager::RenderScene();

        glBindFramebuffer(GL_FRAMEBUFFER, 0);
        glViewport(0, 0, g_width, g_height);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        editor.Render();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window.window);

        finishFrameTime = glfwGetTime();
        deltaTime = static_cast<float>(finishFrameTime - currentTime);
        currentTime = finishFrameTime;
    }


    glDeleteProgram(modelShaderProgram);

    glfwTerminate();
    return 0;
}