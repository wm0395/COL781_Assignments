#include "Scene.hpp"
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>


Shape::Shape(){
    material = new Material();
    transformation_mat = mat4(1.0f);
}

void Shape::scaling(vec3 s){
    cout << "Before scaling => \n";
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cout << transformation_mat[i][j] << " ";
        }
        cout << endl;
    }

    transformation_mat = scale(transformation_mat, s);

    cout << "After scaling => \n";
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cout << transformation_mat[i][j] << " ";
        }
        cout << endl;
    }
}

void Shape::translation(vec3 t){

    cout << "Before translation => \n";
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cout << transformation_mat[i][j] << " ";
        }
        cout << endl;
    }

    transformation_mat = translate(transformation_mat, t);

    cout << "After translation => \n";
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cout << transformation_mat[i][j] << " ";
        }
        cout << endl;
    }

}

void Shape::rotation(float radian, vec3 axis){
    std::cout << "Before rotation: " << std::endl;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            std::cout << transformation_mat[i][j] << " ";
        }
        std::cout << std::endl;
    }

    transformation_mat = rotate(transformation_mat, radians(radian), axis);

    std::cout << "After rotation: " << std::endl;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            std::cout << transformation_mat[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Shape::invert_transformation(){
    // print before inversion
    std::cout << "Before inversion: " << std::endl;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            std::cout << transformation_mat[i][j] << " ";
        }
        std::cout << std::endl;
    }
    mat4 tmp = inverse(transformation_mat);
    transformation_mat = tmp;
    // transformation_mat = inverse(transformation_mat);

    // print after inversion
    std::cout << "After inversion: " << std::endl;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            std::cout << transformation_mat[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

Sphere::Sphere(const float &r, const vec4 &c) : radius(r), centre(c) {

}

pair<Ray*, vec4> Sphere::hit(Ray *ray) {
    
    // mat4 world_to_object = inverse(transformation_mat);
    mat4 world_to_object = transformation_mat;

    //print the world_to_object mat4
    // cout << "World to object matrix: \n";
    // for (int i = 0; i<4; i++){
    //     for (int j = 0; j<4; j++){
    //         std::cout << world_to_object[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    ray->o = world_to_object * ray->o;
    ray->d = world_to_object * ray->d;

    float x1 = dot(ray->d, ray->o - centre);
    float norm_d_sq = length(ray->d);
    norm_d_sq *= norm_d_sq;
    float x2 = dot(ray->o - centre, ray->o - centre) - radius * radius;

    if (x1 * x1 - norm_d_sq * x2 < 0){
        ray->t = INT32_MAX;
        return {nullptr, vec4(0.0f,0.0f,0.0f,0.0f)};
    }
    float D = sqrt(x1 * x1 - norm_d_sq * x2);
    float t1 = -x1 - D;

    t1 /= norm_d_sq;

    float t2 = -x1 + D;
    t2 /= norm_d_sq;

    if(t2 <= ray->t_near){
        ray->t = INT32_MAX;
        return {nullptr, vec4(0.0f,0.0f,0.0f,0.0f)};
    }
    else if(t1 <= ray->t_near){
        ray->t = t2;
        return reflected_ray(ray, t2);
    }
    else{
        ray->t = t1;
        return reflected_ray(ray, t1);
    }
}

vec4 Sphere::normal_ray(vec4 position){
    return position - centre;
}

pair<Ray*, vec4> Sphere::reflected_ray(Ray* ray, float t){
    vec4 normal = ray->o + t * ray->d - centre;
    float norm = length(normal);
    normal /= norm;

    Ray* ref_ray = new Ray();
    ref_ray->o = ray->o + t * ray->d;
    ref_ray->t_near = ray->t_near;
    ref_ray->t_far = ray->t_far;
    vec4 d = ray->d / length(ray->d);
    ref_ray->d = d - 2*dot(normal,d)*normal;

    // normal = normal * inverse(transpose(transformation_mat));   // yeh ooper aayega ya idhar 
    normal = normal * transpose(transformation_mat);

    return {new Ray(), normal};
}

Plane::Plane(const vec4 &normal, const vec4 &point_on_plane) : normal(normal), point_on_plane(point_on_plane) {

}

pair<Ray*, vec4> Plane::hit(Ray *ray){

    mat4 world_to_object = inverse(transformation_mat);
    ray->o = world_to_object * ray->o;
    ray->d = world_to_object * ray->d;

    // t = (n · (p0 − o))/(n · d) 
    float t = float(dot(normal, point_on_plane - ray->o)) / dot(normal, ray->d);
    if (t <= ray->t_near){
        ray->t = INT32_MAX;
        return {nullptr, vec4(0.0f,0.0f,0.0f,0.0f)};
    }
    else{
        ray->t = t;
        return reflected_ray(ray, t);
    }
}

vec4 Plane::normal_ray(vec4 position){
    return normal;
}

pair<Ray*, vec4> Plane::reflected_ray(Ray* ray, float t){
    Ray* ref_ray = new Ray();
    ref_ray->o = ray->o + t * ray->d;
    ref_ray->t_near = ray->t_near;
    ref_ray->t_far = ray->t_far;
    vec4 d = ray->d / length(ray->d);
    vec4 n = normal / length(normal);
    ref_ray->d = d - 2*dot(n,d)*n;

    normal = normal * transpose(transformation_mat);    // yeh ooper aayega ya idhar hi
    return {ref_ray, normal};
}