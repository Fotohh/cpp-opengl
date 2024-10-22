//
// Created by zinha on 10/20/2024.
//

#ifndef RENDERER_H
#define RENDERER_H

#include "../obj/Model.h"
#include "../obj/ModelManager.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>



class renderer {

public:
    explicit renderer(model_manager* manager) : m_manager_(manager) {
    }
    void init();
    void add_model(model &model);
    void unload() const;
    void render_model(const model &model);

private:
    model_manager *m_manager_;
    unsigned int m_vaos_[100]{};
    unsigned int m_vbos_[100]{};
    unsigned int m_ebos_[100]{};
    int m_render_count_ = 0;
    int m_init_count_ = 0;
};



#endif //RENDERER_H
