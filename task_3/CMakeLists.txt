cmake_minimum_required(VERSION 3.10)
project(CircleProject)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(CircleProject
    main/main.cpp
    src/point.cpp
    src/circle.cpp
)
