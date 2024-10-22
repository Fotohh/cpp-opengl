#ifndef SHADER_H
#define SHADER_H

#include <iostream>
#include <vector>
#include <glad/glad.h>

class shader {
public:
    explicit shader(char *vertex_path) : m_vertex_path_(vertex_path) {
        m_vertex_shader_ = glCreateShader(GL_VERTEX_SHADER);
    }

    bool init() const;

    unsigned int get_vertex_shader() const;

    unsigned int create_shader_program(char* path);

    std::vector<unsigned int> get_fragment_shaders() const;

    std::vector<unsigned int> get_shader_programs() const;

    void unload() const;

private:
    static bool compile_shader(unsigned int, const char *path);

private:
    unsigned int m_vertex_shader_;
    std::vector<unsigned int> m_shader_programs_{};
    char *m_vertex_path_;
    std::vector<char *> m_fragment_paths_{};
    std::vector<unsigned int> m_fragment_shaders_{};
};


#endif //SHADER_H
