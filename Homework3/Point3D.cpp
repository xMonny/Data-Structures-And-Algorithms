#include <iostream>
#include <cmath>
#include "Point3D.h"

Point3D::Point3D():Point2D()
{
    setZ(0);
}

Point3D::Point3D(const double newX, const double newY, const double newZ):Point2D(newX, newY)
{
    setZ(newZ);
}

double Point3D::getDistanceTo(const Point2D &point3D) const
{
    try
    {
        auto newPoint3D = dynamic_cast<const Point3D&>(point3D);
        double distance;
        double newX;
        double newY;
        double newZ;

        newX = point3D.getX()-getX();
        newY = point3D.getY()-getY();
        newZ = point3D.getZ()-getZ();

        distance = sqrt(newX*newX + newY*newY + newZ*newZ);
        return distance;
    }

    catch(...)
    {
        return Point2D::getDistanceTo(point3D);
    }
}

void Point3D::setZ(const double newZ)
{
    z = newZ;
}

double Point3D::getZ() const
{
    return z;
}

void Point3D::print() const
{
    Point2D::print();
    std::cout << "z: " << getZ() << std::endl;
}
