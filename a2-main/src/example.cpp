#include "viewer.hpp"
#include "./util/util.hpp"
#include "./util/mesh.cpp"
#include "./util/halfedge.cpp"
#include <vector>
#include <iostream>

namespace V = COL781::Viewer;
using namespace glm;
using namespace std;

int main() {
    // vec3 vertices[] = {
    //     vec3(-0.5, -0.5, 0.0),
    //     vec3( 0.5, -0.5, 0.0),
    //     vec3(-0.5,  0.5, 0.0),
    //     vec3( 0.5,  0.5, 0.0)
    // };
    // vec3 normals[] = {
    //     vec3(0.0, 0.0, 1.0),
    //     vec3(0.0, 0.0, 1.0),
    //     vec3(0.0, 0.0, 1.0),
    //     vec3(0.0, 0.0, 1.0)
    // };
    // ivec3 triangles[] = {
    //     ivec3(0, 1, 2),
    //     ivec3(1, 2, 3),
    // };

    vector<vec3> vertices = {
        vec3(-0.5, -0.5, 0.0),
        vec3( 0.5, -0.5, 0.0),
        vec3(-0.5,  0.5, 0.0),
        vec3( 0.5,  0.5, 0.0)
    };

    vector<vec3> normals = {
        vec3(0.0, 0.0, 1.0),
        vec3(0.0, 0.0, 1.0),
        vec3(0.0, 0.0, 1.0),
        vec3(0.0, 0.0, 1.0)
    };

    vector<ivec3> triangles = {
        ivec3(0, 1, 2),
        ivec3(1, 2, 3),
    };

    HalfEdge *he = nullptr;
    get_vflist(he, vertices, normals, triangles);

    Mesh *mesh = new Mesh(vertices.size(), triangles.size(), he->head);
    mesh->give_initial_mesh();
    mesh->populate_mesh();

    // V::Viewer v;
    // if (!v.initialize("Mesh viewer", 640, 480)) {
    //     return EXIT_FAILURE;
    // }
    // v.setVertices(4, vertices);
    // v.setNormals(4, normals);
    // v.setTriangles(2, triangles);
    // v.view();


    // vector<vec3> vertex;
    // vector<vec3> normal;
    // vector<ivec3> face;

    // string file = "meshes/bunny-1k.obj";

    // parse_OBJ(file.c_str(), vertex, normal, face);

    // vec3 *vertices = new vec3[vertex.size()];
    // copy(vertex.begin(), vertex.end(), vertices);

    // vec3 *normals = new vec3[normal.size()];
    // copy(normal.begin(), normal.end(), normals);

    // ivec3 *triangles = new ivec3[face.size()];
    // copy(face.begin(), face.end(), triangles);

    // V::Viewer v;
    // if (!v.initialize("Mesh viewer", 640, 480)) {
    //     return EXIT_FAILURE;
    // }
    // v.setVertices(vertex.size(), vertices);
    // v.setNormals(normal.size(), normals);
    // v.setTriangles(face.size(), triangles);
    // v.view(); 
}