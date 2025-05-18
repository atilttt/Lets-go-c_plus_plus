#pragma once

#include <deque>
#include <iostream>
#include <string>
#include <utility>
#include <cstdlib>
#include <initializer_list>

const int MIN_PRIORITY = 0;
const int MAX_PRIORITY = 1000;

/**
 * @class PriorityDeque - очередь с приоритетом и двусторонним доступом. Элементы представляются парой.
 * Позволяет добавлять с обеих концов.
 * Элементы можно удалять, а также находить элементы с наимешньшим и наибольшим приоритетом
 */
class PriorityDeque
{
    private:
        std::deque<std::pair<int, int>> data;

        /**
         * @brief функция, завершающая программу и выводящаяя ошибку
         */
        void error_message(const std::string &message) const;

        /**
         * @brief проверка допустимость приоритета
         */
        bool isValidPriority(int priority) const;
    public:
        /**
         * @brief конструктор по умолчанию
         */
        PriorityDeque();

        /**
         * @brief конструктор копирования
         * @param other другой объект PriorityDeque для копирования
         */
        PriorityDeque(const PriorityDeque& other);

        /**
         * @brief конструктор со списком инициализации
         * @param init список пар (значение, приоритет)
         */
        PriorityDeque(std::initializer_list<std::pair<int, int>> init);

        /**
         * @brief оператор присваивания копированием
         * @param other другой объект PriorityDeque для копирования
         */
        PriorityDeque& operator=(const PriorityDeque& other) noexcept;
        
        /**
         * @brief диструктор по умолчанию
         */
        ~PriorityDeque();

        /**
         * @brief вставка элемента в начало
         * @param value значение элемента
         * @param priority приоритет элемента
         * @return завершает программу, если приоритет недопустим
         */
        void push_front(int value, int priority);
        
        /**
         * @brief вставка элемента в конец
         * @param value значение элемента 
         * @param priority приоритет элимента
         * @return завершает программу, если приоритет недопустим
         */
        void push_back(int value, int priority);

        /**
         * @brief удаляет элемент с начала
         */
        void pop_front();

        /**
         * @brief удаляет элемент с конца
         */
        void pop_back();

        /**
         * @brief функция, проверяещую очередь на пустоту
         * @return false - очередь не пуста, true - очередь пустая 
         */
        bool isEmpty() const;

        /**
         * @brief функция, возвращающая количество элементов в очереди
         */
        int size() const;

        /**
         * @brief функция, которая находит элемент с минимальным приоритетом
         * @return пару (значение, приоритет)
         */
        std::pair<int, int> get_minimal_priority() const;
        
        /**
         * @brief функция, которая находит элемент с максимальным приоритетом
         * @return пару (значение, приоритет)
         */
        std::pair<int, int> get_maximum_priority() const;

        /**
         * @brief строковое представление очереди
         */
        std::string toString() const;
};