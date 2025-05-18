#include <iostream>
#include "../include/Queue.h"

#define DEBUG_MODE 

#ifdef DEBUG_MODE

int main() {
    PriorityDeque q = {{10, 3}, {5, 1}, {20, 7}};
    
    std::cout << "Начальная очередь: " << q.toString() << "\n";

    auto min = q.get_minimal_priority();
    auto max = q.get_maximum_priority();

    std::cout << "Минимальный приоритет: " << min.first << " (pr=" << min.second << ")\n";
    std::cout << "Максимальный приоритет: " << max.first << " (pr=" << max.second << ")\n";

    q.pop_front();
    q.push_back(100, 500);
    q.push_front(200, 900);

    std::cout << "После изменений: " << q.toString() << "\n";

    std::cout << "Проверка isEmpty(): " << (q.isEmpty() ? "пусто" : "не пусто") << "\n";
    std::cout << "Размер очереди: " << q.size() << "\n";

    return 0;
}

#endif //DEBUG_MOD
