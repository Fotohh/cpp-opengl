#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

class Window {
public:
    Window(const int width, const int height, const char *title): m_width_(width), m_height_(height),
                                                                          m_title_(title), m_is_running_(false) {
    }

    bool init();

    bool window_should_close() const;

    static void process_input(GLFWwindow* window);

    bool is_running() const;

    [[nodiscard]] int get_width() const;

    [[nodiscard]] int get_height() const;

    [[nodiscard]] GLFWwindow *get_window() const;

    [[nodiscard]] const char* get_title() const;

private:
    int m_width_;
    int m_height_;
    const char* m_title_;
    GLFWwindow *m_window_{};
    bool m_is_running_;
};

#endif
