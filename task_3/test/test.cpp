#include "catch_amalgamated.hpp"
#include "../include/circle.h"
#include "../include/point.h"

TEST_CASE("Circle class comprehensive tests", "[circle]") {
    CUSTOM::Point::max_x = 1000;
    CUSTOM::Point::max_y = 1000;

    SECTION("Constructors and basic properties") {
        CUSTOM::Circle circle1(100, 100, 50);
        REQUIRE(circle1.ToString() == "Circle: {center(100,100), Radius(50)}");

        CUSTOM::Point center(150, 150);
        CUSTOM::Circle circle2(center, 75);
        REQUIRE(circle2.ToString() == "Circle: {center(150,150), Radius(75)}");
    }

    SECTION("Edge cases") {
        REQUIRE_NOTHROW(CUSTOM::Circle(0, 0, 1)); 
        REQUIRE_NOTHROW(CUSTOM::Circle(1000, 1000, 1));
    }

    SECTION("Invalid radius") {
        REQUIRE_THROWS_AS(CUSTOM::Circle(100, 100, 0), invalid_argument);
    }

    SECTION("Out of bounds") {
        CUSTOM::Point::max_x = 100;
        CUSTOM::Point::max_y = 100;
        REQUIRE_THROWS(CUSTOM::Circle(150, 150, 10));
        CUSTOM::Point::max_x = 1000;
        CUSTOM::Point::max_y = 1000;
    }

    SECTION("Draw method output") {
        CUSTOM::Circle circle(200, 200, 100);
        REQUIRE_NOTHROW(circle.Draw());
    }

    SECTION("Inheritance check") {
        CUSTOM::Circle circle(300, 300, 150);
        CUSTOM::Figure* figure = &circle;
        REQUIRE_NOTHROW(figure->Draw());
        REQUIRE_NOTHROW(figure->ToString());
    }
}