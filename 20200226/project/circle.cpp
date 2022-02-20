#include <math.h>
#include "circle.h"
#include "point.h"

Circle::Circle(Point cp, double r) {
    _centralPoint = cp;
    _radius = r;
}

double Circle::area() {
    return _radius*_radius*M_PI;
}

bool Circle::isInside(Point p) {
    return _centralPoint.distance(p) < _radius;
}
