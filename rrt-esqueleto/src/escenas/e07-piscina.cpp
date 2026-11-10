#include <memory>
#include <escenas.h>
#include <plane.h>
#include <sphere.h>
#include <checker.h>
#include <mirror.h>
#include <triangle.h>
#include <dielectric.h>
void build_scene_07(Scene &scene, Camera &camera)
{
    camera.look_at(glm::vec3(0.0f, 0.9f, 6.0f), // ojo
                   glm::vec3(0.0f, 0.35f, -4.0f), // hacia donde mira
                   glm::vec3(0.0f, 1.0f, 0.0f), // arriba
                   50.0f);                      // fov vertical

    scene.set_background(glm::vec3(0.35f,0.55f,0.8f));

    auto floor = std::make_shared<Checker>();
    floor->size = 0.5f;
    floor->kd   = glm::vec3(0.85f);   
    floor->ka   = glm::vec3(0.05f);
    floor->kd2  = glm::vec3(0.08f, 0.3f, 0.55f);   
    floor->ka2  = glm::vec3(0.005f, 0.02f, 0.035f);
    scene.add_object(std::make_shared<Plane>(glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), floor));

    auto sup_agua = std::make_shared<Dielectric>();
    sup_agua->ior = 1.33f;
    sup_agua->transparency = 0.9f;
    sup_agua->ks = glm::vec3(1.0f);
    sup_agua->shininess=300.0f;
    scene.add_object(std::make_shared<Plane>(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), sup_agua));

    auto red = std::make_shared<Diffuse>();
    red->kd = glm::vec3(0.8f, 0.1f, 0.1f);
    red->ka = glm::vec3(0.04f, 0.0f, 0.0f);
    red->ks = glm::vec3(0.4f);
    red->shininess = 40.0f;
    scene.add_object(std::make_shared<Sphere>(glm::vec3(0.2f, 0.7f, 1.5f), 0.5f, red));

    auto yellow = std::make_shared<Diffuse>();
    yellow->kd = glm::vec3(0.85f, 0.75f, 0.1f);
    yellow->ka = glm::vec3(0.04f, 0.04f, 0.0f);
    yellow->ks = glm::vec3(0.4f);
    yellow->shininess = 40.0f;
    scene.add_object(std::make_shared<Sphere>(glm::vec3(-4.5f, 2.2f, -16.0f), 2.0f, yellow));

    auto green = std::make_shared<Diffuse>();
    green->kd = glm::vec3(0.1f, 0.7f, 0.2f);
    green->ka = glm::vec3(0.0f, 0.04f, 0.0f);
    green->ks = glm::vec3(0.4f);
    green->shininess = 40.0f;
    scene.add_object(std::make_shared<Sphere>(glm::vec3(4.0f, 1.6f, -11.0f), 1.4f, green));

    const glm::vec3 att(1.0f, 0.12f, 0.02f);
    scene.add_light(Light(glm::vec3(-6.0f, 10.0f, 4.0f), glm::vec3(13.5f, 13.5f, 12.6f), att));
}