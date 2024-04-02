#include "Scene.hpp"

Renderer::Renderer(int bounces, int paths, int samples, string sampling) : MAX_BOUNCES(bounces), PATHS(paths), SAMPLES(samples), SAMPLING(sampling){

}


vec4 Renderer::rand_hemisphere(){
    float e1 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    float e2 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    return vec4(sqrt(1-e1*e1)*cos(2*M_PI*e2), sqrt(1-e1*e1)*sin(2*M_PI*e2), e1, 0.0f);
}

vec4 Renderer::cos_hemisphere(){
    float e1 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    float e2 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    float theta = acos(sqrt(e1));
    float phi = 2 * M_1_PIf32 * e2;
 
    float x = cos(phi) * sin(theta);
    float y = sin(phi) * sin(theta);
    float z = cos(theta);
 
    return vec4(x, y, z, 0.0f);
}


pair<int, vec4> Renderer::incident_ray(vec4 position, vec4 direction){
    Ray *ray = new Ray();
    ray->o = position;
    ray->d = direction;
    ray->t_near = 0.01f;
    ray->t_far = 1000.0f;
    float t = INT32_MAX;
    int hit_id = -1;
    for(int i = 0; i < scene->objects.size(); i++){
        ray->t = 0;
        pair<Ray*, vec4> hit = scene->objects[i]->hit(ray);
        if(ray->t > 0 && ray->t < t){
            t = ray->t;
            hit_id = i;
        }
    }
    vec4 p = position + t * ray->d;
    return {hit_id, p};
}

int Renderer::shadow_ray(int light_id, vec4 position){
    Ray *ray = new Ray();
    ray->o = scene->lights[light_id]->position;
    ray->d = position - scene->lights[light_id]->position;
    ray->t_near = 0.0f;
    ray->t_far = 1000.0f;
    // int bias = 0.0
    float t = INT32_MAX;
    int hit_id = -1;
    for(int i = 0; i < scene->objects.size(); i++){
        ray->t = 0;
        pair<Ray*, vec4> hit = scene->objects[i]->hit(ray);
        if(ray->t > 0.01f && ray->t < t && ray->t < INT32_MAX){
            t = ray->t;
            hit_id = i;
        }
    }
    vec4 p = ray->o + t * ray->d;
    if(dot(p- position, p- position) > 0.00001f)
        hit_id = -1;
    return hit_id;
}

vec4 Renderer::point_lambert(Ray *ray){
    pair<int, vec4> hit = incident_ray(ray->o, ray->d);
    // pair<*Ray, vec4> reflect = scene->objects[hit.first]->hit(ray);
    if(hit.first == -1) return scene->sky;
    
    vec4 color = vec4(0.0f, 0.0f, 0.0f, 1.0f);
    
    if(scene->objects[hit.first]->material->emmission){
        color += scene->objects[hit.first]->material->emmission(ray->o, ray->d, scene->objects[hit.first]->normal_ray(hit.second));
    }
    
    float N = 0.0f;
    
    vec4 intensity = vec4(0.0f, 0.0f, 0.0f, 0.0f);

    for(int i = 0; i < scene->lights.size(); i++){
        if(shadow_ray(i, hit.second) != hit.first){ 
            // cout<<hit.first<<"Ray Blocked\n";
            continue;
        }

        N+= 1.0f;
        vec4 irradiace = scene->lights[i]->Intensity;
        float fall_off = 4.0f*(float)M_PI*glm::dot(scene->lights[i]->position - hit.second, scene->lights[i]->position - hit.second);
        vec4 out = scene->lights[i]->position - hit.second;
        vec4 normal = scene->objects[hit.first]->normal_ray(hit.second);
        float out_norm = glm::length(out);
        float normal_norm = glm::length(normal);
        float cos_theta = glm::dot(out, normal)/ (out_norm * normal_norm);
        // cout << cos_theta <<"\n";
        // float cos_theta = glm::dot(hit.second - scene->lights[i]->position, -(ray->d))/ (sqrt(glm::dot(hit.second - scene->lights[i]->position, hit.second - scene->lights[i]->position)) * sqrt(glm::dot(ray->d, ray->d)));
        // float cos_theta = 1.0f;
        irradiace *= (cos_theta/ fall_off);
        irradiace.w /= (cos_theta/ fall_off);
        intensity += irradiace;
    }
    
    intensity = vec4(glm::min(1.0f, intensity.x), glm::min(1.0f, intensity.y), glm::min(1.0f, intensity.z), glm::min(1.0f, intensity.w));

    if(N == 0.0f){
        // cout<< hit.first <<"no light intersect\n";
        return color;
    }

    intensity = vec4(pow(intensity.x, 1.0f/2.2), pow(intensity.y, 1.0f/2.2), pow(intensity.z, 1.0f/2.2), pow(intensity.w, 1.0f/2.2));
    intensity *= (2.0f/pow(N,1.0f/4.0f));
    vec4 temp = vec4(1.0f, 1.0f, 1.0f, 1.0f);
    // if(scene->objects[hit.first]->material->diffuse)
    //     temp = scene->objects[hit.first]->material->diffuse(ray->o, ray->d);
    color = color + ((scene->objects[hit.first]->material->albedo * intensity));
    
    color = vec4(glm::min(1.0f, color.x), glm::min(1.0f, color.y), glm::min(1.0f, color.z), glm::min(1.0f, color.w));
    return color;
}

vec4 Renderer::normal_map(Ray *ray){
    pair<int, vec4> i_ray = incident_ray(ray->o, ray->d);
    if(i_ray.first == -1) return vec4(0.0f, 0.0f, 0.0f, 0.0f);

    pair<Ray*, vec4> hit = scene->objects[i_ray.first]->hit(ray);
    vec4 normal = hit.second;
    vec4 color = (normal + vec4(1.0f, 1.0f, 1.0f, 1.0f));    // if hit
    color /= 2;
    return color;
}

vec4 Renderer::MC_Sampling(int obj_id, vec4 position, vec4 out_dir, int depth){
    
    vec4 F = vec4(0.0f, 0.0f, 0.0f, 0.0f);
    
    vec4 normal = scene->objects[obj_id]->normal_ray(position);
    float normal_norm = glm::length(normal);

    vec3 z = normalize(vec3(normal.x, normal.y, normal.z));
    vec3 x = normalize(glm::cross(vec3(out_dir.x, out_dir.y, out_dir.z), z));
    vec3 y = normalize(glm::cross(z, x));
    mat4 T = mat4(vec4(x.x, x.y, x.z, 0.0f),vec4(y.x, y.y, y.z, 0.0f),vec4(z.x, z.y, z.z, 0.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f));

    for(int i = 0; i < PATHS && depth <= MAX_BOUNCES; i++){
        
        // Uniform Hemisphere
        vec4 rand_dir = rand_hemisphere();
        // // Cos weighted Hemisphere
        // vec4 rand_dir = cos_hemisphere();
        rand_dir = T * rand_dir;

        pair<int, vec4> hit = incident_ray(position, rand_dir);
        if(hit.first == -1){
            F += scene->sky;
            continue;
        }

        Ray *branch_ray = new Ray();
        branch_ray->o = position;
        branch_ray->d = rand_dir;
        branch_ray->t = 0.0f;
        branch_ray->t_near = 0.0f;
        branch_ray->t_far = 1000.0f;
        pair<Ray*, vec4> hit_out = scene->objects[hit.first]->hit(branch_ray);

        float fall_off = 4.0f*(float)M_PI*glm::dot(hit.second - position, hit.second - position);
        // float fall_off = 1.0f;
        // vec4 out = hit.second - position;
        
        
        vec4 irradiance = MC_Sampling(hit.first, hit.second, -rand_dir, depth+1);
        
        // Not needed for Xos sampling
        float out_norm = glm::length(rand_dir);
        float cos_theta = glm::dot(rand_dir, normal)/ (out_norm * normal_norm);
        irradiance *= (cos_theta/ fall_off);
        irradiance.w /= (cos_theta/ fall_off);

        F += scene->objects[obj_id]->material->diffuse(out_dir, rand_dir, normal) * irradiance;
    }

    // F *= (2.0f*M_1_PI/glm::pow((float)SAMPLES, 1.0f/4.0f));
    // F /= (float)PATHS;
    if(scene->objects[obj_id]->material->emmission){
        F += scene->objects[obj_id]->material->emmission(position, out_dir, normal);
    }

    // F = scene->objects[obj_id]->material->diffuse(position, out_dir) * F;
    return scene->objects[obj_id]->material->albedo * F;
}

// vec4 Renderer::path_trace(int obj_id, vec4 position, vec4 out_dir, int depth){
//     vec4 color = scene->objects[obj_id]->material->emmission(position, -out_dir);
// }

vec4 Renderer::ray_trace(Ray *ray){
    pair<int, vec4> hit = incident_ray(ray->o, ray->d);
    if(hit.first == -1) return scene->sky;

    vec4 intensity = vec4(0.0f, 0.0f, 0.0f, 0.0f);
    for(int i = 0; i < SAMPLES; i++){ 
        intensity += MC_Sampling(hit.first, hit.second, -(ray->d), 1);
    }
    
    intensity = vec4(pow(intensity.x, 1.0f/2.2f), pow(intensity.y, 1.0f/2.2f), pow(intensity.z, 1.0f/2.2f), pow(intensity.w, 1.0f/2.2f));
    intensity *= (2.0f*M_1_PI/glm::pow((float)SAMPLES, 1.0f/1.0f));
    intensity = vec4(glm::min(1.0f, intensity.x), glm::min(1.0f, intensity.y), glm::min(1.0f, intensity.z), glm::min(1.0f, intensity.w));
    
    return scene->objects[hit.first]->material->albedo * intensity;
}

vec4 Renderer::render(Ray* ray){
    if(SAMPLING.compare("normal_map") == 0)
        return normal_map(ray);
    else if(SAMPLING.compare("point_lambert") == 0)
        return point_lambert(ray);
    else if(SAMPLING.compare("ray_trace") == 0)
        return ray_trace(ray);
    else 
        return vec4(0,0,0,0);
}