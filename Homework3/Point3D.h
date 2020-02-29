#pragma once
#include "Point2D.h"

class Point3D:public Point2D
{
private:
    double z;
    void setZ(const double);

public:
    Point3D();
    Point3D(const double, const double, const double);

    virtual Point3D* clone() const
    {
        return new Point3D(*this);
    }

    virtual double getDistanceTo(const Point2D&) const;

    virtual double getZ() const;

    virtual void print() const;
};
