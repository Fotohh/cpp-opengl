
#include "Window.h"

int Window::get_width() const {
    return m_width_;
}

int Window::get_height() const {
    return m_height_;
}

GLFWwindow* Window::get_window() const {
    return m_window_;
}

const char* Window::get_title() const {
    return m_title_;
}

bool Window::is_running() const {
    return m_is_running_;
}

void error_callback(const int error, const char* description) {
    std::cerr << "GLFW Error (" << error << "): " << description << std::endl;
}

void framebuffer_size_callback(GLFWwindow* window,const int width,const int height)
{
    glViewport(0, 0, width, height);
}

void Window::process_input(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

bool Window::init() {

    if(m_is_running_) {
        std::cout << "Program already running!";
        return false;
    }

    glfwSetErrorCallback(error_callback);

    if (!glfwInit()) {
        std::cout << "Failed to initialize GLFW" << std::endl;
        return false;
    }

    m_window_ = glfwCreateWindow(m_width_, m_height_, m_title_, nullptr, nullptr);
    if (m_window_ == nullptr) {
        std::cout << "Failed to create GLFW Window" << std::endl;
        glfwTerminate();
        return false;
    }

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glfwMakeContextCurrent(m_window_);
    glfwSetFramebufferSizeCallback(m_window_, framebuffer_size_callback);
    glfwSetInputMode(m_window_, GLFW_CURSOR, GLFW_CURSOR_NORMAL);

    if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to load GLAD" << std::endl;
        return false;
    }

    m_is_running_ = true;
    return true;
}

bool Window::window_should_close() const
{
    return glfwWindowShouldClose(m_window_);
}

