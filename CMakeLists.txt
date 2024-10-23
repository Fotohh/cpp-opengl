
cmake_minimum_required (VERSION 3.8)


project ("cpp-opengl")

add_executable (cpp-opengl "src/cpp-opengl.cpp"
        src/window/Window.h
        src/window/Window.cpp
        src/shader/Shader.cpp
        src/shader/Shader.h
        src/render/Renderer.h
        src/render/Renderer.cpp
        src/obj/Model.h
        src/obj/Model.cpp
        )

find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

target_link_libraries(cpp-opengl PRIVATE glfw)
target_link_libraries(cpp-opengl PRIVATE glm::glm)
target_link_libraries(cpp-opengl PRIVATE glad::glad)


