#ifndef MYSTICFACTORIES_PLAYER_H
#define MYSTICFACTORIES_PLAYER_H

#include "Entity.h"

class Player : public Entity {

public:
    Player(std::uint32_t health, std::uint32_t maxHealth, int xPos, int yPos);
};

#endif //MYSTICFACTORIES_PLAYER_H
