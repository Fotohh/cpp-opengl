#include <iostream>
#include "window/Window.h"
#include "shader/Shader.h"

int main() {
    window win(640, 480, "Hello World");

    if (!win.init()) {
        std::cout << "Failed to init window!" << std::endl;
        return -1;
    }

    char *vert_path = "G:/Zinha/coding/cpp/cpp-opengl/shaders/vertex.vsh";
    char *frag_path = "G:/Zinha/coding/cpp/cpp-opengl/shaders/fragment.fsh";

    shader shader(vert_path, frag_path);
    shader.init();

    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f
    };

    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);

    while (!win.window_should_close()) {
        window::process_input(win.get_window());


        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shader.get_shader_program());
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(win.get_window());
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shader.get_shader_program());

    glfwTerminate();

    return 0;
}
