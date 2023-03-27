#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <cmath>
#include "doctest.h"
#include "car.hpp"

bool areEqual(double a, double b) {
    constexpr double EPSILON = 0.00001;
    return fabs(a - b) < EPSILON;
}

TEST_CASE("Car constructor creates car successfully")
{
    Car car("bmw", "e36", 120);

    CHECK(strcmp(car.getBrand(), "bmw") == 0);
    CHECK_EQ(strcmp(car.getModel(), "e36"), 0);
}

TEST_CASE("Car dynamic memory test")
{
    Car car("bmw", "e36", 120);

    SUBCASE("Car copy sonstructor manages memory correctly")
    {
        Car *copy = new Car(car);
        delete copy;

        CHECK(strcmp(car.getBrand(), "bmw") == 0);
        CHECK_EQ(strcmp(car.getModel(), "e36"), 0);
    }

    SUBCASE("Car copy assignment operator manages memory correctly")
    {
        Car *copy = new Car("toyota", "supra", 5000);
        *copy = car;
        delete copy;

        CHECK(strcmp(car.getBrand(), "bmw") == 0);
        CHECK_EQ(strcmp(car.getModel(), "e36"), 0);
    }
}

TEST_CASE("Correct id") {
    Car car1("bmw", "e36", 120);
    Car car2("toyota", "supra mk4", 5000);

    CHECK_FALSE(car1.getId() == car2.getId());
    CHECK_EQ(car1.getId() + 1, car2.getId());
}

TEST_CASE("Drive method test") {
    Car car("bmw", "e36", 100);

    SUBCASE("Drive correctly estimates time") {
        CHECK(areEqual(car.drive(50), 0.5));
    }

    SUBCASE("Drive modifies distance") {
        REQUIRE(areEqual(car.drive(50), 0.5));
        CHECK(areEqual(car.getDistance(), 50));
    }

    SUBCASE("Average speed decreases with every 100 km") {
        CHECK(areEqual(car.drive(100), 1));
        CHECK(areEqual(car.drive(99), 1));
    }
}