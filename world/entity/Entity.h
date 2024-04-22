#ifndef MYSTICFACTORIES_ENTITY_H
#define MYSTICFACTORIES_ENTITY_H

#include <cstdint>

class Entity {
private:
    std::uint32_t health;
    std::uint32_t maxHealth;
    int xPos;
    int yPos;
public:
    Entity(std::uint32_t health, std::uint32_t maxHealth, int xPos, int yPos);
    ~Entity();
    virtual void Update();
    virtual void Move(int x, int y);
    virtual void Damage(std::uint32_t damage);
    virtual void Heal(std::uint32_t heal);
    virtual void SetPosition(int x, int y);
    [[nodiscard]] std::uint32_t GetHealth() const;
    [[nodiscard]] std::uint32_t GetMaxHealth() const;
    [[nodiscard]] int GetXPos() const;
    [[nodiscard]] int GetYPos() const;

    virtual bool IsDead();
};


#endif //MYSTICFACTORIES_ENTITY_H
