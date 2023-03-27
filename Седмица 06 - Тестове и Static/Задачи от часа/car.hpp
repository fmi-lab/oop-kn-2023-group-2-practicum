#ifndef CAR_HPP
#define CAR_HPP

#include <cstddef>

class Car {
private:
    char* brand;
    char* model;
    static std::size_t factoryNumber;
    std::size_t id;
    double originalAverageSpeed;
    double currentAverageSpeed;
    double distance;

    void erase();
    void copy(const Car&);
public:
    Car(const char* _brand, const char* _model, double _averageSpeed);
    Car(const Car&);
    ~Car();
    Car& operator=(const Car&);

    const char* getBrand() const { return brand; }
    // char* getBrand() {return brand;}
    const char* getModel() const { return model; }
    std::size_t getId() const {return id;}
    double getDistance() const {return distance; }

    double drive(double);
};

#endif