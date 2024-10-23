//
// Created by zinha on 10/21/2024.
//

#ifndef MODEL_H
#define MODEL_H

class model {

public:
    model(float vertices[], const int vertex_count) : m_vertices_(vertices), m_vertex_count_(vertex_count) {

    }

    float* get_vertices() const;
    int get_vertex_count() const;
    int get_index_location() const;
    void set_index_location(int loc);
private:
    float* m_vertices_;
    const int m_vertex_count_;
    int m_index_location_{};
};

#endif //MODEL_H
