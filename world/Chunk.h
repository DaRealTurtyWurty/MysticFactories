#ifndef MYSTICFACTORIES_CHUNK_H
#define MYSTICFACTORIES_CHUNK_H

#include <list>
#include "entity/Entity.h"

struct ChunkPosition {
    int x;
    int y;
};

class Chunk {
private:
    std::list<Entity*> entities{};
public:
    void Update();
    void AddEntity(Entity* entity);
    void RemoveEntity(Entity* entity);
    std::list<Entity*> GetEntities();

    const static int CHUNK_SIZE = 16;
};

#endif //MYSTICFACTORIES_CHUNK_H
