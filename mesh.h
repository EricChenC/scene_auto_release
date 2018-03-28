#pragma once

#include <memory>
#include <iostream>
#include <glm.hpp>
#include <vector>

class Mesh {
public:
    explicit Mesh() {
        std::cout << "mesh construct\n";
    }

    ~Mesh() {
        std::cout << "mesh destruct\n";
    }

    void set_vetexs(std::shared_ptr<std::vector<glm::vec3>> vertexs) {
        vertexs_ = vertexs;
    }

    void set_uvs(std::shared_ptr<std::vector<glm::vec2>> uvs) {
        uvs_ = uvs;
    }

    void set_normals(std::shared_ptr<std::vector<glm::vec3>> normals) {
        normals_ = normals;
    }

    std::shared_ptr<std::vector<glm::vec3>> get_vertexs() {
        return vertexs_;
    }

    std::shared_ptr<std::vector<glm::vec2>> get_uvs() {
        return uvs_;
    }

    std::shared_ptr<std::vector<glm::vec3>> get_normals() {
        return normals_;
    }

private:
    std::shared_ptr<std::vector<glm::vec3>> vertexs_;
    std::shared_ptr<std::vector<glm::vec2>> uvs_;
    std::shared_ptr<std::vector<glm::vec3>> normals_;

};