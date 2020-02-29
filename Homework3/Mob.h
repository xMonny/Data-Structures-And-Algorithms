#pragma once
#include "Entity.h"

class Mob:public Entity
{
private:
    int damage;
    int health;

    virtual void setDamage(const int);
    virtual void setHealth(const int);

public:
    Mob();
    Mob(const Mob&);
    Mob(const std::string, const Point2D&, const int, const int);

    virtual bool isAlive() const;

    virtual int getDamage() const;
    virtual int getHealth() const;

    virtual Mob* clone() const
	{
        return new Mob(*this);
	}

    void attack(Entity&);

    virtual void print() const;
};
