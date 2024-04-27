#include "WorldRenderer.h"

WorldRenderer::WorldRenderer(World* pWorld, Camera* pCamera) : world(pWorld), camera(pCamera) {}

void WorldRenderer::Render(SDL_Renderer* renderer) {
    int camX = camera->getX();
    int camY = camera->getY();

    std::map<ChunkPosition, Chunk*>* chunks = world->GetChunks();
    for (std::pair<ChunkPosition, Chunk*> pair : *chunks) {
        if (!camera->IsVisible(pair.first.x * CHUNK_SIZE * TILE_SIZE, pair.first.y * CHUNK_SIZE * TILE_SIZE,CHUNK_SIZE * TILE_SIZE, CHUNK_SIZE * TILE_SIZE))
            continue;

        Chunk* chunk = pair.second;
        for (int x = 0; x < CHUNK_SIZE; x++) {
            for (int y = 0; y < CHUNK_SIZE; y++) {
                TileData tile = chunk->GetTile(x, y);
                if(tile.isEmpty())
                    continue;

                int tileX = (pair.first.x * CHUNK_SIZE * TILE_SIZE) + (x * TILE_SIZE);
                int tileY = (pair.first.y * CHUNK_SIZE * TILE_SIZE) + (y * TILE_SIZE);

                SDL_Rect rect = {tileX - camX, tileY - camY, TILE_SIZE, TILE_SIZE};
                SDL_SetRenderDrawColor(renderer, 0, 128, 0, 255);
                SDL_RenderFillRect(renderer, &rect);
            }
        }

        std::list<Entity*> entities = chunk->GetEntities();
        for (Entity* entity : entities) {
            if (!camera->IsVisible(entity->GetXPos(), entity->GetYPos(), 16, 16))
                continue;

            SDL_Rect rect = {entity->GetXPos() - camX, entity->GetYPos() - camY, 16, 16};
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            SDL_RenderFillRect(renderer, &rect);
        }
    }

    Player* player = world->GetPlayer();

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_Rect playerRect = {player->GetXPos() - camX, player->GetYPos() - camY, 16, 16};
    SDL_RenderFillRect(renderer, &playerRect);
}
