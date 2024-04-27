#ifndef MYSTICFACTORIES_WORLDRENDERER_H
#define MYSTICFACTORIES_WORLDRENDERER_H

#include <SDL_render.h>
#include "../world/World.h"
#include "Camera.h"

class WorldRenderer {
private:
    World* world;
    Camera* camera;
public:
    explicit WorldRenderer(World *pWorld, Camera *pCamera);
    void Render(SDL_Renderer* renderer);
};

#endif //MYSTICFACTORIES_WORLDRENDERER_H
