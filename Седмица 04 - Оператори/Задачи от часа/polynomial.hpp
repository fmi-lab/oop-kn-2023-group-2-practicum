#ifndef __POLYNOMIAL_HPP
#define __POLYNOMIAL_HPP

#include <cstddef>
#include <iostream>

class Polynomial {
private:
    double* coefficients;
    std::size_t degree;
    std::size_t capacity;

    void resize();
    void copy(const Polynomial&);
    void erase();
public:
    Polynomial(std::size_t _capacity = 0);
    Polynomial(const Polynomial&);
    ~Polynomial();
    Polynomial& operator=(const Polynomial&);

    void addCoeff(double);
    void removeCoeff();

    double operator()(double) const;
    double operator[](std::size_t) const;

    Polynomial operator+(const Polynomial&) const;
    Polynomial operator-(const Polynomial&) const;
    Polynomial& operator+=(const Polynomial&);
    Polynomial& operator-=(const Polynomial&);

    Polynomial operator*(double) const;
    Polynomial operator/(double) const;
    Polynomial& operator*=(double);
    Polynomial& operator/=(double);

    bool operator==(const Polynomial&) const;
    bool operator!=(const Polynomial&) const;

    friend std::ostream& operator<<(std::ostream&, const Polynomial&);
};

template <typename T, typename U, typename BinaryOperation>
U reduce(T *const arr, std::size_t size, BinaryOperation acc, U nv)
{
    for (size_t i = 0; i < size; i++)
    {
        nv = acc(nv, arr[i]);
    }
    return nv;
}

template <typename T, typename U = double, typename UnaryOperation>
U* map(T* arr, std::size_t size, UnaryOperation op)
{
    U* result = new U[size];
    for (size_t i = 0; i < size; i++)
    {
        result[i] = op(arr[i]);
    }
    
    return result;
}

#endif