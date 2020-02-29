#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <vector>
#include "Environment.h"

void Environment::add(Entity& entity)
{
    entities.push_back(entity.clone());
}

Entity* Environment::getAt(const int index) const
{
    if (index > entities.size())
    {
        return nullptr;
    }

    return entities[index];
}

void Environment::removeAt(const int index)
{
    if (index < entities.size())
    {
        entities.erase(entities.begin()+index);
    }
}

void Environment::generateEntities()
{
    srand(time(NULL));
    double xRandom1 = rand()%15;
    double yRandom1 = rand()%15;
    int damageRandom1 = rand()%100;
    int healthRandom1 = rand()%200;

    Point2D point1(xRandom1, yRandom1);

    double xRandom2 = rand()%15;
    double yRandom2 = rand()%15;
    int damageRandom2 = rand()%100;
    int healthRandom2 = rand()%200;

    Point2D point2(xRandom2, yRandom2);

    double xRandom3 = rand()%15;
    double yRandom3 = rand()%15;

    Point2D point3(xRandom3, yRandom3);

    Player player("New player", point1, damageRandom1, healthRandom1);

    Mob mob("New mob", point2, damageRandom2, healthRandom2);

    NPC npc("New npc", point3);

    add(player);
    add(mob);
    add(npc);
}

void Environment::destroyEntities()
{
    for (int i = 0; i < entities.size(); i++)
    {
        delete entities[i];
    }
    entities.clear();
}

Entity* Environment::getClosestAliveEntity(const Entity& player, const EntityType ET)
{
    if (player.getEntityType() == EntityType::Player)
    {
        int position = -1;
        double distance = -1;
        for (int i = 0; i < entities.size(); i++)
        {
            if (entities[i]->getEntityType() == ET && player.getID() != entities[i]->getID() && entities[i]->isAlive() == true)
            {
                if (distance == -1)
                {
                    distance = entities[i]->getDistanceTo(player);
                    position = i;
                }

                else
                {
                    if (entities[i]->getDistanceTo(player) <= distance)
                    {
                        distance = entities[i]->getDistanceTo(player);
                        position = i;
                    }
                }
            }
        }

        if (position == -1)
        {
            return nullptr;
        }

        return entities[position];
    }
}

int Environment::getSize() const
{
    return entities.size();
}

void Environment::print() const
{
    if (entities.size() == 0)
    {
        std::cout << "There are no elements to print." << std::endl;
    }

    else
    {
        for (int i = 0; i < entities.size(); i++)
        {
            entities[i]->print();
            std::cout << std::endl;
        }
    }
}
