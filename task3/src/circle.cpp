#include "../include/circle.h"
#include <string>

namespace CUSTOM
{
    Circle::Circle(const Point& center, int radius) : center(center), radius(radius)
    {
        if (radius <= 0)
        {
            throw invalid_argument("Ошибка создания круга: радиус должен быть положительным.");
        }
    }

    Circle::Circle(int x, int y, int radius)
        : center(Point(x, y)), radius(radius)
    {
        if (radius <= 0)
        {
            throw invalid_argument("Ошибка создания круга: радиус должен быть положительным.");
        }
    }

    string Circle::ToString() const
    {
        return "Circle: {center(" + to_string(center.get_x()) + "," + to_string(center.get_y()) + "), Radius(" + to_string(radius) + ")}";
    }

    void Circle::Draw() const
    {
        cout << ToString() << endl;
    }
}
