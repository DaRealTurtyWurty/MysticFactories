#include <cstdlib>
#include "Entity.h"

Entity::Entity(std::uint32_t health, std::uint32_t maxHealth, int xPos, int yPos) :
health(health), maxHealth(maxHealth), xPos(xPos), yPos(yPos) {}

Entity::~Entity() = default;

void Entity::Update() {}

void Entity::Move(int x, int y) {
    xPos = x;
    yPos = y;
}

void Entity::Damage(std::uint32_t damage) {
    health -= damage;
}

void Entity::Heal(std::uint32_t heal) {
    health += heal;
}

void Entity::SetPosition(int x, int y) {
    xPos = x;
    yPos = y;
}

std::uint32_t Entity::GetHealth() const {
    return health;
}

std::uint32_t Entity::GetMaxHealth() const {
    return maxHealth;
}

int Entity::GetXPos() const {
    return xPos;
}

int Entity::GetYPos() const {
    return yPos;
}

bool Entity::IsDead() {
    return health <= 0;
}

int Entity::DistanceTo(int x, int y) const {
    return abs(xPos - x) + abs(yPos - y);
}
