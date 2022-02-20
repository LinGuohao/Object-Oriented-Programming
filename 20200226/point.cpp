#include <cmath>
#include "point.h"

Point::Point() {
    _x = 0;
    _y = 0;
}

Point::Point(double x, double y) {
    _x = x;
    _y = y;
}

double Point::getX() {
    return _x;
}

double Point::getY() {
    return _y;
}

void Point::setX(double x) {
    _x = x;
}

void Point::setY(double y) {
    _y = y;
}

double Point::distance( Point &p) {

//            return sqrt(pow(_x-p._x,2) + pow(_y-p._y,2));
            return sqrt(pow_x-p.getX(),2) + pow(_y-p.getY(),2));

}

