#include "Chunk.h"

Chunk::Chunk() {
    for (int x = 0; x < CHUNK_SIZE; x++) {
        for (int y = 0; y < CHUNK_SIZE; y++) {
            tiles[x][y] = TileData(TileType::EMPTY);
        }
    }
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
            tiles[x][y].Update();
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

    return tiles[relativeX][relativeY];
}
