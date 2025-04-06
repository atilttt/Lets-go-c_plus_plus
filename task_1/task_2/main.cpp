#include "Hexagon.h"
#include <iostream>
#include <cstdlib>

/**
 * @brief Считывает числовое значение с проверкой ввода.
 * @param prompt Приглашение для ввода.
 * @return Считанное значение, если все введено корректно, иначе закрывает программу.
 */
double getValue(const std::string& prompt);

/**
 * @brief Считывает координаты точки.
 * @param prompt Приглашение для ввода.
 * @return Объект Point с введёнными координатами.
 */
Point getPoint(const std::string& prompt);

/**
 * @brief Создаёт шестиугольник по введённым данным.
 * @return Объект Hexagon.
 * @note Включает проверку радиуса на положительность.
 */
Hexagon getHexagon();

/**
 * @brief Точка входа в программу.
 * @return 0 при успешном выполнении.
 */
int main() {
    Hexagon hex = getHexagon();
    
    std::cout << "\nHexagon info:\n";
    hex.print_basic_info();
    
    std::cout << "\nCalculated properties:\n";
    std::cout << "Side length: " << hex.side_length() << "\n";
    std::cout << "Area: " << hex.area() << "\n";

    return 0;
}

double getValue(const std::string& prompt) {
    double value;
    std::cout << prompt;
    if (!(std::cin >> value)) {
        std::cerr << "Invalid input\n";
        exit(EXIT_FAILURE);
    }
    return value;
}


Point getPoint(const std::string& prompt) {
    std::cout << prompt;
    double x = getValue("x: ");
    double y = getValue("y: ");
    return Point(x, y);
}

Hexagon getHexagon() {
    Point center = getPoint("Enter center point:\n");
    double radius = getValue("Enter radius: ");
    Point point = getPoint("Enter point on circle:\n");
    return Hexagon(center, radius, point);
}