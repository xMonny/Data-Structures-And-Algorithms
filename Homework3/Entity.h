#pragma once
#include <string>

enum class EntityType
{
    Player,
    NPC,
    Mob
};

static long number = 0;
class Entity
{
protected:
    unsigned long id;
    std::string name;
    Point2D* location = nullptr;

    void setID(const unsigned long);
    void setName(const std::string);

    EntityType entityType;

public:
    Entity();
    Entity(const Entity&);
    Entity& operator=(const Entity&);
    virtual ~Entity();

    Entity(const std::string, const Point2D&);

    void setEntityType(const EntityType ET)
    {
        entityType = ET;
    }

    EntityType getEntityType() const
    {
        return entityType;
    }

    std::string getName() const;
    unsigned long getID() const;

    virtual int getDamage() const=0;
    virtual int getHealth() const=0;
    virtual void setDamage(int)=0;
    virtual void setHealth(int)=0;

    void setLocation(const Point2D*);
    Point2D* getLocation() const;

    virtual bool isAlive() const;
    double getDistanceTo2D(const Entity&) const;
    double getDistanceTo(const Entity&) const;
    void moveTo(const Point2D&);
    void moveTo(const Entity&);

    virtual Entity* clone() const=0;

    virtual void print() const;
};

