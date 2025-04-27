#pragma once
#include <iostream>
using namespace std;

namespace CUSTOM
{ 
    class Point // класс представляющий точку на плоскости
    {
        private:
            unsigned int x;
            unsigned int y;
        public:
            /**
            * @brief Конструктор точки
            * @param x Координата X (по умолчанию 0)
            * @param y Координата Y (по умолчанию 0)
            */
        Point(unsigned int x = 0, unsigned int y = 0);
    
        static unsigned int max_x; ///< Максимальное значение X
        static unsigned int max_y; ///< Максимальное значение Y
    
         /**
        * @brief Получение координаты X
        * @return Значение координаты X
         */
        unsigned int get_x() const;
    
        /**
        * @brief Получение координаты Y
        * @return Значение координаты Y
        */
        unsigned int get_y() const;
    };

}