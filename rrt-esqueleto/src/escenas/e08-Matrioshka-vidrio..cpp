#include <memory>
#include <escenas.h>
#include <plane.h>
#include <sphere.h>
#include <checker.h>
#include <mirror.h>
#include <triangle.h>
#include <dielectric.h>
void build_scene_08(Scene &scene, Camera &camera)
{
    camera.look_at(glm::vec3(0.0f, 2.0f, 6.0f), // ojo
                   glm::vec3(0.0f, 1.5f, 0.0f), // hacia donde mira
                   glm::vec3(0.0f, 1.0f, 0.0f), // arriba
                   45.0f);                      // fov vertical

    scene.set_background(glm::vec3(0.05f,0.07f,0.1f));

    auto floor = std::make_shared<Checker>();
    floor->size = 0.4f;
    floor->kd   = glm::vec3(0.85f);   
    floor->ka   = glm::vec3(0.05f);
    floor->kd2  = glm::vec3(0.08f, 0.08f, 0.3f);   
    floor->ka2  = glm::vec3(0.005f, 0.005f, 0.018f);
    scene.add_object(std::make_shared<Plane>(glm::vec3(0.0f), glm::vec3(0.0f, 1.0f, 0.0f), floor));

    auto sup_exterior1 = std::make_shared<Dielectric>();
    sup_exterior1->ior = 1.5f;
    sup_exterior1->transparency = 0.9f;
    sup_exterior1->ks = glm::vec3(1.0f);
    sup_exterior1->shininess=150.0f;
    scene.add_object(std::make_shared<Sphere>(glm::vec3(0.0f, 1.6f, 0.0f), 1.5f, sup_exterior1));

    auto sup_exterior2 = std::make_shared<Dielectric>();
    sup_exterior2->ior = 1.5f;
    sup_exterior2->transparency = 0.9f;
    sup_exterior2->ks = glm::vec3(1.0f);
    sup_exterior2->shininess=150.0f;
    scene.add_object(std::make_shared<Sphere>(glm::vec3(0.0f, 1.6f, 0.0f), 1.0f, sup_exterior2));

    auto sup_exterior3 = std::make_shared<Dielectric>();
    sup_exterior3->ior = 1.5f;
    sup_exterior3->transparency = 0.9f;
    sup_exterior3->ks = glm::vec3(1.0f);
    sup_exterior3->shininess=150.0f;
    scene.add_object(std::make_shared<Sphere>(glm::vec3(0.0f, 1.6f, 0.0f), 0.6f, sup_exterior3));

    auto sup_interior1 = std::make_shared<Dielectric>();
    sup_interior1->ior = 1/1.5f;
    sup_interior1->transparency = 0.9f;
    sup_interior1->ks = glm::vec3(0.0f);
    sup_interior1->shininess=150.0f;
    scene.add_object(std::make_shared<Sphere>(glm::vec3(0.0f, 1.6f, 0.0f), 1.44f, sup_interior1));

    auto sup_interior2 = std::make_shared<Dielectric>();
    sup_interior2->ior = 1/1.5f;
    sup_interior2->transparency = 0.9f;
    sup_interior2->ks = glm::vec3(0.0f);
    sup_interior2->shininess=150.0f;
    scene.add_object(std::make_shared<Sphere>(glm::vec3(0.0f, 1.6f, 0.0f), 0.96f, sup_interior2));

    auto sup_interior3 = std::make_shared<Dielectric>();
    sup_interior3->ior = 1/1.5f;
    sup_interior3->transparency = 0.9f;
    sup_interior3->ks = glm::vec3(0.0f);
    sup_interior3->shininess=150.0f;
    scene.add_object(std::make_shared<Sphere>(glm::vec3(0.0f, 1.6f, 0.0f), 0.576f, sup_interior3));

    auto nucleo = std::make_shared<Diffuse>();
    nucleo->kd = glm::vec3(0.85f, 0.08f, 0.05f);
    nucleo->ka = glm::vec3(0.05f, 0.0f, 0.0f);
    nucleo->ks = glm::vec3(0.5f);
    nucleo->shininess = 40.0f;
    scene.add_object(std::make_shared<Sphere>(glm::vec3(0.0f, 1.6f, 0.0f), 0.3f, nucleo));

    const glm::vec3 att(1.0f, 0.12f, 0.02f);
    scene.add_light(Light(glm::vec3(-3.0f, 6.0f, 4.0f), glm::vec3(2.8f, 2.8f, 2.8f), att));
    scene.add_light(Light(glm::vec3(4.0f, 4.0f, 3.0f), glm::vec3(1.0f, 1.0f, 1.0f), att));

    scene.set_max_depth(12U);
}
