#include "Hexagon.h"
#include <iostream>
#include <cstdlib>

/**
 * @brief конструктор по умолчанию для class_hexagon
 * Инциализация центра, радиуса и точки на оркужности значениями по умолчанию
 */
Hexagon::Hexagon(): centere(), radius(0), random_point_on_circle() {}

/**
 * @brief функция для ввода данных
 */
void Hexagon::input()
{
    std::cout << "Center (x y): ";
    centere.input();

    std::cout << "Please enter radius circle: \n";
    std::cin >> radius;

    std::cout << "Enter a point on the circle(x y): \n";
    random_point_on_circle.input();

    if (!check())
    {
        std::cout << "the values are incorrect\n";
        std::exit(EXIT_FAILURE);
    }
}

/**
 * @brief функция, проверяющая корректность ввода данных
 * @return true - данные корректны, иначе false
 */
bool Hexagon::check() const
{
    if (radius <= 0)
    {
        std::cout << "The radius cannot be negative or zero.\n";
        return false;
    } 

    double distanceSquared = (random_point_on_circle.getX() - centere.getX()) * (random_point_on_circle.getX() - centere.getX()) + (random_point_on_circle.getY() - centere.getY()) * (random_point_on_circle.getY() - centere.getY());
    double radius_squared = radius * radius;

    if (std::abs(distanceSquared - radius_squared) > 1e-15)
    {
        std::cout << "The point does not lie on the circle.\n";
        return false;
    }

    return true;
}

/**
 * @brief Функция, рассчитывающая площадь шестиугольника
 * @return рассчитанная площадь шестиугольника
 */
double Hexagon::get_area() const
{
    return (3 * std::sqrt(3) * radius * radius) / (double)2;
}

/**
 * @brief Функция, как бы рассчитывающая длину стороны шестиугольника, но в окружность можно вписать только правильный шестиугольник
 * @return длину стороны шестиугольника
 */
double Hexagon::lenght_side() const
{
    return radius;
}

/**
 * @brief функция для вывода всей информации о шестиугольнике
 */
void Hexagon::print_info() const
{
    std::cout << "Centre: (" << centere.getX() << ", " << centere.getY() << ")\n";
    std::cout << "The radius of the circle: " << radius << "\n";
    std::cout << "Point on the circle: (" << random_point_on_circle.getX() << ", " << random_point_on_circle.getY() << ")\n";
    std::cout << "lenght side: " << lenght_side() << "\n";
    std::cout << "Area: " << get_area() << "\n";
}

