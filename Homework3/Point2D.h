#pragma once

class Point2D
{
private:
    double x;
    double y;

    void setX(const double);
    void setY(const double);

public:
    Point2D();
    Point2D(const double, const double);
    virtual ~Point2D();

    virtual Point2D* clone() const
    {
        return new Point2D(*this);
    }

    virtual bool checkFor3D() const;

    virtual double getDistanceTo(const Point2D&) const;

    double getX() const;
    double getY() const;
    virtual double getZ() const;

    virtual void print() const;
};
