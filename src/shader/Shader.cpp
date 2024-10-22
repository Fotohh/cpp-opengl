#include "Shader.h"

#include <fstream>

std::vector<unsigned int> shader::get_fragment_shaders() const {
    return m_fragment_shaders_;
}

unsigned int shader::get_vertex_shader() const {
    return m_vertex_shader_;
}

bool shader::init() {
    const bool vert_status = compile_shader(m_vertex_shader_, m_vertex_path_);
    for (int i = 0; i < m_fragment_shaders_.size(); i++) {
        const unsigned int shader = m_fragment_shaders_[i];
        const char *path = m_fragment_paths_[i];
        const bool frag_status = compile_shader(shader, path);

        if (!frag_status) {
            std::cout << "Failed to load fragment shaders!" << std::endl;
            return false;
        }
    }

    if (!vert_status) {
        std::cout << "Failed to load vertex shaders!" << std::endl;
        return false;
    }

    for (const unsigned int fragment_shader: m_fragment_shaders_) {
        int success;
        const unsigned int shader_program = glCreateProgram();
        glAttachShader(shader_program, m_vertex_shader_);
        glAttachShader(shader_program, fragment_shader);
        glLinkProgram(shader_program);
        glGetProgramiv(shader_program, GL_LINK_STATUS, &success);
        if (!success) {
            char log[512];
            glGetProgramInfoLog(shader_program, 512, nullptr, log);
            std::cout << "ERROR::SHADER::LINKING_FAILED\n" << log << std::endl;
            return false;
        }
        glDeleteShader(fragment_shader);
        m_shader_programs_.push_back(shader_program);
    }
    glDeleteShader(m_vertex_shader_);
    return true;
}

std::vector<unsigned int> shader::get_shader_programs() const {
    return m_shader_programs_;
}

bool shader::compile_shader(const unsigned int shader, const char *path) {
    std::ifstream file(path);
    const std::string str((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    const char *stream = str.c_str();
    file.close();
    m_shaders_src_.push_back(stream);
    glShaderSource(shader, 1, &stream, nullptr);
    glCompileShader(shader);
    int success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char log[512];
        glGetShaderInfoLog(shader, 512, nullptr, log);
        std::cout << "ERROR:SHADER::COMPILATION_FAILED\n" << log << std::endl;
        return nullptr;
    }
    return stream;
}

void shader::unload() const {
    for (const unsigned int program: m_shader_programs_) {
        glDeleteProgram(program);
    }
}
