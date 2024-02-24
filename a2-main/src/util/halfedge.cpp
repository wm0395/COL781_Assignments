#include "mesh.hpp"
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void Vertex::traverse(void (*func)(Face *face)){
    HalfEdge *he = halfedge;
    bool boundary = false;
    do{
        Face *face = he->left;
        func(face);
        //check for boundary
        if(he->next->pair){
            he = he->next->pair;
        }
        else{
            boundary = true;
            break;
        }

    }while(he != halfedge);

    he = halfedge->pair;
    // reverse traversal for opposite of boundary
    while(he && boundary){
        Face *face = he->left;
        func(face);
        he = he->next->next->pair;
    }
}

void Face::traverse(void (*func)(Vertex *vertex)){
    HalfEdge *he = halfedge;
    do{
        Vertex *vertex = he->head;
        func(vertex);
        he = he->next;

    }while(he != halfedge);    
}

ivec3 Face::get_face_vertices(){
    std::vector<GLint> vert = {};
    
    HalfEdge *he = this->halfedge;
    do{
        Vertex *vertex = he->head;
        // std::cout << vertex->index << "\n";
        vert.push_back(vertex->index);
        // std::cout << he->head->index << " " << he->next->head->index << "\n";
        he = he->next;
        // std::cout << he->head->index << "\n";

    }while(he != this->halfedge);

    ivec3 indices = ivec3(vert[0], vert[1], vert[2]);
    return indices;
}

int hash_func(int i, int j, int n){
    return n*std::min(i,j) + std::max(i,j);
}
// pair<int,int> inv_hash_func(int N, int n){
//     return make_pair((int)(N/n), int(N%n));
// }

void get_vflist(HalfEdge* &head, vector<vec3>& vertex, vector<vec3>& normal, vector<ivec3>& face){
    int N = face.size();
    int V = vertex.size();

    // std::cout << N << " " << V << "\n";
    vector<Vertex*> v2v(V, new Vertex()); //vertex-list to vertex pointer
    // vector<vector<HalfEdge*>> v2h(V, vector<HalfEdge*>(V, new HalfEdge()));//vertex-list to all it's half-edge pointers
    unordered_map<int, vector<HalfEdge*>> v2h;
    vector<Face*> f2f(N, new Face());//face-list to face pointer
    for(int i = 0; i < V; i++){
        v2v[i]->index = i;
        v2v[i]->position = &vertex[i];
        v2v[i]->normal = &normal[i];
    }

    for (int i = 0; i<V; i++){
        Vertex *v = v2v[i];
        std::cout << "vertex => " << v << "\n";
        std::cout << "Index => " << v->index << "\n";
        vec3 pos = *v->position;
        std::cout << "position => " << pos.x << " " << pos.y << " " << pos.z << "\n";
        std::cout << "\n";
    }
    
    for(int i = 0; i < N; i++){
        f2f[i]->index = i;
        
        HalfEdge *he = new HalfEdge();
        f2f[i]->halfedge = he;
        he->left = f2f[i]; 
        v2v[face[i].x]->halfedge = he;
        he->head = v2v[face[i].x];
        v2h[hash_func(face[i].x, face[i].y, N)].push_back(he);

        he->next = new HalfEdge();
        he->next->left = f2f[i];
        v2v[face[i].y]->halfedge = he->next;
        he->next->head = v2v[face[i].y];
        v2h[hash_func(face[i].y, face[i].z, N)].push_back(he->next);

        he->next->next = new HalfEdge();
        he->next->next->left = f2f[i];
        v2v[face[i].z]->halfedge = he->next->next;
        he->next->next->head = v2v[face[i].z];
        v2h[hash_func(face[i].z, face[i].x, N)].push_back(he->next->next);

        he->next->next->next = he;
    }
    for(auto vhe: v2h){
        if(vhe.second.size() < 2) continue;
        vhe.second[0]->pair = vhe.second[1];
        vhe.second[1]->pair = vhe.second[0];
    }
    head = v2v[0]->halfedge;
    // cout << "exiting vflist" <<endl;
}