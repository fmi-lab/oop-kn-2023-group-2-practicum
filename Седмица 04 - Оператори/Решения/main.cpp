#include <iostream>
#include "complex.hpp"

int main()
{
    Complex a(2, 3);
    a.print();
    a.printTrigonometric();

    Complex b;
    std::cout << b << '\n';
    b.printTrigonometric();

    std::cin >> b;
    std::cout << b << '\n';

    std::cout << a + b << '\n'
              << a * b << '\n';

    Complex c(4);
    c -= a;
    std::cout<<*c<<'\n';

    double modulus = c;
    std::cout<<modulus<<'\n';

    std::cout<<(a^3)<<'\n';
    a ^= 3;
    std::cout<<a<<'\n';
    return 0;
}