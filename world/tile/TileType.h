#ifndef MYSTICFACTORIES_TILETYPE_H
#define MYSTICFACTORIES_TILETYPE_H

#include <string>

class TileType {
private:
    std::string name;
    bool isSolid;
public:
    TileType(std::string name, bool isSolid) : name(std::move(name)), isSolid(isSolid) {}

    [[nodiscard]] const std::string& GetName() const { return name; }
    [[nodiscard]] bool IsSolid() const { return isSolid; }

    bool operator==(const TileType& other) const {
        return name == other.name && isSolid == other.isSolid;
    }

    static const TileType &EMPTY;
};


#endif //MYSTICFACTORIES_TILETYPE_H
