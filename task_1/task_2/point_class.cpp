#include "point_class.h"
#include <iostream>
#include <cmath>
#include <cstdlib>

/**
 * @brief Конструктор по умолчанию для класса Point.
 * Инициализирует координаты точки (0, 0).
 */
Point :: Point() : x(0), y(0) {}

/**
 * @brief Конструктор с параметрами для класса Point.
 * @param x Координата точки по оси абсцисс.
 * @param y Координата точки по оси ординат.
 */
Point::Point(const double x, const double y) : x(x), y(y) {}

/**
 * @brief Функция для ввода координат точки с клавиатуры.
 */
void Point::input()
{
    std::cout << "Please enter the coordinates of the point (x y): ";
    std::cin >> x >> y;
    check_input();
}

/**
 * @brief Функция для проверки корректности координат точки.
 * @return true, если координаты корректны, иначе false.
 */
void Point::check_input() const
{
    if (std::cin.fail())
    {
        std::cout << "Incorrect input\n";
        std::exit(EXIT_FAILURE);
    }   
}

/**
 * @brief позволяет обратится к переменной приватной переменной x
 * @return возвращает переменную x
 */
double Point::getX() const
{
    return x;
}

/**
 * @brief позволяет обратится к переменной приватной переменной y
 * @return возвращает переменную y
 */
double Point::getY() const
{
    return y;
}