#include <iostream>
#include "linkedList.hpp"

int main() {
    LinkedList<int> l;
    l.insertLast(1);
    l.insertLast(2);
    l.insertLast(3);
    l.insertLast(4);
    l.reverse();
    std::cout<<std::boolalpha<<l.any([](const int& el){
        return el % 2 == 0;
    }) << '\n';
    LinkedList<int> m(l);
    l.append(m);
    return 0;
}