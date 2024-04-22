#include "Chunk.h"

void Chunk::Update() {
    for (auto entity : entities) {
        entity->Update();

        if (entity->IsDead()) {
            RemoveEntity(entity);
        }
    }

    // TODO: Tile updates
}

void Chunk::AddEntity(Entity* entity) {
    entities.push_back(entity);
}

void Chunk::RemoveEntity(Entity* entity) {
    entities.remove(entity);

    delete entity;
}