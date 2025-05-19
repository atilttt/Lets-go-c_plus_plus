#include "Queue.h"
#include <iostream>
#include <sstream>
#include <cstdlib>

PriorityDeque::PriorityDeque() : capacity(8), count(0) {
    data = new std::pair<size_t, size_t>[capacity];
}

PriorityDeque::PriorityDeque(size_t maxSize) : capacity(maxSize), count(0) {
    if (capacity == 0)
        error_message("Размер очереди должен быть положительным");
    data = new std::pair<size_t, size_t>[capacity];
}

PriorityDeque::PriorityDeque(std::initializer_list<std::pair<size_t, size_t>> init)
    : capacity(init.size() + 8), count(0) {
    data = new std::pair<size_t, size_t>[capacity];
    for (const auto& item : init) {
        if (!isValidPriority(item.second))
            error_message("Недопустимый приоритет при инициализации: " + std::to_string(item.second));
        data[count++] = item;
    }
}

void PriorityDeque::error_message(const std::string& message) const {
    std::cerr << "Ошибка: " << message << std::endl;
    std::exit(EXIT_FAILURE);
}

bool PriorityDeque::isValidPriority(size_t priority) const {
    return priority >= MIN_PRIORITY && priority <= MAX_PRIORITY;
}

void PriorityDeque::ensure_capacity() {
    if (count >= capacity) {
        size_t new_capacity = capacity * 2;
        auto* new_data = new std::pair<size_t, size_t>[new_capacity];
        for (size_t i = 0; i < count; ++i)
            new_data[i] = data[i];
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }
}

void PriorityDeque::shift_right() {
    for (size_t i = count; i > 0; --i)
        data[i] = data[i - 1];
}

void PriorityDeque::shift_left() {
    for (size_t i = 0; i < count - 1; ++i)
        data[i] = data[i + 1];
}


PriorityDeque::PriorityDeque(const PriorityDeque& other)
    : capacity(other.capacity), count(other.count) {
    data = new std::pair<size_t, size_t>[capacity];
    for (size_t i = 0; i < count; ++i)
        data[i] = other.data[i];
}

PriorityDeque& PriorityDeque::operator=(const PriorityDeque& other) {
    if (this != &other) {
        delete[] data;
        capacity = other.capacity;
        count = other.count;
        data = new std::pair<size_t, size_t>[capacity];
        for (size_t i = 0; i < count; ++i)
            data[i] = other.data[i];
    }
    return *this;
}

PriorityDeque::~PriorityDeque() {
    delete[] data;
}

void PriorityDeque::push_front(size_t value, size_t priority) {
    if (!isValidPriority(priority))
        error_message("Недопустимый приоритет в push_front");
    ensure_capacity();
    shift_right();
    data[0] = {value, priority};
    ++count;
}

void PriorityDeque::push_back(size_t value, size_t priority) {
    if (!isValidPriority(priority))
        error_message("Недопустимый приоритет в push_back");
    ensure_capacity();
    data[count++] = {value, priority};
}

void PriorityDeque::pop_front() {
    if (count == 0)
        error_message("Очередь пуста (pop_front)");
    shift_left();
    --count;
}

void PriorityDeque::pop_back() {
    if (count == 0)
        error_message("Очередь пуста (pop_back)");
    --count;
}

bool PriorityDeque::isEmpty() const {
    return count == 0;
}

size_t PriorityDeque::size() const {
    return count;
}

std::pair<size_t, size_t> PriorityDeque::get_minimal_priority() const {
    if (count == 0)
        error_message("Очередь пуста (get_minimal_priority)");
    auto min = data[0];
    for (size_t i = 1; i < count; ++i)
        if (data[i].second < min.second)
            min = data[i];
    return min;
}

std::pair<size_t, size_t> PriorityDeque::get_maximum_priority() const {
    if (count == 0)
        error_message("Очередь пуста (get_maximum_priority)");
    auto max = data[0];
    for (size_t i = 1; i < count; ++i)
        if (data[i].second > max.second)
            max = data[i];
    return max;
}

std::string PriorityDeque::toString() const {
    std::ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < count; ++i) {
        oss << "(" << data[i].first << ", pr=" << data[i].second << ")";
        if (i < count - 1)
            oss << ", ";
    }
    oss << "]";
    return oss.str();
}
