#include "../include/circle.h"
using namespace CUSTOM;

/**
 * @brief Функция для создания круга с пользовательским вводом
 * @return объект класса Circle
 */
Circle fill_circle();

/**
 * @brief Точка входа в программу
 * @return 0 при успешном завершении
 */
int main() {
    try {
        Circle circle = fill_circle();
        circle.Draw();
    }
    catch (const exception& ex) {
        cerr << "Ошибка: " << ex.what() << endl;
    }
    catch (...) {
        cerr << "Неизвестная ошибка." << endl;
    }

    return 0;
}

Circle fill_circle() {
    while (true) {
        try {
            cout << "Введите максимальное разрешение экрана:" << endl;
            cout << "Max X: ";
            cin >> Point::max_x;
            cout << "Max Y: ";
            cin >> Point::max_y;

            enum Mode { SEPARATE = 1, SINGLE_LINE = 2 };
            int mode;
            cout << "\nВыберите способ ввода центра круга:\n";
            cout << SEPARATE << ". Вводить X и Y отдельно\n";
            cout << SINGLE_LINE << ". Вводить X и Y вместе\n> ";
            cin >> mode;

            int x, y, radius;

            switch (mode) {
                case SEPARATE: {
                    cout << "\nВведите координату X центра: ";
                    cin >> x;
                    cout << "Введите координату Y центра: ";
                    cin >> y;
                    cout << "Введите радиус круга: ";
                    cin >> radius;
                    break;
                }
                case SINGLE_LINE: {
                    cout << "\nВведите координаты центра и радиус через пробел (X Y Radius): ";
                    cin >> x >> y >> radius;
                    break;
                }
                default:
                    throw invalid_argument("Неверный режим ввода.");
            }

            if (x > Point::max_x || y > Point::max_y) {
                throw out_of_range("Координаты центра превышают разрешение экрана.");
            }
            if (radius == 0) {
                throw invalid_argument("Радиус должен быть положительным числом.");
            }

            Point center(x, y);
            return Circle(center, radius);
        }
        catch (const exception& ex) {
            cerr << "Ошибка: " << ex.what() << endl;
            cout << "Попробуйте снова.\n\n";
        }
    }
}
