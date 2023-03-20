#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>

class Complex {
private:
    double real;
    double imaginary;

public:
    Complex(double _real = 0, double _imaginary = 0);
    
    double getRealPart() const;
    double getImaginaryPart() const;
    Complex& setRealPart(double);
    Complex& setImaginaryPart(double);

    double modulus() const;
    void print(std::ostream& os = std::cout) const;
    void printTrigonometric(std::ostream& os = std::cout) const;

    Complex operator+(const Complex&) const;
    Complex operator-(const Complex&) const;
    Complex operator*(const Complex&) const;
    Complex operator/(const Complex&) const;
    Complex operator^(int) const;

    Complex& operator+=(const Complex&);
    Complex& operator-=(const Complex&);
    Complex& operator*=(const Complex&);
    Complex& operator/=(const Complex&);
    Complex& operator^=(int);

    double operator*() const;
    operator double() const;

    bool operator<(const Complex&) const;
    bool operator<=(const Complex&) const;
    bool operator>(const Complex&) const;
    bool operator>=(const Complex&) const;

    bool operator==(const Complex&) const;
    bool operator!=(const Complex&) const;
};

std::istream& operator>>(std::istream&, Complex&);
std::ostream& operator<<(std::ostream&, const Complex&);

#endif