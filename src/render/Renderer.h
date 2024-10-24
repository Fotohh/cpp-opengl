//
// Created by zinha on 10/20/2024.
//

#ifndef RENDERER_H
#define RENDERER_H

#include "../obj/Model.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class renderer {

public:
    renderer() = default;
    void init(long size);
    void add_model(model &model);
    void unload() const;
    void render_model(const model &model) const;

public:
    unsigned int m_vaos[10]{};
    unsigned int m_vbos[10]{};
    unsigned int m_ebos[10]{};
private:
    int m_init_count_ = 0;
};

#endif //RENDERER_H
