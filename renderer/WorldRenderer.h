#ifndef MYSTICFACTORIES_WORLDRENDERER_H
#define MYSTICFACTORIES_WORLDRENDERER_H

#include <SDL_render.h>
#include "../world/World.h"

class WorldRenderer {
private:
    World* world;
public:
    explicit WorldRenderer(World* pWorld);
    void Render(SDL_Renderer* renderer);
};

#endif //MYSTICFACTORIES_WORLDRENDERER_H
