#include <escenas.h>

const SceneEntry kScenes[] = {
    {  0, "Taller 1: plano con tablero, dos esferas difusas, luz puntual", build_scene_00 },
    { 11, "Spheres and Checkerboard (Whitted, 1980)", build_scene_11 },
    { 1, "Luces y sombras de colores", build_scene_01 },
    { 2, "Espejos y reflejos", build_scene_02 },
    { 3, "Pasillo con espejos", build_scene_03 },
    { 4, "Esferas de vidrio y agua", build_scene_04 },
    { 5, "Banco de índices de refracción", build_scene_05 },
    {6, "Esfera maciza, hueca y burbuja", build_scene_06 },
};

const int kSceneCount = int(sizeof(kScenes) / sizeof(kScenes[0]));
