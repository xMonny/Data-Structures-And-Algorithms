#pragma once
#include <string>
#include <vector>

class Environment
{
private:
    std::vector<Entity*> entities;

public:
    void add(Entity&);
    Entity* getAt(const int) const;
    void removeAt(const int);
    void generateEntities();
    void destroyEntities();
    Entity* getClosestAliveEntity(const Entity&, const EntityType);

    int getSize() const;

    void print() const;
};
