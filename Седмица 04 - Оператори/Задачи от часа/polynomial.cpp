#include <cmath>
#include "polynomial.hpp"

bool areEqual(double a, double b)
{
    constexpr double EPSILON = 0.000001;
    return fabs(a - b) < EPSILON;
}

void Polynomial::resize()
{
    if (capacity == 0)
    {
        ++capacity;
    }
    
    std::size_t newCapacity = capacity * 2;
    double *newCoefficients = new double[newCapacity];

    for (std::size_t i = 0; i < degree + 1; i++)
    {
        newCoefficients[i] = coefficients[i];
    }

    delete[] coefficients;
    coefficients = newCoefficients;
    capacity = newCapacity;
}

void Polynomial::copy(const Polynomial &other)
{
    degree = other.degree;
    capacity = other.capacity;

    coefficients = new double[other.capacity];

    for (std::size_t i = 0; i < other.degree + 1; i++)
    {
        coefficients[i] = other.coefficients[i];
    }
}

void Polynomial::erase()
{
    delete[] coefficients;
    degree = -1;
}

Polynomial::Polynomial(std::size_t _capacity)
    : capacity(_capacity),
      degree(-1),
      coefficients(new double[_capacity]) {}

Polynomial::Polynomial(const Polynomial &other)
{
    copy(other);
}

Polynomial::~Polynomial()
{
    erase();
}

Polynomial &Polynomial::operator=(const Polynomial &other)
{
    if (this != &other)
    {
        erase();
        copy(other);
    }

    return *this;
}

void Polynomial::addCoeff(double a)
{
    if (degree + 1 == capacity)
    {
        resize();
    }
    coefficients[++degree] = a;
}

void Polynomial::removeCoeff()
{
    if (degree >= 0)
    {
        degree--;
    }
}

double Polynomial::operator()(double x) const
{
    int n = 0;
    return reduce(coefficients, degree + 1, [x, &n](const double &res, const double &el){
            return res + el * pow(x, n++); 
        },0);
}

double Polynomial::operator[](std::size_t index) const
{
    if (index >= 0 && index <= degree)
    {
        return coefficients[index];
    }
    return 0;
}

Polynomial Polynomial::operator+(const Polynomial &other) const
{
    Polynomial res;
    
    std::size_t minDegree = std::min(degree, other.degree);
    std::size_t maxDegree = std::max(degree, other.degree);

    for (size_t i = 0; i < minDegree + 1; i++)
    {
        res.addCoeff(coefficients[i] + other.coefficients[i]);
    }

    for (size_t i = minDegree + 1; i < 1 + maxDegree; i++)
    {
        if (degree > other.degree)
        {
            res.addCoeff(coefficients[i]);
        }
        else
        {
            res.addCoeff(other.coefficients[i]);
        }
    }
    return res;
}

Polynomial Polynomial::operator-(const Polynomial &) const
{
}

Polynomial &Polynomial::operator+=(const Polynomial &)
{
}

Polynomial &Polynomial::operator-=(const Polynomial &other)
{
    std::size_t minDegree = std::min(degree, other.degree);
    std::size_t maxDegree = std::max(degree, other.degree);
    
    for (size_t i = 0; i < minDegree + 1; i++)
    {
        coefficients[i] -= other.coefficients[i];
    }

    for (size_t i = minDegree + 1; i < 1 + maxDegree; i++)
    {
        if (degree == minDegree)
        {
            addCoeff(other.coefficients[i]);
        }
        else
        {
            coefficients[i] = -coefficients[i];
        }
    }

    return *this;
}

Polynomial Polynomial::operator*(double n) const
{
    Polynomial res;
    for (size_t i = 0; i < degree + 1; i++)
    {
        res.addCoeff(coefficients[i] * n);
    }
    return res;
}

Polynomial Polynomial::operator/(double) const
{
}

Polynomial &Polynomial::operator*=(double)
{
}

Polynomial &Polynomial::operator/=(double)
{
}

bool Polynomial::operator==(const Polynomial &other) const
{
    if (degree != other.degree)
    {
        return false;
    }

    double diff = coefficients[0] / other.coefficients[0];
    Polynomial p = other * diff;
    for (size_t i = 0; i < degree + 1; i++)
    {
        if (!areEqual(coefficients[i], p.coefficients[i]))
        {
            return false;
        }
    }
    return true;
}

bool Polynomial::operator!=(const Polynomial &other) const
{
    return !(*this == other);
}

std::ostream &operator<<(std::ostream &os, const Polynomial &other)
{
    for (int i = other.degree; i >= 1; i--)
    {
        os << other.coefficients[i] << "x^" << i << " + ";
    }
    return os << other.coefficients[0];
}