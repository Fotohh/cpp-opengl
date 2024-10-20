
cmake_minimum_required (VERSION 3.8)


project ("cpp-opengl")

add_executable (cpp-opengl "src/cpp-opengl.cpp"
        src/Window.h
        src/Window.cpp)

find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

target_link_libraries(cpp-opengl PRIVATE glfw)
target_link_libraries(cpp-opengl PRIVATE glm::glm)
target_link_libraries(cpp-opengl PRIVATE glad::glad)


