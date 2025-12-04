
#include "MeshRenderer.h"

#include <format>

#include "../Core/Camera.h"
#include <glm/gtc/type_ptr.hpp>

#include "Light.h"
#include "../SceneManagement/SceneManager.h"

void MeshRenderer::Start() {
    if (!shaderId)
        return;

    mvpLocation = glGetUniformLocation(shaderId, "mvpMatrix");

    SceneManager::GetActiveScene()->RegisterRenderable(this);

}

void MeshRenderer::Render() {
    if (!model || shaderId == 0)
        return;

    glUseProgram(shaderId);

    glm::mat4 mvp =
        Camera::GetActive()->GetProjectionMatrix() *
        Camera::GetActive()->GetViewMatrix() *
        transform->GetModelMatrix();

    if (mvpLocation >= 0)
        glUniformMatrix4fv(mvpLocation, 1, GL_FALSE, glm::value_ptr(mvp));

    if (textureId != 0 && textureLocation >= 0) {
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, textureId);
        glUniform1i(textureLocation, 0);
    }

    std::vector<Light*> lights = SceneManager::GetActiveScene()->GetLights();
    auto sizeUniformLocation = glGetUniformLocation(shaderId,"size");
    glUniform1i(sizeUniformLocation, lights.size());

    for (int i = 0; i < lights.size(); ++i) {
        Light* light = lights[i];

        auto positionUniformLocation = glGetUniformLocation(shaderId,std::format("lights[{}].position",i).c_str());
        auto lightPos = light->transform->GetPosition();
        glUniform3f(positionUniformLocation, lightPos.x, lightPos.y, lightPos.z);

        auto colorUniformLocation = glGetUniformLocation(shaderId,std::format("lights[{}].color",i).c_str());
        auto lightColor = light->color;
        glUniform3f(colorUniformLocation, lightColor.x, lightColor.y, lightColor.z);
    }

    model->render();

    glBindVertexArray(0);
}

