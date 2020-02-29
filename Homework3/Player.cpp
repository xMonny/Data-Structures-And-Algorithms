#include <iostream>
#include "Player.h"

Player::Player():Entity()
{
    setDamage(0);
    setHealth(0);
    setEntityType(EntityType::Player);
}

Player::Player(const Player &player):Entity(player)
{
    setDamage(player.getDamage());
    setHealth(player.getHealth());
    setEntityType(EntityType::Player);
}

Player::Player(const std::string newName, const Point2D &newPoint, const int newDamage, const int newHealth):Entity(newName, newPoint)
{
    setDamage(newDamage);
    setHealth(newHealth);
    setEntityType(EntityType::Player);
}

bool Player::isAlive() const
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

void Player::setDamage(const int newDamage)
{
    damage = newDamage;
}

int Player::getDamage() const
{
    return damage;
}

void Player::setHealth(const int newHealth)
{
    health = newHealth;
}

int Player::getHealth() const
{
    return health;
}

void Player::attack(Entity &entity)
{
    if (entity.getEntityType() == EntityType::Player || entity.getEntityType() == EntityType::Mob)
    {
        if (this->getID() != entity.getID())
        {
            if (getDistanceTo(entity) < 5)
            {
                entity.setHealth(entity.getHealth() - this->getDamage());
            }
        }
   }
}

void Player::print() const
{
    Entity::print();
    std::cout << "Damage: " << getDamage() << std::endl;
    std::cout << "Health: " << getHealth() << std::endl;
    std::cout << "Type: Player" << std::endl;
}
