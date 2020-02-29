#include <iostream>
#include <cmath>
#include <string>
#include "Entity.h"

Entity::Entity()
{
    setID(number+1);
    setName("New");
    setLocation(nullptr);
    number++;
}

Entity::Entity(const std::string newName, const Point2D &newPoint)
{
    setID(number+1);
    setName(newName);
    setLocation(&newPoint);
    number++;
}

Entity::Entity(const Entity &entity)
{
    setID(number+1);
    *this = entity;
    number++;
}

Entity& Entity::operator=(const Entity &entity)
{
    if (this != &entity)
    {
        setName(entity.getName());
        setLocation(entity.getLocation());
    }
    return *this;
}

Entity::~Entity()
{
    delete location;
}

void Entity::setLocation(const Point2D* newLocation)
{
    if (newLocation == nullptr)
    {
        delete location;
        location = nullptr;
        return;
    }
    delete location;
    location = newLocation->clone();
}

Point2D* Entity::getLocation() const
{
    return location;
}

bool Entity::isAlive() const
{
    return true;
}

void Entity::setID(const unsigned long newID)
{
    id = newID;
}

unsigned long Entity::getID() const
{
    return id;
}

void Entity::setName(const std::string newName)
{
    name = newName;
}

std::string Entity::getName() const
{
    return name;
}

double Entity::getDistanceTo2D(const Entity &entity) const
{
    return getLocation()->Point2D::getDistanceTo(*entity.getLocation());
}

double Entity::getDistanceTo(const Entity &entity) const
{
    if (dynamic_cast<Point3D*>(this->getLocation()) != nullptr && dynamic_cast<Point3D*>(entity.getLocation()) != nullptr)//if both are Point3D
    {
        return getLocation()->getDistanceTo(*entity.getLocation());
    }
    return getLocation()->Point2D::getDistanceTo(*entity.getLocation());
}

void Entity::moveTo(const Point2D &object)
{
    setLocation(&object);
}

void Entity::moveTo(const Entity &entity)
{
    if (entity.getLocation() != getLocation())
    {
        setLocation(entity.getLocation());
    }
}

void Entity::print() const
{
    std::cout << "ID: " << getID() << std::endl;
    std::cout << "Name: " << getName() << std::endl;
    if (getLocation() != nullptr)
    {
        getLocation()->print();
    }
}
