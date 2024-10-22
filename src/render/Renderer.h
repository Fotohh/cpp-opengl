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
    renderer(model_manager* manager) : m_manager_(manager) {
    }
    void init();
    void update() const;
    void unload() const;

private:
    model_manager *m_manager_;
    unsigned int m_vaos_[100]{};
    unsigned int m_vbos_[100]{};
    unsigned int m_ebos_[100]{};
};



#endif //RENDERER_H
