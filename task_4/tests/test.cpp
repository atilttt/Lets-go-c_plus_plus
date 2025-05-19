#include "Queue.h"
#include <gtest/gtest.h>

//Проверка нахождения минимального и максимального приоритета
TEST(PriorityDequeTest, MinMaxPriorityElements) {
    PriorityDeque q = { {10, 5}, {20, 1}, {30, 9} };
    auto min = q.get_minimal_priority();
    auto max = q.get_maximum_priority();
    EXPECT_EQ(min.first, 20);
    EXPECT_EQ(min.second, 1);
    EXPECT_EQ(max.first, 30);
    EXPECT_EQ(max.second, 9);
}


//Проверка удаления элементов с обеих сторон очереди
TEST(PriorityDequeTest, PopOperations) {
    PriorityDeque q = { {1, 1}, {2, 2}, {3, 3} };
    q.pop_front(); 
    EXPECT_EQ(q.size(), 2);
    q.pop_back(); 
    EXPECT_EQ(q.size(), 1);
}

//Проверка метода isEmpty() до и после вставки
TEST(PriorityDequeTest, IsEmpty) {
    PriorityDeque q;
    EXPECT_TRUE(q.isEmpty());
    q.push_back(10, 1);
    EXPECT_FALSE(q.isEmpty());
}

// Проверка выхода при недопустимом приоритете (меньше MIN_PRIORITY)
TEST(PriorityDequeTest, InvalidPriorityCausesExit) {
    EXPECT_EXIT({
        PriorityDeque q;
        q.push_back(42, static_cast<size_t>(-1));
    }, ::testing::ExitedWithCode(EXIT_FAILURE), "Недопустимый приоритет");
}

// Проверка выхода при удалении из пустой очереди
TEST(PriorityDequeTest, PopEmptyDequeCausesExit) {
    EXPECT_EXIT({
        PriorityDeque q;
        q.pop_front();
    }, ::testing::ExitedWithCode(EXIT_FAILURE), "Очередь пуста.*pop_front");
}

// Проверка выхода при попытке найти min в пустой очереди
TEST(PriorityDequeTest, GetMinFromEmptyCausesExit) {
    EXPECT_EXIT({
        PriorityDeque q;
        q.get_minimal_priority();
    }, ::testing::ExitedWithCode(EXIT_FAILURE), "Очередь пуста.*get_minimal_priority");
}

// Проверка строкового вывода очереди
TEST(PriorityDequeTest, ToStringFormat) {
    PriorityDeque q = { {5, 2}, {8, 3} };
    EXPECT_EQ(q.toString(), "[(5, pr=2), (8, pr=3)]");
}
