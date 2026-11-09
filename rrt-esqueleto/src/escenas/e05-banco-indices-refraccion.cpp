#include <memory>
#include <escenas.h>
#include <plane.h>
#include <sphere.h>
#include <checker.h>
#include <mirror.h>
#include <triangle.h>
#include <dielectric.h>
void build_scene_05(Scene &scene, Camera &camera)
{
    camera.look_at(glm::vec3(0.0f, 1.8f, 5.0f), // ojo
                   glm::vec3(0.0f, 0.7f, 0.0f), // hacia donde mira
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

    auto aire = std::make_shared<Dielectric>();
    aire->ior = 1.0f;
    aire->transparency = 0.9f;
    aire->ks = glm::vec3(1.0f);
    aire->shininess=150.0f;
    scene.add_object(std::make_shared<Sphere>(glm::vec3(-2.4f, 0.8f, 0.0f), 0.7f, aire));

    auto agua = std::make_shared<Dielectric>();
    agua->ior = 1.33f;
    agua->transparency = 0.9f;
    agua->ks = glm::vec3(1.0f);
    agua->shininess=150.0f;
    scene.add_object(std::make_shared<Sphere>(glm::vec3(-0.8f, 0.8f, 0.0f), 0.7f, agua));

    auto vidrio = std::make_shared<Dielectric>();
    vidrio->ior = 1.5f;
    vidrio->transparency = 0.9f;
    vidrio->ks = glm::vec3(1.0f);
    vidrio->shininess=150.0f;
    scene.add_object(std::make_shared<Sphere>(glm::vec3(0.8f, 0.8f, 0.0f), 0.7f, vidrio));

    auto diamante = std::make_shared<Dielectric>();
    diamante->ior = 2.42f;
    diamante->transparency = 0.9f;
    diamante->ks = glm::vec3(1.0f);
    diamante->shininess=150.0f;
    scene.add_object(std::make_shared<Sphere>(glm::vec3(2.4f, 0.8f, 0.0f), 0.7f, diamante));

    const glm::vec3 att(1.0f, 0.12f, 0.02f);
    scene.add_light(Light(glm::vec3(-3.0f, 6.0f, 4.0f), glm::vec3(2.6f, 2.6f, 2.6f), att));
    scene.add_light(Light(glm::vec3(4.0f, 4.0f, 3.0f), glm::vec3(1.0f, 1.0f, 1.0f), att));

}