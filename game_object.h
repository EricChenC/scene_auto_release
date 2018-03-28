#pragma once 

#include "mesh.h"
#include "transform.h"

#include <memory>
#include <iostream>
#include <string>
#include <vector>

class GameObject {
public:
    explicit GameObject(const std::string& name)
        : name_(name)
        , parent_(nullptr)
    {
        transfrom_ = std::make_shared<Transform>();
        std::cout << "game object construct ->  " << name_ << std::endl;
    }

    ~GameObject(){
        std::cout << "game object destruct ->  " << name_ << std::endl;
    }

    void add_component(std::shared_ptr<Mesh> mesh) {
        mesh_ = mesh;
    }

    std::shared_ptr<Transform> transform() {
        return transfrom_;
    }

    std::shared_ptr<Mesh> get_mesh() {
        return mesh_;
    }

    void add_child(std::shared_ptr<GameObject> child) {
        childs_.push_back(child);
        child->parent_ = this;
    }

    std::vector<std::shared_ptr<GameObject>> get_childs() {
        return childs_;
    }

    //! never delete parent pointer, otherwise, program be crashed.
    GameObject* get_parent() {
        return parent_;
    }

private:
    std::shared_ptr<Mesh> mesh_;
    std::shared_ptr<Transform> transfrom_;
    std::string         name_;

    GameObject* parent_;
    std::vector<std::shared_ptr<GameObject>> childs_;
};