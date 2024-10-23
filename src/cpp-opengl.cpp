﻿#include <iostream>

#include "render/Renderer.h"
#include "window/Window.h"
#include "shader/Shader.h"

int main() {

    window win(640, 480, "Hello World");

    if (!win.init()) {
        std::cout << "Failed to init window!" << std::endl;
        return -1;
    }

    const char *vert_path = "G:/Zinha/coding/cpp/cpp-opengl/shaders/vertex.vsh";
    char *frag_path = "G:/Zinha/coding/cpp/cpp-opengl/shaders/fragment.fsh";
    char *frag2_path = "G:/Zinha/coding/cpp/cpp-opengl/shaders/fragment2.fsh";

    auto *shade_manager = new shader();

    if (!shade_manager->init_vertex_shader(vert_path)) {
        std::cout << "Failed to init vertex shader!" << std::endl;
        return -1;
    }

    const unsigned int orange = shade_manager->create_shader_program(frag_path);
    const unsigned int yellow = shade_manager->create_shader_program(frag2_path);

    auto *render = new renderer();

    static float vert_1[] = {
        -0.9f, -0.5f, 0.0f,
        -0.0f, -0.5f, 0.0f,
        -0.45f, 0.5f, 0.0f,
    };
    static float vert_2[] = {
        0.0f, -0.5f, 0.0f,
        0.9f, -0.5f, 0.0f,
        0.45f, 0.5f, 0.0f
    };

    model model_1(vert_1, 3);
    //model model_2(vert_2, 3);

    GLenum error = glGetError();
    error = glGetError();
    if (error != GL_NO_ERROR) {
        std::cout << "OpenGL Error before render->add_model(model_1): " << error << std::endl;
    }

    render->add_model(model_1); //error orginates from here:
    //render->add_model(model_2);

    error = glGetError();
    if (error != GL_NO_ERROR) {
        std::cout << "OpenGL Error after render->add_model(model_1): " << error << std::endl;
    }

    render->init();

    while (!win.window_should_close()) {
        window::process_input(win.get_window());

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(orange);

        render->render_model(model_1);

        //glUseProgram(yellow);
        // render->render_model(model_2);

        glfwSwapBuffers(win.get_window());
        glfwPollEvents();
    }

    shade_manager->cleanup();

    glDeleteProgram(orange);
    glDeleteProgram(yellow);

    render->unload();

    delete render;
    delete shade_manager;

    glfwTerminate();

    return 0;
}
