#include <iostream>

#include "render/Renderer.h"
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

    const std::vector<char *> &paths{frag_path};

    shader shader(vert_path, paths);
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

    manager->add_model(model_1);
    manager->add_model(model_2);

    renderer renderer(manager);

    renderer.init();
    while (!win.window_should_close()) {
        window::process_input(win.get_window());

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shader.get_shader_programs()[0]);

        renderer.update();

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
