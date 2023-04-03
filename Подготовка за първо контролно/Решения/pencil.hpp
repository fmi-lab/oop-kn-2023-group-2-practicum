#ifndef PENCIL_HPP
#define PENCIL_HPP

#include <iostream>

class Pencil {
private:
    char brand[101];
    unsigned year;
    unsigned hardness;
public:
    Pencil(const char* _brand = "<unknown>", unsigned _year = 0, unsigned _hardness = 0);

    const char* getBrand() const;
    unsigned getYear() const;
    unsigned getHardness() const;

    void setBrand(const char* _brand);
    void setYear(unsigned _year);
    void setHardness(unsigned _hardness);

    friend std::istream& operator>>(std::istream& is, Pencil& pencil);
};

std::ostream& operator<<(std::ostream& os, const Pencil& pencil);

#endif