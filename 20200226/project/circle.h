#ifndef CIRCLE_H
#define CIRCLE_H
#include "point.h"

class Circle {

private:
    Point _centralPoint;
    double _radius;

public:
    Circle(Point cp, double r);
    double area();
    bool isInside(Point p);
    Point getCentralPoint()  { return _centralPoint; }
    void setCentralPoint(Point cp) { _centralPoint = cp; }
    double getRadius() { return _radius; }
    void setRadius(double r) { _radius = r; }
};
#endif //CIRCLE_H
