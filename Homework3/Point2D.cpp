#include <iostream>
#include <cmath>
#include "Point2D.h"

Point2D::Point2D()
{
    setX(0);
    setY(0);
}

Point2D::Point2D(const double newX, const double newY)
{
    setX(newX);
    setY(newY);
}

bool Point2D::checkFor3D() const
{
    return false;
}

double Point2D::getZ() const
{
    return 0.0;
}

double Point2D::getDistanceTo(const Point2D &point2D) const
{
    double distance;
    double newX;
    double newY;

    newX = getX() - point2D.getX();
    newY = getY() - point2D.getY();

    distance = sqrt(newX*newX + newY*newY);
    return distance;
}

void Point2D::setX(const double newX)
{
    x = newX;
}

double Point2D::getX() const
{
    return x;
}

void Point2D::setY(const double newY)
{
    y = newY;
}

double Point2D::getY() const
{
    return y;
}

void Point2D::print() const
{
    std::cout << "x: " << getX() << std::endl;
    std::cout << "y: " << getY() << std::endl;
}

Point2D::~Point2D()
{

}
