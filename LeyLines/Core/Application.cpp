
#include "Application.h"

#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "Input.h"
#include "SceneManagement/SceneManager.h"
#include "RenderWindow.h"

#include <GLFW/glfw3.h>

Application::Application() {
    Init();
}

Application::~Application() {
    ShutDown();
}

void Application::Init() {
    renderWindow = new RenderWindow("LeyLines");
    Input::SetWindow(renderWindow->glWindow);

    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    ImGui_ImplGlfw_InitForOpenGL(renderWindow->glWindow, true);
    ImGui_ImplOpenGL3_Init("#version 330");
    ImGui::StyleColorsDark();

    editor = new Editor();

    sceneWindow = new SceneWindow(editorContext, 0, 0);
    hierarchyWindow = new HierarchyWindow(editorContext);
    inspectorWindow = new InspectorWindow(editorContext);
    projectWindow = new ProjectWindow(editorContext);

    editor->AddWindow(sceneWindow);
    editor->AddWindow(hierarchyWindow);
    editor->AddWindow(inspectorWindow);
    editor->AddWindow(projectWindow);

    lastFrameTime = glfwGetTime();
}

void Application::Run() {
    editorContext.activeScene = SceneManager::GetActiveScene();
    while (!glfwWindowShouldClose(renderWindow->glWindow)) {
        double currentTime = glfwGetTime();
        float deltaTime = (float) (currentTime - lastFrameTime);
        lastFrameTime = currentTime;

        glfwPollEvents();
        Update(deltaTime);
        Render();
        glfwSwapBuffers(renderWindow->glWindow);
    }
}

void Application::Update(float deltaTime) {
    SceneManager::UpdateScene(deltaTime);
}

void Application::Render() {
    sceneWindow->RenderToFramebuffer();

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    SceneManager::RenderScene();
    editor->Render();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void Application::ShutDown() {
    if (editor) delete editor;
    if (sceneWindow) delete sceneWindow;
    if (hierarchyWindow) delete hierarchyWindow;
    if (inspectorWindow) delete inspectorWindow;
    if (projectWindow) delete projectWindow;

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    delete renderWindow;
}