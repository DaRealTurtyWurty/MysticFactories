#ifndef MYSTICFACTORIES_CHUNK_H
#define MYSTICFACTORIES_CHUNK_H

#include <list>
#include "entity/Entity.h"
#include "tile/TileData.h"

const static int CHUNK_SIZE = 16;

struct ChunkPosition {
    int x;
    int y;
};

class Chunk {
private:
    std::list<Entity*> entities = {};
    TileData tiles[CHUNK_SIZE][CHUNK_SIZE];
public:
    Chunk();
    void Update();
    void AddEntity(Entity* entity);
    void RemoveEntity(Entity* entity);
    [[nodiscard]] std::list<Entity*> GetEntities() const { return entities; }
    [[nodiscard]] TileData GetTile(int x, int y) const;
};

#endif //MYSTICFACTORIES_CHUNK_H
