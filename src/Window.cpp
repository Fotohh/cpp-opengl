
#include "Window.h"

int window::get_width() const {
    return m_width_;
}

int window::get_height() const {
    return m_height_;
}

GLFWwindow* window::get_window() const {
    return m_window_;
}

const char* window::get_title() const {
    return m_title_;
}

bool window::init() {

    (void) glfwInit();
    glfwWindowHint(GLFW_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_window_ = glfwCreateWindow(m_width_, m_height_,m_title_, nullptr, nullptr);
    if (m_window_ == nullptr) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(m_window_);
    glfwSetFramebufferSizeCallback(m_window_, framebuffer_size_callback);
    glfwSetInputMode(m_window_, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to load GLAD" << std::endl;
        return false;
    }

    return true;

}

