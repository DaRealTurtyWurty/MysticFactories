#include "WorldRenderer.h"
#include "../math/Random.h"

std::map<Vector2, SDL_Color> WorldRenderer::tileColors;

WorldRenderer::WorldRenderer(World* pWorld, Camera* pCamera) : world(pWorld), camera(pCamera) {}

void WorldRenderer::Render(SDL_Renderer* renderer) {
    std::map<ChunkPosition, Chunk*>* chunks = world->GetChunks();
    for (std::pair<ChunkPosition, Chunk*> pair : *chunks) {
        int chunkX = Chunk::GetXWorldSpace(pair.first.x);
        int chunkY = Chunk::GetYWorldSpace(pair.first.y);

        if (!camera->IsVisible(chunkX, chunkY, CHUNK_SIZE * TILE_SIZE, CHUNK_SIZE * TILE_SIZE))
            continue;

        Chunk* chunk = pair.second;
        for (int x = 0; x < CHUNK_SIZE; x++) {
            for (int y = 0; y < CHUNK_SIZE; y++) {
                TileData tile = chunk->GetTile(x, y);
                if(tile.isEmpty())
                    continue;

                int tileX = chunkX + (x * TILE_SIZE);
                int tileY = chunkY + (y * TILE_SIZE);

                SDL_Rect rect = {camera->GetRelativeX(tileX), camera->GetRelativeY(tileY), TILE_SIZE, TILE_SIZE};

                // This is temporary code to randomize the colour until a proper lookup is implemented
                SDL_Color color = tileColors[{tileX, tileY}];
                if(color.r == 0 && color.g == 0 && color.b == 0) {
                    Uint8 red = 20 + Random::Global.Next(5, 10);
                    Uint8 green = 128 + Random::Global.Next(-10, 20);
                    Uint8 blue = 20 + Random::Global.Next(5, 10);
                    color = tileColors[{tileX, tileY}] = {red, green, blue, 255};
                }

                SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
                SDL_RenderFillRect(renderer, &rect);
            }
        }

        std::list<Entity*> entities = chunk->GetEntities();
        for (Entity* entity : entities) {
            if (!camera->IsVisible(entity->GetXPos(), entity->GetYPos(), 16, 16))
                continue;

            SDL_Rect rect = {camera->GetRelativeX(entity->GetXPos()), camera->GetRelativeY(entity->GetYPos()), 16, 16};
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            SDL_RenderFillRect(renderer, &rect);
        }
    }

    Player* player = world->GetPlayer();

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_Rect playerRect = {camera->GetRelativeX(player->GetXPos()), camera->GetRelativeY(player->GetYPos()), 16, 16};
    SDL_RenderFillRect(renderer, &playerRect);
}