#ifndef CLASS_HEXAGON_H
#define CLASS_HEXAGON_H

#include "point_class.h"
#include <cmath>

class Hexagon {
    Point center;
    double radius;
    Point point_on_circle;
    
public:
    Hexagon(const Point& center, double radius, const Point& point_on_circle);
    
    double side_length() const;
    double area() const;
    void print_basic_info() const;
};

#endif