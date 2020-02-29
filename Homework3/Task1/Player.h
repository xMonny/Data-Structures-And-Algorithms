#pragma once
#include "Entity.h"

class Player:public Entity
{
private:
    int damage;
    int health;

    virtual void setDamage(const int);
    virtual void setHealth(const int);

public:
    Player();
    Player(const Player&);
    Player(const std::string, const Point2D&, const int, const int);

    virtual int getDamage() const;
    virtual int getHealth() const;

    virtual bool isAlive() const;

    virtual Player* clone() const
	{
        return new Player(*this);
	}

    void attack(Entity&);

    virtual void print() const;
};
