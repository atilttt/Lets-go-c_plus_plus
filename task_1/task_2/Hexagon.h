#ifndef CLASS_HEXAGON_H
#define CLASS_HEXAGON_H

#include "point_class.h"
#include <cmath>

class Hexagon {
    private:
        Point centere;
        double radius = 0;
        Point random_point_on_circle;
        bool check() const;
    public:
        Hexagon();
        
        void input();
        void print_info() const;
        double lenght_side() const;
        double get_area() const;
};

#endif //CLASS_HEXAGON_H