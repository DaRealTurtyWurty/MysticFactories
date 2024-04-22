#include "World.h"

#include <utility>

World::World(std::string name) : name(std::move(name)) {
    this->player = new Player(100, 100, 0, 0); // TODO: Load data from file
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
}

void World::Save() {
    // TODO: Save world data to file
}

std::vector<Chunk*> World::GetNearbyChunks() {
    std::vector<Chunk*> nearbyChunks;
    ChunkPosition playerChunkPosition = {player->GetXPos() / Chunk::CHUNK_SIZE, player->GetYPos() / Chunk::CHUNK_SIZE};

    for (int x = playerChunkPosition.x - 1; x <= playerChunkPosition.x + 1; x++) {
        for (int y = playerChunkPosition.y - 1; y <= playerChunkPosition.y + 1; y++) {
            Chunk* chunk = GetChunk(x, y);
            if(chunk != nullptr)
                nearbyChunks.push_back(chunk);
        }
    }

    return nearbyChunks;
}
