#include "Renderer.h"

#include <iostream>

void Renderer::init(const size_t size) {
    if(size > MAX_MODELS) {
        std::cout << "Renderer only supports up to " << MAX_MODELS << " models!" << std::endl;
        m_capacity_ = MAX_MODELS;
    }else {
        m_capacity_ = size;
    }

    glGenVertexArrays(static_cast<GLsizei>(m_capacity_), m_vaos);
    glGenBuffers(static_cast<GLsizei>(m_capacity_), m_vbos);
}

void Renderer::add_model(Model &model) {
    if(m_init_count_ >= static_cast<int>(m_capacity_)) {
        std::cout << "Renderer has no room for another model!" << std::endl;
        return;
    }

    glBindVertexArray(m_vaos[m_init_count_]);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbos[m_init_count_]);

    glBufferData(GL_ARRAY_BUFFER, model.get_vertices().size() * sizeof(float), model.get_vertices().data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    model.set_index_location(m_init_count_);
    m_init_count_++;
}

void Renderer::render_model(const Model &model) const{
    if(model.get_index_location() < 0 || model.get_index_location() >= m_init_count_) {
        std::cout << "Model has not been initialized by the renderer!" << std::endl;
        return;
    }

    glBindVertexArray(m_vaos[model.get_index_location()]);
    glDrawArrays(GL_TRIANGLES, 0, model.get_vertex_count());
}

void Renderer::unload() const {
    glDeleteVertexArrays(m_init_count_, m_vaos);
    glDeleteBuffers(m_init_count_, m_vbos);
}
