#include <cstring>
#include "car.hpp"

std::size_t Car::factoryNumber = 0;

Car::Car(const char *_brand, const char *_model, double _averageSpeed)
    : brand(new char[strlen(_brand) + 1]),
      model(new char[strlen(_model) + 1]),
      originalAverageSpeed(_averageSpeed),
      currentAverageSpeed(_averageSpeed),
      distance(0)
{
    ++factoryNumber;
    id = factoryNumber;
    strcpy(brand, _brand);
    strcpy(model, _model);
}

void Car::erase()
{
    delete[] brand;
    delete[] model;
}

void Car::copy(const Car &other)
{
    brand = new char[strlen(other.brand) + 1];
    model = new char[strlen(other.model) + 1];
    strcpy(brand, other.brand);
    strcpy(model, other.model);
    originalAverageSpeed = other.originalAverageSpeed;
    currentAverageSpeed = other.currentAverageSpeed;
    distance = other.distance;
    id = other.id;
}

Car::Car(const Car &other)
{
    copy(other);
}

Car::~Car()
{
    erase();
}

Car &Car::operator=(const Car &other)
{
    if (this != &other)
    {
        erase();
        copy(other);
    }

    return *this;
}

double Car::drive(double dist)
{
    double result = 0;
    double restOnSameSpeed = (100000 - (int)(distance * 100000) % 10000000) / 1000;
    result += restOnSameSpeed * currentAverageSpeed;
    if (currentAverageSpeed > originalAverageSpeed / 2)
    {
        --currentAverageSpeed;
    }
    dist -= restOnSameSpeed;
    double finalDist = ((int)(distance * 100000) % 10000000) / 1000;
    double hundreds = (int)(dist / 100);

    for (size_t i = 0; i < hundreds; i++)
    {
        result += 100 * currentAverageSpeed;
        if (currentAverageSpeed > originalAverageSpeed / 2)
        {
            --currentAverageSpeed;
        }
    }

    result += finalDist*currentAverageSpeed;

    return result;
}
