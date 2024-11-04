//
// Created by zinha on 10/21/2024.
//

#ifndef MODEL_H
#define MODEL_H
#include <utility>
#include <vector>

class Model {
public:
    Model(const std::vector<float>& vertices, const int vertex_count) : m_vertices_(vertices), m_vertex_count_(vertex_count) {
    }

    const std::vector<float>& get_vertices();

    int get_vertex_count() const;

    int get_index_location() const;

    bool operator==(const Model& other) const {
        return m_index_location_ == other.get_index_location();
    }

    void set_index_location(int loc);

private:
    std::vector<float> m_vertices_;
    const int m_vertex_count_;
    int m_index_location_ = 0;
};

#endif //MODEL_H
