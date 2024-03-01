#include "std_mesh.hpp"
#include "mesh.cpp"
#include "halfedge.cpp"
#include <vector>
#include <iostream>

using namespace glm;
using namespace std;

Mesh* square_grid(int m, int n){
    // vec3 vertices[(m+1)*(n+1)];
    // vec3 normals[(m+1)*(n+1)];
    // ivec3 triangles[2*m*n];

    // int cnt = 0;
    // int tri_cnt = 0;

    // std::swap(m,n);

    // for (int i = 0; i<=m; i++){
    //     for (int j = 0; j<=n; j++){
    //         vertices[cnt] = vec3(float(i)/float(m)-0.5, float(j)/float(n)-0.5, 0.0);
    //         normals[cnt] = vec3(0.0, 0.0, 1.0);
    //         cnt++;

    //         if (j!=n && i!=m)
    //         {
    //             int x1 = (n+1)*i + j;
    //             int x2 = x1+1;
    //             int x3 = (n+1)*(i+1) + j;
    //             int x4 = x3+1;
    //             triangles[tri_cnt] = ivec3(x1, x2, x3);
    //             tri_cnt++;
    //             triangles[tri_cnt] = ivec3(x2, x3, x4);
    //             tri_cnt++;
    //         }
    //     }
    // }
    vec3 vertices[] = {
        vec3(-0.5, -0.5, 0.0),
        vec3( 0.5, -0.5, 0.0),
        vec3(-0.5,  0.5, 0.0),
        vec3( 0.5,  0.5, 0.0)
    };
    vec3 normals[] = {
        vec3(0.0, 0.0, 1.0),
        vec3(0.0, 0.0, 1.0),
        vec3(0.0, 0.0, 1.0),
        vec3(0.0, 0.0, 1.0)
    };
    ivec3 triangles[] = {
        ivec3(0, 1, 2),
        ivec3(1, 2, 3),
    };

    Mesh* mesh = new Mesh(4, 2, vertices, normals, triangles);

    // Mesh* mesh = new Mesh((m+1)*(n+1), 2*m*n, vertices, normals, triangles);

    std::cout << mesh->vertices << "\n";

    for (int i = 0; i<mesh->num_of_vertices; i++){
        vec3 pos = mesh->vertices[i];
        std::cout << pos.x << " " << pos.y << " " << pos.z << "\n";
    }
    return mesh;
}