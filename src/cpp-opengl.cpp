#include <iostream>

#include "render/Renderer.h"
#include "window/Window.h"
#include "shader/ShaderManager.h"

int main() {
    window win(640, 480, "Hello World");

    if (!win.init()) {
        std::cout << "Failed to init window!" << std::endl;
        return -1;
    }

    char *vert_path = "G:/Zinha/coding/cpp/cpp-opengl/shaders/vertex.vsh";
    char *frag_path = "G:/Zinha/coding/cpp/cpp-opengl/shaders/fragment.fsh";
    char *frag2_path = "G:/Zinha/coding/cpp/cpp-opengl/shaders/fragment2.fsh";

    shader shader(vert_path);
    if (!shader.init()) {
        std::cout << "Failed to init shaders!" << std::endl;
        return -1;
    }

    auto *manager = new model_manager();

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
    model model_2(vert_2, 3);

    renderer renderer(manager);
    renderer.add_model(model_1);
    renderer.add_model(model_2);

    const unsigned int orange = shader.create_shader_program(frag_path);
    const unsigned int yellow = shader.create_shader_program(frag2_path);

    renderer.init();
    while (!win.window_should_close()) {
        window::process_input(win.get_window());

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(orange);


        glUseProgram(yellow);

        //renderer.update();
        /*
        *glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // now when we draw the triangle we first use the vertex and orange fragment shader from the first program
        glUseProgram(shaderProgramOrange);
        // draw the first triangle using the data from our first VAO
        glBindVertexArray(VAOs[0]);
        glDrawArrays(GL_TRIANGLES, 0, 3);	// this call should output an orange triangle
        // then we draw the second triangle using the data from the second VAO
        // when we draw the second triangle we want to use a different shader program so we switch to the shader program with our yellow fragment shader.
        glUseProgram(shaderProgramYellow);
        glBindVertexArray(VAOs[1]);
        glDrawArrays(GL_TRIANGLES, 0, 3);	// this call should output a yellow triangle
         */

        glfwSwapBuffers(win.get_window());
        glfwPollEvents();
    }

    renderer.unload();
    shader.unload();

    delete manager;
    manager = nullptr;

    glfwTerminate();

    return 0;
}
