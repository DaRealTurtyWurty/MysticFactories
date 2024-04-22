#ifndef MYSTICFACTORIES_WORLD_H
#define MYSTICFACTORIES_WORLD_H

#include <map>
#include <string>
#include <vector>
#include "Chunk.h"
#include "entity/Player.h"

class World {
private:
    std::string name;
    std::map<ChunkPosition, Chunk*> chunks{};
    Player* player;
public:
    explicit World(std::string name);
    ~World();
    Chunk* GetChunk(int x, int y);
    void Update();
    void Load();
    void Save();
    std::vector<Chunk*> GetNearbyChunks();

    [[nodiscard]] Player* GetPlayer() const {
        return player;
    }
};

#endif //MYSTICFACTORIES_WORLD_H
