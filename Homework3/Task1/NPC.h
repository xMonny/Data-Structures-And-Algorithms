#pragma once
#include "Entity.h"

class NPC:public Entity
{
private:
    virtual void setDamage(const int);
    virtual void setHealth(const int);
    virtual int getDamage() const;
    virtual int getHealth() const;

public:
    NPC();
    NPC(const NPC&);
    NPC(const std::string, const Point2D&);

    virtual bool isAlive() const;

    virtual NPC* clone() const
	{
        return new NPC(*this);
	}

    virtual void print() const;
};
