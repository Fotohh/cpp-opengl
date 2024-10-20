#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


void framebuffer_size_callback(GLFWwindow *window, int width, int height);

void process_input(GLFWwindow *window);

class window {
public:
    window(const int width, const int height, const char *title): m_width_(width), m_height_(height),
                                                                          m_title_(title) {

    }

    bool init();

    [[nodiscard]] int get_width() const;

    [[nodiscard]] int get_height() const;

    [[nodiscard]] GLFWwindow *get_window() const;

    [[nodiscard]] const char* get_title() const;

    static void framebuffer_size_callback(GLFWwindow *window, const int width, const int height) {
        glViewport(0, 0, width, height);
    }

    static void process_input(GLFWwindow *window) {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);
    }

private:
    uint8_t m_width_;
    uint8_t m_height_;
    const char* m_title_;
    GLFWwindow *m_window_{};
};

#endif
