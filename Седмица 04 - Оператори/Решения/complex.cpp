#include <cmath>
#include "complex.hpp"

Complex::Complex(double _real, double _imaginary) : real(_real), imaginary(_imaginary) {}

double Complex::getRealPart() const { return real; }

double Complex::getImaginaryPart() const { return imaginary; }

Complex &Complex::setRealPart(double _real)
{
    real = _real;
    return *this;
}

Complex &Complex::setImaginaryPart(double _imaginary)
{
    imaginary = _imaginary;
    return *this;
}

double Complex::modulus() const { return sqrt(real * real + imaginary * imaginary); }

void Complex::print(std::ostream &os) const
{
    os << real << " + " << imaginary << "i\n";
}

void Complex::printTrigonometric(std::ostream &os) const
{
    if (real == 0 && imaginary == 0)
    {
        os << "undefined\n";
        return;
    }

    double angle = 0; // angle is in radians
    if (real < 0 && imaginary == 0)
    {
        angle = 2 * acos(0.0); // pi
    }
    else
    {
        angle = 2 * atan2(imaginary, (modulus() + real)); // atan2(x, y) computates arctg(x/y)
    }

    os << modulus() << "( cos(" << angle << ") + i*sin(" << angle << ") )\n";
}

Complex Complex::operator+(const Complex &other) const
{
    return Complex(real + other.real, imaginary + other.imaginary);
}

Complex Complex::operator-(const Complex &other) const
{
    return Complex(real - other.real, imaginary - other.imaginary);
}

Complex Complex::operator*(const Complex &other) const
{
    return Complex(real * other.real - imaginary * other.imaginary, real * other.imaginary + imaginary * other.real);
}

Complex Complex::operator/(const Complex &other) const
{
    double denominator = other.real * other.real + other.imaginary * other.imaginary;

    double realResult = (real * other.real + imaginary * other.imaginary) / denominator;
    double imaginaryResult = (imaginary * other.real - real * other.imaginary) / denominator;

    return Complex(realResult, imaginaryResult);
}

Complex Complex::operator^(int n) const
{
    Complex result(*this);
    for (size_t i = 1; i < n; i++)
    {
        result *= *this;
    }
    return result;
}

Complex &Complex::operator+=(const Complex &other)
{
    real += other.real;
    imaginary += other.imaginary;

    return *this;
}

Complex &Complex::operator-=(const Complex &other)
{
    real -= other.real;
    imaginary -= other.imaginary;

    return *this;
}

Complex &Complex::operator*=(const Complex &other)
{
    double newReal = real * other.real - imaginary * other.imaginary;
    double newImaginary = real * other.imaginary + imaginary * other.real;

    real = newReal;
    imaginary = newImaginary;

    return *this;
}

Complex &Complex::operator/=(const Complex &other)
{
    double denominator = other.real * other.real + other.imaginary * other.imaginary;

    real = (real * other.real + imaginary * other.imaginary) / denominator;
    imaginary = (imaginary * other.real - real * other.imaginary) / denominator;

    return *this;
}

Complex &Complex::operator^=(int n)
{
    return *this = Complex(*this) ^ n;
}

double Complex::operator*() const { return modulus(); }

Complex::operator double() const { return modulus(); }

bool Complex::operator<(const Complex &other) const
{
    return modulus() < other.modulus();
}

bool Complex::operator<=(const Complex &other) const
{
    return modulus() <= other.modulus();
}

bool Complex::operator>(const Complex &other) const
{
    return !(*this <= other);
}

bool Complex::operator>=(const Complex &other) const
{
    return !(*this < other);
}

bool Complex::operator==(const Complex &other) const
{
    return (*this <= other) && (*this >= other);
}

bool Complex::operator!=(const Complex &other) const
{
    return !(*this == other);
}

std::istream &operator>>(std::istream &is, Complex &complex)
{
    double realInput, imaginaryInput;
    is >> realInput >> imaginaryInput;
    complex.setRealPart(realInput).setImaginaryPart(imaginaryInput);
    return is;
}

std::ostream &operator<<(std::ostream &os, const Complex &complex)
{
    return os << complex.getRealPart() << " + " << complex.getImaginaryPart() << "i";
}
