#ifndef SHADER_H
#define SHADER_H

#include <iostream>
#include <vector>
#include <glad/glad.h>

class shader {
public:
    shader(char *vertex_path, const std::vector<char *> &fragment_paths) : m_vertex_path_(vertex_path) {
        m_vertex_shader_ = glCreateShader(GL_VERTEX_SHADER);
        for (char *path: fragment_paths) {
            m_fragment_paths_.push_back(path);
            m_fragment_shaders_.push_back(glCreateShader(GL_FRAGMENT_SHADER));
        }
    }

    bool init();

    unsigned int get_vertex_shader() const;

    std::vector<unsigned int> get_fragment_shaders() const;

    std::vector<unsigned int> get_shader_programs() const;

    void unload() const;

private:
    bool compile_shader(unsigned int, const char *path);

private:
    unsigned int m_vertex_shader_;
    std::vector<unsigned int> m_shader_programs_{};
    char *m_vertex_path_;
    std::vector<char *> m_fragment_paths_{};
    std::vector<unsigned int> m_fragment_shaders_{};
    std::vector<const char *> m_shaders_src_{};
};


#endif //SHADER_H
