#include <iostream>
#include "NPC.h"

void NPC::setDamage(const int newDamage)
{

}

int NPC::getDamage() const
{
    return 0;
}

void NPC::setHealth(const int newHealth)
{

}

int NPC::getHealth() const
{
    return 0;
}

NPC::NPC():Entity()
{
    setEntityType(EntityType::NPC);
}

NPC::NPC(const NPC &npc):Entity(npc)
{
    setEntityType(EntityType::NPC);
}

NPC::NPC(const std::string newName, const Point2D &newPoint):Entity(newName, newPoint)
{
    setEntityType(EntityType::NPC);
}

bool NPC::isAlive() const
{
    Entity::isAlive();
}

void NPC::print() const
{
    Entity::print();
    std::cout << "Type: NPC" << std::endl;
}
