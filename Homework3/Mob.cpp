#include <iostream>
#include "Mob.h"

Mob::Mob()
{
    setDamage(0);
    setHealth(0);
    setEntityType(EntityType::Mob);
}

Mob::Mob(const Mob &mob):Entity(mob)
{
    setDamage(mob.getDamage());
    setHealth(mob.getHealth());
    setEntityType(EntityType::Mob);
}

Mob::Mob(const std::string newName, const Point2D &newPoint, const int newDamage, const int newHealth):Entity(newName, newPoint)
{
    setDamage(newDamage);
    setHealth(newHealth);
    setEntityType(EntityType::Mob);
}

bool Mob::isAlive() const
{
   if (getHealth() > 0)
   {
       return true;
   }
   else
   {
       return false;
   }
}

void Mob::setDamage(const int newDamage)
{
    damage = newDamage;
}

int Mob::getDamage() const
{
    return damage;
}

void Mob::setHealth(const int newHealth)
{
    health = newHealth;
}

int Mob::getHealth() const
{
    return health;
}

void Mob::attack(Entity &entity)
{
    if (entity.getEntityType() == EntityType::Player)
    {
        if (this->Entity::getID() != entity.Entity::getID())
        {
            if (getDistanceTo(entity) < 5)
            {
                entity.setHealth(entity.getHealth() - this->getDamage());
            }
        }
   }
}

void Mob::print() const
{
    Entity::print();
    std::cout << "Damage: " << getDamage() << std::endl;
    std::cout << "Health: " << getHealth() << std::endl;
    std::cout << "Type: Mob" << std::endl;
}
