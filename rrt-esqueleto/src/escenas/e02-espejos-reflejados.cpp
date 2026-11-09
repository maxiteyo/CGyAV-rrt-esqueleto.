#include <memory>
#include <escenas.h>
#include <plane.h>
#include <sphere.h>
#include <checker.h>
#include <mirror.h>
void build_scene_02(Scene &scene, Camera &camera)
{
    camera.look_at(glm::vec3(2.0f, 1.6f, 2.5f), // ojo
                   glm::vec3(-6.0f, 0.7f, -1.5f), // hacia donde mira
                   glm::vec3(0.0f, 1.0f, 0.0f), // arriba
                   55.0f);                      // fov vertical

    scene.set_background(glm::vec3(0.02f));

    auto floor = std::make_shared<Checker>();
    floor->size = 0.5f;
    floor->kd   = glm::vec3(0.85f);   
    floor->ka   = glm::vec3(0.05f);
    floor->kd2  = glm::vec3(0.10f);   
    floor->ka2  = glm::vec3(0.006f);
    scene.add_object(std::make_shared<Plane>(glm::vec3(0.0f), glm::vec3(0.0f, 1.0f, 0.0f), floor));

    auto espejo_izq = std::make_shared<Mirror>();
    espejo_izq->ka = glm::vec3(0.0f);
    espejo_izq->kd = glm::vec3(0.0f);
    espejo_izq->ks = glm::vec3(0.0f);
    espejo_izq->kr = 0.8f;
    scene.add_object(std::make_shared<Plane>(glm::vec3(-2.5f,0.0f,0.0f), glm::vec3(1.0f, 0.0f, 0.0f), espejo_izq));

    auto espejo_der = std::make_shared<Mirror>();
    espejo_der->ka = glm::vec3(0.0f);
    espejo_der->kd = glm::vec3(0.0f);
    espejo_der->ks = glm::vec3(0.0f);
    espejo_der->kr = 0.8f;
    scene.add_object(std::make_shared<Plane>(glm::vec3(2.5f,0.0f,0.0f), glm::vec3(1.0f, 0.0f, 0.0f), espejo_der));

    auto white = std::make_shared<Diffuse>();
    white->ka = glm::vec3(0.05f, 0.02f, 0.0f);
    white->kd = glm::vec3(0.9f, 0.45f, 0.05f);
    white->ks = glm::vec3(0.5f);
    white->shininess = 50.0f;
    scene.add_object(std::make_shared<Sphere>(glm::vec3(0.0f, 0.7f, -1.0f), 0.7f, white));

    const glm::vec3 att(1.0f, 0.12f, 0.02f);
    scene.add_light(Light(glm::vec3(0.0f, 5.0f, 2.0f), glm::vec3(3.5f, 3.5f, 3.5f), att));
    
    scene.set_max_depth(8U);
}