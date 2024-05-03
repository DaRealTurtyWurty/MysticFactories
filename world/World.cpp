#include "World.h"

#include <utility>
#include <intrin.h>

World::World(std::string name) : name(std::move(name)) {
    this->player = new Player(100, 100, 0, 0); // TODO: Load data from file
    Load(); // TEMP
}

World::~World() {
    Save();
}

Chunk* World::GetChunk(int x, int y) {
    ChunkPosition chunkPosition = {x, y};

    for (const auto& item: chunks) {
        if (item.first.x == chunkPosition.x && item.first.y == chunkPosition.y) {
            return item.second;
        }
    }

    return nullptr;
}

void World::Update() {
    for (auto chunk: GetNearbyChunks()) {
        chunk->Update();
    }

    player->Update();

    // TODO: Day/night cycle
}

void World::Load() {
    // TODO: Load world data from file

    // TODO: Remove
    // Generate chunks
    for (int x = -10; x < 10; x++) {
        for (int y = -10; y < 10; y++) {
            chunks[{x, y}] = new Chunk();
        }
    }
}

void World::Save() {
    // TODO: Save world data to file
}

std::vector<Chunk*> World::GetNearbyChunks(int atX, int atY) {
    std::vector<Chunk*> nearbyChunks;
    ChunkPosition chunkPos = {atX / CHUNK_SIZE, atY / CHUNK_SIZE};

    for (int x = chunkPos.x - 1; x <= chunkPos.x + 1; x++) {
        for (int y = chunkPos.y - 1; y <= chunkPos.y + 1; y++) {
            Chunk* chunk = GetChunk(x, y);
            if(chunk != nullptr)
                nearbyChunks.push_back(chunk);
        }
    }

    return nearbyChunks;
}

std::vector<Chunk*> World::GetNearbyChunks() {
    return World::GetNearbyChunks(player->GetXPos(), player->GetYPos());
}

std::list<Entity *> World::GetEntities(int x, int y, int radius) {
    // find all chunks in the radius
    int chunkX = x / CHUNK_SIZE;
    int chunkY = y / CHUNK_SIZE;
    int chunkRadius = ceil(static_cast<double>(radius) / CHUNK_SIZE);

    std::vector<Chunk*> nearbyChunks;
    for (int i = chunkX - chunkRadius; i <= chunkX + chunkRadius; i++) {
        for (int j = chunkY - chunkRadius; j <= chunkY + chunkRadius; j++) {
            Chunk* chunk = GetChunk(i, j);
            if (chunk != nullptr) {
                nearbyChunks.push_back(chunk);
            }
        }
    }

    // find all entities in the chunks
    std::list<Entity*> entities;
    for (auto chunk : nearbyChunks) {
        for (auto entity : chunk->GetEntities()) {
            if (entity->DistanceTo(x, y) <= radius) {
                entities.push_back(entity);
            }
        }
    }

    return entities;
}

std::map<ChunkPosition, Chunk*>* World::GetChunks() {
    return &chunks;
}