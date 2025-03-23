#include "Hexagon.h"
#include <iostream>

/**
 * @brief точка входа в программу
 * @return 0 в случае успеха
 */
int main(void)
{
    Hexagon hex;

    std::cout << "Please enter the data for the hexagon: \n";
    hex.input();

    std::cout << "\nThis is information about hexagon\n";
    hex.print_info();

    return 0;
}