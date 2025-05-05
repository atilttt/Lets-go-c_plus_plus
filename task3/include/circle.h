#pragma once

#include <iostream>
#include <string>

#include "figure.h"
#include "point.h" 

using namespace std;

namespace CUSTOM
{
    class Circle : public Figure // класс, который представляет круг на плоскости
    {
        private: 
            Point center; // центр окружности
            int radius; // радиус окружности
        public:
            /**
             * @brief конструктор через обьект класс
             * @param center - центр окружности
             * @param radius - радиус круга
             */
            Circle(const Point& center, int radius);

            /**
             * @brief конструктор через координаты 
             * @param x координата центра на оси абсцисс
             * @param y координата центра на оси ординат
             * @param radius радиус окружности
             */
            Circle(int x, int y, int radius);

            /**
             * @brief метод ToString для вывода информации об окружности
             */
            string ToString() const; // реализация виртуального метода

            /**
             * @brief виртуальный метод Draw для вывода информации
             */
            void Draw() const override; //реализация чисто виртуального метода
    };
} 

