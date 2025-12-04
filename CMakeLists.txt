cmake_minimum_required(VERSION 3.29)
project(RawEngine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
        imgui
        imgui/backends
        RawEngine
        LeyLines
)

set(IMGUI_SOURCES
        imgui/imgui.cpp
        imgui/imgui_draw.cpp
        imgui/imgui_demo.cpp
        imgui/imgui_tables.cpp
        imgui/imgui_widgets.cpp
        imgui/backends/imgui_impl_glfw.cpp
        imgui/backends/imgui_impl_opengl3.cpp
)

set(ENGINE_SOURCES
        LeyLines/Rendering/texture.cpp
        LeyLines/Rendering/texture.h
        LeyLines/Rendering/assimpLoader.cpp
        LeyLines/Rendering/assimpLoader.h
        LeyLines/Rendering/mesh.cpp
        LeyLines/Rendering/mesh.h
        LeyLines/Rendering/vertex.h
        LeyLines/Rendering/model.cpp
        LeyLines/Rendering/model.h
        LeyLines/SceneManagement/GameObject.cpp
        LeyLines/SceneManagement/GameObject.h
        LeyLines/SceneManagement/Scene.cpp
        LeyLines/SceneManagement/Scene.h
        LeyLines/Core/Component.cpp
        LeyLines/Core/Component.h
        LeyLines/Core/Transform.cpp
        LeyLines/Core/Transform.h
        LeyLines/Rendering/Shader.cpp
        LeyLines/Rendering/Shader.h
        LeyLines/Core/Camera.cpp
        LeyLines/Core/Camera.h
        LeyLines/SceneManagement/SceneManager.cpp
        LeyLines/SceneManagement/SceneManager.h
        LeyLines/Game/Movement.cpp
        LeyLines/Game/Movement.h
        LeyLines/Rendering/IRenderable.h
        LeyLines/Rendering/MeshRenderer.cpp
        LeyLines/Rendering/MeshRenderer.h
        LeyLines/Core/Input.cpp
        LeyLines/Core/Input.h
        LeyLines/Core/RenderWindow.cpp
        LeyLines/Core/RenderWindow.h
        LeyLines/Editor/EditorWindow.h
        LeyLines/Editor/HierarchyWindow.cpp
        LeyLines/Editor/HierarchyWindow.h
        LeyLines/Editor/Editor.cpp
        LeyLines/Editor/Editor.h
        LeyLines/Editor/EditorContext.h
        LeyLines/Editor/SceneWindow.cpp
        LeyLines/Editor/SceneWindow.h
        LeyLines/Editor/InspectorWindow.cpp
        LeyLines/Editor/InspectorWindow.h
        LeyLines/Core/Application.cpp
        LeyLines/Core/Application.h
        LeyLines/Editor/ProjectWindow.cpp
        LeyLines/Editor/ProjectWindow.h
        LeyLines/Game/MonkeyRotator.cpp
        LeyLines/Game/MonkeyRotator.h
        LeyLines/Rendering/Light.h
)

add_executable(RawEngine main.cpp ${IMGUI_SOURCES} ${ENGINE_SOURCES})

add_custom_command(
        TARGET RawEngine PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/shaders/
        ${CMAKE_CURRENT_BINARY_DIR}/shaders/
)

add_custom_command(
        TARGET RawEngine PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/models/
        ${CMAKE_CURRENT_BINARY_DIR}/models/
)

add_custom_command(
        TARGET RawEngine PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/textures/
        ${CMAKE_CURRENT_BINARY_DIR}/textures/
)

add_custom_target(copy_shaders ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/shaders
        ${CMAKE_CURRENT_BINARY_DIR}/shaders
)

add_dependencies(RawEngine copy_shaders)

find_package(glad CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(assimp CONFIG REQUIRED)
find_package(Stb REQUIRED)
find_package(X11 REQUIRED)

target_link_libraries(RawEngine PRIVATE
        glad::glad
        glfw
        glm::glm
        assimp::assimp
        ${Stb_INCLUDE_DIR}
        ${X11_LIBRARIES}
        Xrandr
        Xi
        Xxf86vm
        Xcursor
        pthread
        dl
)
