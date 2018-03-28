#include "scene.h"

#include <memory>
#include <iostream>
#include <vector>

#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h> 


void add_mesh(std::shared_ptr<GameObject> game_object) {

    auto vertexs = std::make_shared<std::vector<glm::vec3>>();
    auto uvs = std::make_shared<std::vector<glm::vec2>>();
    auto normals = std::make_shared<std::vector<glm::vec3>>();

    vertexs->push_back(glm::vec3(0.5, 0.5, 0.5));
    vertexs->push_back(glm::vec3(0.5, 0.5, 0.5));
    vertexs->push_back(glm::vec3(0.5, 0.5, 0.5));
  
    uvs->push_back(glm::vec2(0.8, 0.8));
    uvs->push_back(glm::vec2(0.8, 0.8));
    uvs->push_back(glm::vec2(0.8, 0.8));

    normals->push_back(glm::vec3(0.0, 1.0, 0.0));
    normals->push_back(glm::vec3(0.0, 1.0, 0.0));
    normals->push_back(glm::vec3(0.0, 1.0, 0.0));

    auto mesh = std::make_shared<Mesh>();
    mesh->set_vetexs(vertexs);
    mesh->set_uvs(uvs);
    mesh->set_normals(normals);

    game_object->add_component(mesh);
}

void add_game_object(std::shared_ptr<Scene> scene) {
    auto game_object = std::make_shared<GameObject>("game_object");
    add_mesh(game_object);

    auto game_object_child = std::make_shared<GameObject>("game_object_child");
    add_mesh(game_object_child);

    game_object->add_child(game_object_child);

    auto game_object1 = std::make_shared<GameObject>("game_object1");
    add_mesh(game_object1);

    scene->add_root(game_object);
    scene->add_root(game_object1);
}

void main(){
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    auto scene = std::make_shared<Scene>();
    add_game_object(scene);

    std::cout << "add game object end\n";

    auto roots = scene->get_roots();
    for (auto root = roots.begin(); root != roots.end(); root++) {
        auto mesh = (*root)->get_mesh();
        auto vertexs = mesh->get_vertexs();
        auto uvs = mesh->get_uvs();
        auto normals = mesh->get_normals();

        std::cout << "vertexs ------------------\n\n";
        for (auto vertex = vertexs->begin(); vertex != vertexs->end(); vertex++) {
            std::cout << vertex->x << " " << vertex->y << " " << vertex->z << std::endl;
        }

        std::cout << "\n\nuvs ------------------\n\n";
        for (auto uv = uvs->begin(); uv != uvs->end(); uv++) {
            std::cout << uv->x << " " << uv->y << std::endl;
        }

        std::cout << "\n\nnormals ------------------\n\n";
        for (auto normal = normals->begin(); normal != normals->end(); normal++) {
            std::cout << normal->x << " " << normal->y << " " << normal->z << std::endl;
        }

        auto childs = (*root)->get_childs();
        for (auto child = childs.begin(); child != childs.end(); child++) {
            auto child_mesh = (*child)->get_mesh();
            auto child_vertexs = child_mesh->get_vertexs();
            auto child_uvs = child_mesh->get_uvs();
            auto child_normals = child_mesh->get_normals();

            std::cout << "\n\nchild vertexs ------------------\n\n";
            for (auto vertex = child_vertexs->begin(); vertex != child_vertexs->end(); vertex++) {
                std::cout << vertex->x << " " << vertex->y << " " << vertex->z << std::endl;
            }

            std::cout << "\n\nchild uvs ------------------\n\n";
            for (auto uv = child_uvs->begin(); uv != child_uvs->end(); uv++) {
                std::cout << uv->x << " " << uv->y << std::endl;
            }

            std::cout << "\n\nchild normals ------------------\n\n";
            for (auto normal = child_normals->begin(); normal != child_normals->end(); normal++) {
                std::cout << normal->x << " " << normal->y << " " << normal->z << std::endl;
            }

            auto parent = (*child)->get_parent();

            //delete parent;

            std::cout << "\n\n";

        }

        std::cout << "\n\n";

    }



}