#include <iostream>
#include "polynomial.hpp"

int main() {
    Polynomial p;
    Polynomial q;
    p.addCoeff(5);
    p.addCoeff(2);

    Polynomial p1;
    p1.addCoeff(10);
    p1.addCoeff(4);

    q.addCoeff(3);
    q.addCoeff(9);
    q.addCoeff(10);

    Polynomial y = p + q;
    std::cout<<y(6)<<'\n';
    q -= p;
    std::cout<<'\n'<<q<<'\n';
    std::cout<<'\n'<<y*2.5<<'\n';
    std::cout<<'\n'<<std::boolalpha<<(p == p1)<<' ' << (q == y)<<'\n';
    y *= 5;
    std::cout<<'\n'<<y<<'\n';
    return 0;
}