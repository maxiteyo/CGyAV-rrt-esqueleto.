#include <memory>
#include <escenas.h>
#include <plane.h>
#include <sphere.h>
#include <checker.h>
#include <mirror.h>
#include <triangle.h>
#include <dielectric.h>
void build_scene_04(Scene &scene, Camera &camera)
{
    camera.look_at(glm::vec3(0.0f, 2.4f, 9.0f), // ojo
                   glm::vec3(0.0f, 1.0f, 0.0f), // hacia donde mira
                   glm::vec3(0.0f, 1.0f, 0.0f), // arriba
                   40.0f);                      // fov vertical

    // Fondo degradado: horizonte (y=0) → cenit (y=1)
    // Horizonte: (0.55, 0.65, 0.8)  |  Cenit: (0.05, 0.12, 0.35)
    scene.set_background(
        glm::vec3(0.55f, 0.65f, 0.80f),  // horizonte
        glm::vec3(0.05f, 0.12f, 0.35f)   // cenit
    );

    auto floor = std::make_shared<Checker>();
    floor->size = 1.0f;
    floor->kd   = glm::vec3(0.75f);   
    floor->ka   = glm::vec3(0.12f);
    floor->kd2  = glm::vec3(0.05f, 0.15f, 0.45f);   
    floor->ka2  = glm::vec3(0.01f, 0.03f, 0.08f);
    scene.add_object(std::make_shared<Plane>(glm::vec3(0.0f), glm::vec3(0.0f, 1.0f, 0.0f), floor));

    auto vidrio = std::make_shared<Dielectric>();
    vidrio->ior = 1.5f;
    vidrio->transparency = 0.8f;
    vidrio->ks = glm::vec3(1.0f);
    vidrio->shininess=100.0f;
    scene.add_object(std::make_shared<Sphere>(glm::vec3(-1.3f, 1.2f, 2.5f), 1.2f, vidrio));

    auto agua = std::make_shared<Dielectric>();
    agua->ior = 1.33f;
    agua->transparency = 0.9f;
    agua->ks = glm::vec3(1.0f);
    agua->shininess=100.0f;
    scene.add_object(std::make_shared<Sphere>(glm::vec3(1.7f, 0.8f, 3.0f), 0.8f, agua));

    auto red = std::make_shared<Diffuse>();
    red->kd = glm::vec3(0.75f, 0.1f, 0.08f);
    red->ka = 0.1f * red->kd;
    red->ks = glm::vec3(0.4f);
    red->shininess = 50.0f;
    scene.add_object(std::make_shared<Sphere>(glm::vec3(-2.6f, 0.8f, -1.5f), 0.8f, red));

    auto yellow = std::make_shared<Diffuse>();
    yellow->kd = glm::vec3(0.85f, 0.6f, 0.05f);
    yellow->ka = 0.1f * yellow->kd;
    yellow->ks = glm::vec3(0.4f);
    yellow->shininess = 50.0f;
    scene.add_object(std::make_shared<Sphere>(glm::vec3(-0.5f, 0.8f, -2.0f), 0.8f, yellow));

    auto green = std::make_shared<Diffuse>();
    green->kd = glm::vec3(0.1f, 0.55f, 0.2f);
    green->ka = 0.1f * green->kd;
    green->ks = glm::vec3(0.4f);
    green->shininess = 50.0f;
    scene.add_object(std::make_shared<Sphere>(glm::vec3(1.8f, 0.8f, -1.0f), 0.8f, green));

    const glm::vec3 att(1.0f, 0.12f, 0.02f);
    scene.add_light(Light(glm::vec3(-5.0f, 9.0f, 7.0f), glm::vec3(3.0f, 3.0f, 3.0f), att));
    scene.add_light(Light(glm::vec3(6.0f, 7.0f, 5.0f), glm::vec3(2.0f, 2.0f, 2.0f), att));

    

}