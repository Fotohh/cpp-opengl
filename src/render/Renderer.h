//
// Created by zinha on 10/20/2024.
//

#ifndef RENDERER_H
#define RENDERER_H

#include "../shader/Shader.h"
#include <GLFW/glfw3.h>

#include "../obj/Model.h"
#include "../obj/ModelManager.h"


class renderer {

public:
    renderer(shader &shader, model_manager* manager) : m_shader_(shader), m_manager_(manager) {
    }
    void init();
    void update() const;
    void unload() const;

private:
    const shader &m_shader_;
    model_manager *m_manager_;
    unsigned int m_vaos_[100]{};
    unsigned int m_vbos_[100]{};
    unsigned int m_ebos_[100]{};
};



#endif //RENDERER_H
