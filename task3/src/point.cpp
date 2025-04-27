#include "point.h"

namespace CUSTOM
{
    unsigned int Point :: max_x  = 0;
    unsigned int Point :: max_y = 0;

    Point::Point(unsigned int x, unsigned int y): x(x), y(y) {
        if (x > max_x || y > max_y) {
            throw("Error! From the point of the problem");
        }
    }

    unsigned int Point::get_x() const { return x; }
    unsigned int Point::get_y() const { return y; }
}