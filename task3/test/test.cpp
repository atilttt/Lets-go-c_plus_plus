#include "catch_amalgamated.hpp"
#include "../include/circle.h"
#include "../include/point.h"

TEST_CASE("Circle class tests", "[circle]") {
    // Устанавливаем максимальные значения координат
    CUSTOM::Point::max_x = 1000;
    CUSTOM::Point::max_y = 1000;

    SECTION("ToString returns correct representation") {
        CUSTOM::Circle circle(100, 100, 50);
        REQUIRE(circle.ToString() == "Circle: {center(100,100), Radius(50)}");
    }

    SECTION("Constructor with Point works correctly") {
        CUSTOM::Point center(150, 150);
        CUSTOM::Circle circle(center, 75);
        REQUIRE(circle.ToString() == "Circle: {center(150,150), Radius(75)}");
    }

    SECTION("Draw method doesn't throw") {
        CUSTOM::Circle circle(200, 200, 100);
        REQUIRE_NOTHROW(circle.Draw());
    }

    SECTION("Constructor throws when point is out of bounds") {
        CUSTOM::Point::max_x = 100;
        CUSTOM::Point::max_y = 100;
        REQUIRE_THROWS(CUSTOM::Circle(150, 150, 10));
        // Возвращаем значения обратно для других тестов
        CUSTOM::Point::max_x = 1000;
        CUSTOM::Point::max_y = 1000;
    }
}