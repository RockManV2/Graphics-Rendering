//
// Created by chaoscatalyst on 01-12-2025.
//

#include "SceneWindow.h"

#include "imgui.h"
#include "../SceneManagement/SceneManager.h"

SceneWindow::SceneWindow(EditorContext& pContext, int width, int height)
    : editorContext(pContext), fbWidth(width), fbHeight(height)
{
    CreateFramebuffer(width, height);
}

SceneWindow::~SceneWindow()
{
    if (colorTexture) glDeleteTextures(1, &colorTexture);
    if (depthRbo) glDeleteRenderbuffers(1, &depthRbo);
    if (framebuffer) glDeleteFramebuffers(1, &framebuffer);
}

void SceneWindow::CreateFramebuffer(int width, int height)
{
    if (framebuffer) {
        glDeleteTextures(1, &colorTexture);
        glDeleteRenderbuffers(1, &depthRbo);
        glDeleteFramebuffers(1, &framebuffer);
    }

    glGenFramebuffers(1, &framebuffer);
    glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);

    glGenTextures(1, &colorTexture);
    glBindTexture(GL_TEXTURE_2D, colorTexture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, nullptr);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,
                           GL_TEXTURE_2D, colorTexture, 0);

    glGenRenderbuffers(1, &depthRbo);
    glBindRenderbuffer(GL_RENDERBUFFER, depthRbo);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT,
                              GL_RENDERBUFFER, depthRbo);

    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
        printf("SceneWindow: Framebuffer is not complete!\n");

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void SceneWindow::ResizeIfNeeded(int width, int height)
{
    if (width <= 0 || height <= 0) return;
    if (width == fbWidth && height == fbHeight) return;

    fbWidth = width;
    fbHeight = height;
    CreateFramebuffer(fbWidth, fbHeight);
}

void SceneWindow::RenderToFramebuffer()
{
    glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
    glViewport(0, 0, fbWidth, fbHeight);
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Your existing scene render
    SceneManager::RenderScene();

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void SceneWindow::OnImGuiRender()
{
    ImGui::Begin("Scene");

    ImVec2 size = ImGui::GetContentRegionAvail();
    int w = (int)size.x;
    int h = (int)size.y;

    ResizeIfNeeded(w, h);

    ImGui::Image(
        (void*)(intptr_t)colorTexture,
        ImVec2((float)fbWidth, (float)fbHeight),
        ImVec2(0, 1),
        ImVec2(1, 0)
    );

    ImGui::End();
}
