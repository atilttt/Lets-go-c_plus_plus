#pragma once
#include <iostream>
using namespace std;

namespace CUSTOM
{ 
    class Figure // абстрактный класс для фигур на плоскости
    { 
        public:
            /**
             * @brief виртуальный метод для отрисовки фугуры (вывод информации о ней)
             */
            virtual void Draw() const = 0;

            /**
             * @brief виртуальный метод для строкового представления фигуры
             * @return строковое описание фигуры
             */
            virtual string ToString() const = 0; 

            /**
             * @brief виртуальный диструктор (по умолчанию)
             */
            virtual ~Figure() = default;
    };
}
