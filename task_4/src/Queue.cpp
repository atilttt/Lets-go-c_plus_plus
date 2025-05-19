#include "Queue.h"
#include <iostream>
#include <sstream>
#include <cstdlib>

PriorityDeque::PriorityDeque() : data(nullptr), count(0) {}

PriorityDeque::PriorityDeque(size_t maxSize) : data(nullptr), count(0) {
    if (maxSize == 0)
        error_message("Размер очереди должен быть положительным");
}

PriorityDeque::PriorityDeque(std::initializer_list<std::pair<size_t, size_t>> init) : data(nullptr), count(0) {
    for (const auto& item : init) {
        if (!isValidPriority(item.second))
            error_message("Недопустимый приоритет при инициализации: " + std::to_string(item.second));
        insert(item.first, item.second);
    }
}

PriorityDeque::PriorityDeque(const PriorityDeque& other) : count(other.count) {
    data = new std::pair<size_t, size_t>[count];
    for (size_t i = 0; i < count; ++i)
        data[i] = other.data[i];
}

PriorityDeque& PriorityDeque::operator=(const PriorityDeque& other) {
    if (this != &other) {
        delete[] data;
        count = other.count;
        data = new std::pair<size_t, size_t>[count];
        for (size_t i = 0; i < count; ++i)
            data[i] = other.data[i];
    }
    return *this;
}

PriorityDeque::PriorityDeque(PriorityDeque&& other)
    : data(other.data), count(other.count) {
    other.data = nullptr;
    other.count = 0;
}

PriorityDeque& PriorityDeque::operator=(PriorityDeque&& other) {
    if (this != &other) {
        delete[] data;
        data = other.data;
        count = other.count;
        other.data = nullptr;
        other.count = 0;
    }
    return *this;
}

PriorityDeque::~PriorityDeque() {
    delete[] data;
}

void PriorityDeque::error_message(const std::string& message) const {
    std::cerr << "Ошибка: " << message << std::endl;
    std::exit(EXIT_FAILURE);
}

bool PriorityDeque::isValidPriority(size_t priority) const {
    return priority >= MIN_PRIORITY && priority <= MAX_PRIORITY;
}

void PriorityDeque::insert(size_t value, size_t priority) {
    auto* new_data = new std::pair<size_t, size_t>[count + 1];

    size_t insert_index = 0;
    while (insert_index < count && data[insert_index].second <= priority)
        ++insert_index;

    for (size_t i = 0; i < insert_index; ++i)
        new_data[i] = data[i];

    new_data[insert_index] = {value, priority};
    for (size_t i = insert_index; i < count; ++i)
        new_data[i + 1] = data[i];

    delete[] data;
    data = new_data;
    ++count;
}

void PriorityDeque::push_front(size_t value, size_t priority) {
    insert(value, priority);
}

void PriorityDeque::push_back(size_t value, size_t priority) {
    insert(value, priority);
}

void PriorityDeque::pop_front() {
    if (count == 0)
        error_message("Очередь пуста (pop_front)");

    auto* new_data = new std::pair<size_t, size_t>[count - 1];
    for (size_t i = 1; i < count; ++i)
        new_data[i - 1] = data[i];

    delete[] data;
    data = new_data;
    --count;
}

void PriorityDeque::pop_back() {
    if (count == 0)
        error_message("Очередь пуста (pop_back)");

    auto* new_data = new std::pair<size_t, size_t>[count - 1];
    for (size_t i = 0; i < count - 1; ++i)
        new_data[i] = data[i];

    delete[] data;
    data = new_data;
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
    return data[0];
}

std::pair<size_t, size_t> PriorityDeque::get_maximum_priority() const {
    if (count == 0)
        error_message("Очередь пуста (get_maximum_priority)");
    return data[count - 1];
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
