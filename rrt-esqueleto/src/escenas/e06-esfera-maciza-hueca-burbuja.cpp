#include <memory>
#include <escenas.h>
#include <plane.h>
#include <sphere.h>
#include <checker.h>
#include <mirror.h>
#include <triangle.h>
#include <dielectric.h>
void build_scene_06(Scene &scene, Camera &camera)
{
    camera.look_at(glm::vec3(0.0f, 2.2f, 6.0f), // ojo
                   glm::vec3(0.0f, 0.8f, 0.0f), // hacia donde mira
                   glm::vec3(0.0f, 1.0f, 0.0f), // arriba
                   45.0f);                      // fov vertical

    scene.set_background(glm::vec3(0.05f,0.07f,0.1f));

    auto floor = std::make_shared<Checker>();
    floor->size = 0.4f;
    floor->kd   = glm::vec3(0.85f);   
    floor->ka   = glm::vec3(0.05f);
    floor->kd2  = glm::vec3(0.06f, 0.3f, 0.1f);   
    floor->ka2  = glm::vec3(0.004f, 0.018f, 0.006f);
    scene.add_object(std::make_shared<Plane>(glm::vec3(0.0f), glm::vec3(0.0f, 1.0f, 0.0f), floor));

    auto maciza = std::make_shared<Dielectric>();
    maciza->ior = 1.5f;
    maciza->transparency = 0.9f;
    maciza->ks = glm::vec3(1.0f);
    maciza->shininess=150.0f;
    scene.add_object(std::make_shared<Sphere>(glm::vec3(-2.0f, 0.9f, 0.0f), 0.8f, maciza));

    auto hueca_ext = std::make_shared<Dielectric>();
    hueca_ext->ior = 1.5f;
    hueca_ext->transparency = 0.9f;
    hueca_ext->ks = glm::vec3(1.0f);
    hueca_ext->shininess=150.0f;
    scene.add_object(std::make_shared<Sphere>(glm::vec3(0.0f, 0.9f, 0.0f), 0.8f, hueca_ext));

    auto hueca_int = std::make_shared<Dielectric>();
    hueca_int->ior = 1/1.5f;
    hueca_int->transparency = 0.9f;
    hueca_int->ks = glm::vec3(0.0f);
    hueca_int->shininess=150.0f;
    scene.add_object(std::make_shared<Sphere>(glm::vec3(0.0f, 0.9f, 0.0f), 0.768f, hueca_int));

    auto burbuja = std::make_shared<Dielectric>();
    burbuja->ior = 1/1.33f;
    burbuja->transparency = 0.9f;
    burbuja->ks = glm::vec3(1.0f);
    burbuja->shininess=150.0f;
    scene.add_object(std::make_shared<Sphere>(glm::vec3(2.0f, 0.9f, 0.0f), 0.8f, burbuja));

    const glm::vec3 att(1.0f, 0.12f, 0.02f);
    scene.add_light(Light(glm::vec3(-3.0f, 6.0f, 4.0f), glm::vec3(2.6f, 2.6f, 2.6f), att));
    scene.add_light(Light(glm::vec3(4.0f, 4.0f, 3.0f), glm::vec3(1.0f, 1.0f, 1.0f), att));

}