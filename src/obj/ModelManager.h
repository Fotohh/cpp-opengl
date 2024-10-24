//
// Created by zinha on 10/23/2024.
//

#ifndef MODELMANAGER_H
#define MODELMANAGER_H

#include <vector>

#include "Model.h"


class model_manager {

public:
    model_manager() = default;

    long add_model(model &model);
    void remove_model(const model &model);
    std::vector<model*> get_models() const;
    long size() const;

private:
    std::vector<model*> m_models_{};

};



#endif //MODELMANAGER_H
