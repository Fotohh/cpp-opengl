#include "Shader.h"

#include <fstream>
#include <iostream>

unsigned int shader::get_fragment_shader() const {
    return m_fragment_shader_;
}

unsigned int shader::get_vertex_shader() const {
    return m_vertex_shader_;
}

bool shader::init() {
    const bool vert_status = compile_shader(GL_VERTEX_SHADER);
    const bool frag_status = compile_shader(GL_FRAGMENT_SHADER);
    if (!vert_status || !frag_status) {
        std::cout << "Failed to load shaders!" << std::endl;
    }
    int success;
    m_shader_program_ = glCreateProgram();
    glAttachShader(m_shader_program_, m_vertex_shader_);
    glAttachShader(m_shader_program_, m_fragment_shader_);
    glLinkProgram(m_shader_program_);
    glGetProgramiv(m_shader_program_, GL_LINK_STATUS, &success);
    if (!success) {
        char log[512];
        glGetProgramInfoLog(m_shader_program_, 512, nullptr, log);
        std::cout << "ERROR::SHADER::LINKING_FAILED\n" << log << std::endl;
        return false;
    }
    glDeleteShader(m_vertex_shader_);
    glDeleteShader(m_fragment_shader_);
    return true;
}

unsigned int shader::get_shader_program() const {
    return m_shader_program_;
}

bool shader::compile_shader(const GLuint type) const {
    const char *path = type == GL_VERTEX_SHADER ? m_vertex_path_ : m_fragment_path_;
    const unsigned int shader = type == GL_VERTEX_SHADER ? m_vertex_shader_ : m_fragment_shader_;
    const std::string shader_name = type == GL_VERTEX_SHADER ? "VERTEX" : "FRAGMENT";
    std::ifstream file(path);
    const std::string str((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    const char *stream = str.c_str();
    file.close();
    glShaderSource(shader, 1, &stream, nullptr);
    glCompileShader(shader);
    int success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char log[512];
        glGetShaderInfoLog(shader, 512, nullptr, log);
        std::cout << "ERROR:SHADER::" + shader_name + "::COMPILATION_FAILED\n" << log << std::endl;
        return false;
    }
    return true;
}
