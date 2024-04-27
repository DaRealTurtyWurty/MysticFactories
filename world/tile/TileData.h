#ifndef MYSTICFACTORIES_TILEDATA_H
#define MYSTICFACTORIES_TILEDATA_H

#include <utility>

#include "TileType.h"

class TileData {
private:
    TileType type;
public:
    explicit TileData(TileType type) : type(std::move(type)) {}
    TileData() : type(EMPTY) {}

    [[nodiscard]] TileType GetType() const { return type; }
    [[nodiscard]] bool isEmpty() const { return type == EMPTY; }

    bool operator==(const TileData& other) const {
        return type == other.type;
    }

    virtual void Update() {
        // Do nothing
    }
};


#endif //MYSTICFACTORIES_TILEDATA_H
