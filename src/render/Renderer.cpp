#include "Renderer.h"

#include <iostream>

void Renderer::init(const size_t size) {
    glGenVertexArrays(size, m_vaos);
    glGenBuffers(size, m_vbos);
}

void Renderer::add_model(Model &model) {
    glBindVertexArray(m_vaos[m_init_count_]);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbos[m_init_count_]);

    glBufferData(GL_ARRAY_BUFFER, model.get_vertices().size() * sizeof(float), &model.get_vertices()[0], GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    model.set_index_location(m_init_count_);
    m_init_count_++;
}

void Renderer::render_model(const Model &model) const{
    glBindVertexArray(m_vaos[model.get_index_location()]);
    glDrawArrays(GL_TRIANGLES, 0, model.get_vertex_count());
}

void Renderer::unload() const {
    glDeleteVertexArrays(m_init_count_ + 1, m_vaos);
    glDeleteBuffers(m_init_count_ + 1, m_vbos);
}
