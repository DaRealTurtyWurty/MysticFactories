#ifndef MYSTICFACTORIES_WORLDRENDERER_H
#define MYSTICFACTORIES_WORLDRENDERER_H

#include <SDL_render.h>
#include "../world/World.h"
#include "Camera.h"
#include "../math/Vector2.h"

class WorldRenderer {
private:
    World* world;
    Camera* camera;
    static std::map<Vector2, SDL_Color> tileColors;
public:
    explicit WorldRenderer(World *pWorld, Camera *pCamera);
    void Render(SDL_Renderer* renderer);
};

#endif //MYSTICFACTORIES_WORLDRENDERER_H
