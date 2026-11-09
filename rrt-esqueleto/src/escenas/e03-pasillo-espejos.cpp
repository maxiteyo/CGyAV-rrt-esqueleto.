#include <memory>
#include <escenas.h>
#include <plane.h>
#include <sphere.h>
#include <checker.h>
#include <mirror.h>
#include <triangle.h>
void build_scene_03(Scene &scene, Camera &camera)
{
    camera.look_at(glm::vec3(-2.0f, 2.0f, 7.5f), // ojo
                   glm::vec3(3.0f, 1.4f, 0.0f), // hacia donde mira
                   glm::vec3(0.0f, 1.0f, 0.0f), // arriba
                   45.0f);                      // fov vertical

    scene.set_background(glm::vec3(0.02f,0.03f,0.08f));

    auto floor = std::make_shared<Checker>();
    floor->size = 1.0f;
    floor->kd   = glm::vec3(0.7f);   
    floor->ka   = glm::vec3(0.07f);
    floor->kd2  = glm::vec3(0.10f);   
    floor->ka2  = glm::vec3(0.01f);
    scene.add_object(std::make_shared<Plane>(glm::vec3(0.0f), glm::vec3(0.0f, 1.0f, 0.0f), floor));

    // --- Paredes de espejo (dos rectángulos finitos, cada uno = 2 triángulos) ---
    auto wall_material = std::make_shared<Mirror>();
    wall_material->ka = glm::vec3(0.0f);
    wall_material->kd = glm::vec3(0.02f);
    wall_material->ks = glm::vec3(0.0f);
    wall_material->kr = 0.9f;

    // Pared izquierda en x = -3
    // Vértices según especificación: a=(-3,0,14), b=(-3,0,-12), c=(-3,5,-12), d=(-3,5,14)
    // Triángulos: a-b-c y a-c-d (orden CCW visto desde el interior del pasillo → normal +x)
    const glm::vec3 aL(-3.0f, 0.0f,  14.0f);
    const glm::vec3 bL(-3.0f, 0.0f, -12.0f);
    const glm::vec3 cL(-3.0f, 5.0f, -12.0f);
    const glm::vec3 dL(-3.0f, 5.0f,  14.0f);
    scene.add_object(std::make_shared<Triangle>(aL, bL, cL, wall_material));
    scene.add_object(std::make_shared<Triangle>(aL, cL, dL, wall_material));

    // Pared derecha en x = 3
    // Vértices: a=(3,0,14), b=(3,0,-12), c=(3,5,-12), d=(3,5,14)
    // Para que la normal apunte hacia el interior (-x), invertimos el orden: a-c-b y a-d-c
    // (o equivalentemente: a, c, b y a, d, c)
    const glm::vec3 aR( 3.0f, 0.0f,  14.0f);
    const glm::vec3 bR( 3.0f, 0.0f, -12.0f);
    const glm::vec3 cR( 3.0f, 5.0f, -12.0f);
    const glm::vec3 dR( 3.0f, 5.0f,  14.0f);
    scene.add_object(std::make_shared<Triangle>(aR, cR, bR, wall_material));  // a-c-b
    scene.add_object(std::make_shared<Triangle>(aR, dR, cR, wall_material));  // a-d-c

    auto red = std::make_shared<Diffuse>();
    red->ka = glm::vec3(0.08f, 0.01f, 0.01f);
    red->kd = glm::vec3(0.75f, 0.08f, 0.06f);
    red->ks = glm::vec3(0.5f);
    red->shininess = 60.0f;
    scene.add_object(std::make_shared<Sphere>(glm::vec3(0.2f, 1.0f, 0.0f), 1.0f, red));

    auto green = std::make_shared<Diffuse>();
    green->ka = glm::vec3(0.01f, 0.06f, 0.02f);
    green->kd = glm::vec3(0.1f, 0.6f, 0.2f);
    green->ks = glm::vec3(0.4f);
    green->shininess = 40.0f;
    scene.add_object(std::make_shared<Sphere>(glm::vec3(1.2f, 0.6f, 2.5f), 0.6f, green));

    auto espejo = std::make_shared<Mirror>();
    espejo->ka = glm::vec3(0.02f, 0.02f, 0.02f);
    espejo->kd = glm::vec3(0.1f, 0.1f, 0.1f);
    espejo->ks = glm::vec3(1.0f);
    espejo->kr = 0.85f;
    espejo->shininess = 150.0f;
    scene.add_object(std::make_shared<Sphere>(glm::vec3(-1.3f, 0.9f, -2.5f), 0.9f, espejo));

    const glm::vec3 att(1.0f, 0.12f, 0.02f);
    scene.add_light(Light(glm::vec3(0.0f, 9.0f, 5.0f), glm::vec3(4.0f, 4.0f, 4.0f), att));

}