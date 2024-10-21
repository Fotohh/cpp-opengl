//
// Created by zinha on 10/21/2024.
//

#ifndef MODELMANAGER_H
#define MODELMANAGER_H
#include <vector>

#include "Model.h"

class model_manager {

public:
    model_manager() = default;
    void add_model(model& model);
    void remove_model(int pos);
    std::vector<model*> get_models();
    size_t get_model_size() const;
private:
    std::vector<model*> m_models_{};
};



#endif //MODELMANAGER_H
