cmake_minimum_required(VERSION 3.16)
project(PriorityDequeProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_library(prioritydeque STATIC
    src/Queue.cpp
)

target_include_directories(prioritydeque PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(app
    app/main.cpp
)

target_link_libraries(app prioritydeque)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(tests
    tests/test_priority_deque.cpp
)

target_link_libraries(tests prioritydeque GTest::GTest GTest::Main)

add_test(NAME PriorityDequeTests COMMAND tests)
