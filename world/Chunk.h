#ifndef MYSTICFACTORIES_CHUNK_H
#define MYSTICFACTORIES_CHUNK_H

#include <list>
#include <array>
#include "entity/Entity.h"
#include "tile/TileData.h"
#include "../Constants.h"

struct ChunkPosition {
    int x;
    int y;

    bool operator==(const ChunkPosition& other) const {
        return x == other.x && y == other.y;
    }

    bool operator!=(const ChunkPosition& other) const {
        return !(*this == other);
    }

    bool operator<(const ChunkPosition& other) const {
        return x < other.x || (x == other.x && y < other.y);
    }

    bool operator>(const ChunkPosition& other) const {
        return x > other.x || (x == other.x && y > other.y);
    }

    bool operator<=(const ChunkPosition& other) const {
        return *this < other || *this == other;
    }

    bool operator>=(const ChunkPosition& other) const {
        return *this > other || *this == other;
    }

    ChunkPosition operator+(const ChunkPosition& other) const {
        return {x + other.x, y + other.y};
    }

    ChunkPosition operator-(const ChunkPosition& other) const {
        return {x - other.x, y - other.y};
    }

    ChunkPosition operator*(const ChunkPosition& other) const {
        return {x * other.x, y * other.y};
    }

    ChunkPosition operator/(const ChunkPosition& other) const {
        return {x / other.x, y / other.y};
    }

    ChunkPosition operator%(const ChunkPosition& other) const {
        return {x % other.x, y % other.y};
    }
};

class Chunk {
private:
    std::list<Entity*> entities = {};
    std::array<TileData, CHUNK_SIZE * CHUNK_SIZE> tiles;
public:
    Chunk();
    void Update();
    void AddEntity(Entity* entity);
    void RemoveEntity(Entity* entity);
    [[nodiscard]] std::list<Entity*> GetEntities() const { return entities; }
    [[nodiscard]] TileData GetTile(int x, int y) const;

    [[nodiscard]] static int GetXWorldSpace(int x) ;
    [[nodiscard]] static int GetYWorldSpace(int y) ;
};

#endif //MYSTICFACTORIES_CHUNK_H
