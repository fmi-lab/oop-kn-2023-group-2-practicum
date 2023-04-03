#include <cstring>
#include "pencil.hpp"

Pencil::Pencil(const char *_brand, unsigned _year, unsigned _hardness) : year(_year), hardness(_hardness) {
    strcpy(brand, _brand);
}

const char *Pencil::getBrand() const {
    return brand;
}

unsigned Pencil::getYear() const {
    return year;
}

unsigned Pencil::getHardness() const {
    return hardness;
}

void Pencil::setBrand(const char *_brand) {
    strcpy(brand, _brand);
}

void Pencil::setYear(unsigned _year) {
    year = _year;
}

void Pencil::setHardness(unsigned _hardness) {
    hardness = _hardness;
}


std::istream &operator>>(std::istream &is, Pencil &pencil) {
    is>>pencil.year>>pencil.hardness;
    is.ignore();
    return is.getline(pencil.brand, 101);
}
std::ostream &operator<<(std::ostream &os, const Pencil &pencil) {
    return os << pencil.getYear() << ' ' << pencil.getHardness() << ' ' << pencil.getBrand() << '\n';
}
