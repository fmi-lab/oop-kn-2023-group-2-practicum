#include <iostream>
#include "polynomial.hpp"

int main() {
    Polynomial p;
    Polynomial q;
    p.addCoeff(5);
    p.addCoeff(2);

    q.addCoeff(3);
    q.addCoeff(9);
    q.addCoeff(10);

    Polynomial y = p + q;
    // std::cout<<y(6);
    q -= p;
    std::cout<<'\n'<<q<<'\n';
    // std::cout<<'\n'<<y*2.5<<'\n';
    return 0;
}