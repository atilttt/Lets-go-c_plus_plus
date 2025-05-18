#include "Queue.h"
#include <sstream>
#include <utility>

void PriorityDeque::error_message(const std::string& message) const {
    std::cerr << "Ошибка: " << message << std::endl;
    std::exit(EXIT_FAILURE);
}

bool PriorityDeque::isValidPriority(int priority) const {
    return priority >= MIN_PRIORITY && priority <= MAX_PRIORITY;
}

PriorityDeque::PriorityDeque() = default;

PriorityDeque::PriorityDeque(const PriorityDeque& other) : data(other.data) {};

PriorityDeque& PriorityDeque::operator=(const PriorityDeque& other) {
    if (this != &other) {
        data = other.data;
    }
    return *this;
}

PriorityDeque::PriorityDeque(std::initializer_list<std::pair<int, int>> init) {
    for (const auto& item : init) {
        if (!isValidPriority(item.second)) {
            error_message("Недопустимый приоритет при инициализации: " + std::to_string(item.second));
        }
    }
    data = init;
}

void PriorityDeque::push_front(int value, int priority) {
    if (!isValidPriority(priority))
        error_message("Недопустимый приоритет в push_front: " + std::to_string(priority));
    data.push_front({value, priority});
}

void PriorityDeque::push_back(int value, int priority) {
    if (!isValidPriority(priority))
        error_message("Недопустимый приоритет в push_back: " + std::to_string(priority));
    data.push_back({value, priority});
}

void PriorityDeque::pop_front() {
    if (data.empty())
        error_message("Очередь пуста (pop_front)");
    data.pop_front();
}

void PriorityDeque::pop_back() {
    if (data.empty())
        error_message("Очередь пуста (pop_back)");
    data.pop_back();
}

bool PriorityDeque::isEmpty() const {
    return data.empty();
}

int PriorityDeque::size() const {
    return static_cast<int>(data.size());
}

std::pair<int, int> PriorityDeque::get_minimal_priority() const {
    if (data.empty())
        error_message("Очередь пуста (get_minimal_priority)");

    auto minElem = data.front();
    for (const auto& item : data) {
        if (item.second < minElem.second)
            minElem = item;
    }
    return minElem;
}

std::pair<int, int> PriorityDeque::get_maximum_priority() const {
    if (data.empty())
        error_message("Очередь пуста (get_maximum_priority)");

    auto maxElem = data.front();
    for (const auto& item : data) {
        if (item.second > maxElem.second)
            maxElem = item;
    }
    return maxElem;
}

std::string PriorityDeque::toString() const {
    std::ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < data.size(); ++i) {
        oss << "(" << data[i].first << ", pr=" << data[i].second << ")";
        if (i < data.size() - 1)
            oss << ", ";
    }
    oss << "]";
    return oss.str();
}