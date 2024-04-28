#include "Chunk.h"

Chunk::Chunk() {
    tiles.fill(TileData{GRASS});
}

void Chunk::Update() {
    for (auto entity : entities) {
        entity->Update();

        if (entity->IsDead()) {
            RemoveEntity(entity);
        }
    }

    for (int x = 0; x < CHUNK_SIZE; x++) {
        for (int y = 0; y < CHUNK_SIZE; y++) {
            tiles[x * CHUNK_SIZE + y].Update();
        }
    }
}

void Chunk::AddEntity(Entity* entity) {
    entities.push_back(entity);
}

void Chunk::RemoveEntity(Entity* entity) {
    entities.remove(entity);

    delete entity;
}

TileData Chunk::GetTile(int x, int y) const {
    int relativeX = x % CHUNK_SIZE;
    int relativeY = y % CHUNK_SIZE;

    return tiles[relativeX * CHUNK_SIZE + relativeY];
}

int Chunk::GetXWorldSpace(int x) {
    return x * CHUNK_SIZE * TILE_SIZE;
}

int Chunk::GetYWorldSpace(int y) {
    return y * CHUNK_SIZE * TILE_SIZE;
}
