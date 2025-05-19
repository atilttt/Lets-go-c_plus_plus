#pragma once

#include <utility>
#include <string>
#include <cstddef>

const size_t MIN_PRIORITY = 0;
const size_t MAX_PRIORITY = 1000;

class PriorityDeque {
    private:
        std::pair<size_t, size_t>* data; 
        size_t capacity;                  
        size_t count;                     

        /**
        * @brief Выводит сообщение об ошибке и завершает программу.
        * @param message Текст ошибки.
        */
        void error_message(const std::string& message) const;

        /**
        * @brief Проверяет допустимость значения приоритета.
        * @param priority Приоритет элемента.
        * @return true, если приоритет допустим.
        */
        bool isValidPriority(size_t priority) const;

        /**
        * @brief Увеличивает вместимость массива вдвое при необходимости.
        */
        void ensure_capacity();

        /**
        * @brief Сдвигает все элементы массива вправо на одну позицию.
        */
        void shift_right();

        /**
        * @brief Сдвигает все элементы массива влево на одну позицию.
        */
        void shift_left();

    public:
        /**
        * @brief Конструктор по умолчанию. Выделяет память на 8 элементов.
        */
        PriorityDeque();

        /**
        * @brief Конструктор с заданным максимальным размером.
        * @param maxSize Максимальная вместимость очереди.
        */
        explicit PriorityDeque(size_t maxSize);

        /**
        * @brief Конструктор со списком инициализации.
        * @param init Список пар (значение, приоритет).
        */
        PriorityDeque(std::initializer_list<std::pair<size_t, size_t>> init);

        /**
        * @brief Конструктор копирования.
        * @param other Другой объект PriorityDeque.
        */
        PriorityDeque(const PriorityDeque& other);

        /**
        * @brief Оператор присваивания.
        * @param other Другой объект PriorityDeque.
        * @return Ссылка на текущий объект.
        */
        PriorityDeque& operator=(const PriorityDeque& other);

        /**
        * @brief Деструктор. Освобождает динамическую память.
        */
        ~PriorityDeque();

        /**
        * @brief Вставляет элемент в начало очереди.
        * @param value Значение элемента.
        * @param priority Приоритет элемента.
        */
        void push_front(size_t value, size_t priority);

        /**
        * @brief Вставляет элемент в конец очереди.
        * @param value Значение элемента.
        * @param priority Приоритет элемента.
        */
        void push_back(size_t value, size_t priority);

        /**
        * @brief Удаляет элемент из начала очереди.
        */
        void pop_front();

        /**
        * @brief Удаляет элемент из конца очереди.
        */
        void pop_back();

        /**
        * @brief Проверяет, пуста ли очередь.
        * @return true, если очередь пуста.
        */
        bool isEmpty() const;

        /**
        * @brief Возвращает количество элементов в очереди.
        * @return Количество элементов.
        */
        size_t size() const;

        /**
        * @brief Находит элемент с минимальным приоритетом.
        * @return Пара (значение, приоритет) с минимальным приоритетом.
        */
        std::pair<size_t, size_t> get_minimal_priority() const;

        /**
        * @brief Находит элемент с максимальным приоритетом.
        * @return Пара (значение, приоритет) с максимальным приоритетом.
        */
        std::pair<size_t, size_t> get_maximum_priority() const;

        /**
        * @brief Возвращает строковое представление очереди.
        * @return Строка формата [(значение, pr=приоритет), ...]
        */
        std::string toString() const;
};