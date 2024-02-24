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

    // vector<vec3> vertices = {
    //     vec3(-0.5, -0.5, 0.0),
    //     vec3( 0.5, -0.5, 0.0),
    //     vec3(-0.5,  0.5, 0.0),
    //     vec3( 0.5,  0.5, 0.0)
    // };

    // vector<vec3> normals = {
    //     vec3(0.0, 0.0, 1.0),
    //     vec3(0.0, 0.0, 1.0),
    //     vec3(0.0, 0.0, 1.0),
    //     vec3(0.0, 0.0, 1.0)
    // };

    // vector<ivec3> triangles = {
    //     ivec3(0, 1, 2),
    //     ivec3(1, 2, 3),
    // };

    // HalfEdge *he = nullptr;
    // get_vflist(he, vertices, normals, triangles);

    // Mesh *mesh = new Mesh(vertices.size(), triangles.size(), he->head);
    // // mesh->populate_mesh();
    // vec3* verti = mesh->give_vertices();
    // vec3* norm = mesh->give_normals();
    // ivec3* tri = mesh->give_triangles();

    // V::Viewer v;
    // if (!v.initialize("Mesh viewer", 640, 480)) {
    //     return EXIT_FAILURE;
    // }
    // v.setVertices(4, verti);
    // v.setNormals(4, norm);
    // v.setTriangles(2, tri);
    // v.view();


    vector<vec3> vertex;
    vector<vec3> normal;
    vector<ivec3> face;

    string file = "meshes/noisycube.obj";

    parse_OBJ(file.c_str(), vertex, normal, face);

    HalfEdge *he = nullptr;
    get_vflist(he, vertex, normal, face);

    Mesh *mesh = new Mesh(vertex.size(), face.size(), he->head);
    mesh->recompute_normals();
    // vec3* vertices = mesh->vertices;
    // vec3* normals = mesh->normals;
    // ivec3* triangles = mesh->triangles;

    // for (int i = 0; i<vertex.size(); i++){
    //     if (vertex[i] != vertices[i]){
    //         std::cout << i << "\n";
    //     }
    //     if (normal[i] != normals[i]){
    //         std::cout << i << "\n";
    //     }
    // }

    // for (int i = 0; i<face.size(); i++){
    //     if (face[i] != triangles[i]){
    //         std::cout << i << "\n";
    //     }
    // }

    vec3* vertices = new vec3[vertex.size()];
    copy(vertex.begin(), vertex.end(),vertices);

    vec3* normals = new vec3[normal.size()];
    copy(normal.begin(), normal.end(),normals);

    ivec3* triangles = new ivec3[face.size()];
    copy(face.begin(), face.end(), triangles);

    // for (int i = 0; i<vertex.size(); i++){
    //     // if (mesh->vertices[i] != vertices[i]){
    //     //     std::cout << i << "\n";
    //     // }
    //     // if (mesh->normals[i] != normals[i]){
    //     //     std::cout << i << "\n";
    //     // }
    //     std::cout << i << " "  << normals[i].x << " " << normals[i].y << " " << normals[i].z << " " << mesh->normals[i].x << " " << mesh->normals[i].y << " " << mesh->normals[i].z << "\n";
    // }

    // for (int i = 0; i<vertex.size(); i++){
    //     std::cout << &normals[i] << " " << &mesh->normals[i] << "\n";
    // }

    // for (int i = 0; i<face.size(); i++){
    //     if (mesh->triangles[i] != triangles[i]){
    //         std::cout << i << "\n";
    //     }
    // }

    V::Viewer v;
    if (!v.initialize("Mesh viewer", 640, 480)) {
        return EXIT_FAILURE;
    }
    v.setVertices(vertex.size(), mesh->vertices);
    v.setNormals(vertex.size(), mesh->normals);
    v.setTriangles(face.size(), mesh->triangles);
    v.view(); 
} 