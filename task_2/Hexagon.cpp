#include "Hexagon.h"
#include <iostream>
#include <cmath>
#include <limits>
#include <cstdlib>

/**
 * @brief Конструктор для класса Hexagon.
 * @param center Центр описанной окружности.
 * @param radius Радиус описанной окружности (должен быть положительным).
 * @param point_on_circle Точка на окружности (должна лежать на окружности).
 * @note Завершает программу при некорректных данных.
 */
Hexagon::Hexagon(const Point& center, double radius, const Point& point_on_circle)
    : center(center), radius(radius), point_on_circle(point_on_circle) 
{
    if (radius <= 0) {
        std::cerr << "Error: Radius must be positive\n";
        exit(EXIT_FAILURE);
    }

    double dx = point_on_circle.getX() - center.getX();
    double dy = point_on_circle.getY() - center.getY();
    double distance_squared = dx*dx + dy*dy;
    double radius_squared = radius * radius;

    if (std::abs(distance_squared - radius_squared) > std::numeric_limits<double>::epsilon()) {
        std::cerr << "Error: Point does not lie on the circle\n";
        exit(EXIT_FAILURE);
    }
}

/**
 * @brief Выводит основную информацию о шестиугольнике.
 * @details Формат вывода:
 * - Координаты центра
 * - Радиус описанной окружности
 * - Координаты точки на окружности
 */
void Hexagon::print_basic_info() const {
    std::cout << "Center: (" << center.getX() << ", " << center.getY() << ")\n";
    std::cout << "Radius: " << radius << "\n";
    std::cout << "Point on circle: (" << point_on_circle.getX() 
              << ", " << point_on_circle.getY() << ")\n";
}

/**
 * @brief Вычисляет площадь правильного шестиугольника.
 * @return Площадь шестиугольника.
 */
double Hexagon::area() const {
    return (3 * std::sqrt(3) * radius * radius) / 2.0;
}

/**
 * @brief Получает длину стороны шестиугольника.
 * @return Длина стороны (равна радиусу описанной окружности).
 */
double Hexagon::side_length() const {
    return radius;
}