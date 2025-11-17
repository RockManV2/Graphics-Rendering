
#include "MeshRenderer.h"
#include "Camera.h"
#include <glm/gtc/type_ptr.hpp>

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
        model->getModelMatrix();

    if (mvpLocation >= 0)
        glUniformMatrix4fv(mvpLocation, 1, GL_FALSE, glm::value_ptr(mvp));

    if (textureId != 0 && textureLocation >= 0) {
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, textureId);
        glUniform1i(textureLocation, 0);
    }

    model->render();

    glBindVertexArray(0);
}

