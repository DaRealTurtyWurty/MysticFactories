#include "World.h"

#include <utility>

World::World(std::string name) : name(std::move(name)) {
    this->worldRenderer = new WorldRenderer(this);
}

World::~World() {
    Save();
}

Chunk* World::GetChunk(int x, int y) {
    return chunks[{x, y}];
}

void World::Update() {
    for (auto& chunk : chunks) {
        chunk.second->Update();
    }
}

void World::Load() {

}

void World::Save() {

}

std::vector<Chunk> World::GetNearbyChunks() {
    std::vector<Chunk> nearbyChunks;
    ChunkPosition playerChunkPosition = {player->GetXPos() / Chunk::CHUNK_SIZE, player->GetYPos() / Chunk::CHUNK_SIZE};

    for (int x = playerChunkPosition.x - 1; x <= playerChunkPosition.x + 1; x++) {
        for (int y = playerChunkPosition.y - 1; y <= playerChunkPosition.y + 1; y++) {
            nearbyChunks.push_back(*GetChunk(x, y));
        }
    }

    return nearbyChunks;
}
