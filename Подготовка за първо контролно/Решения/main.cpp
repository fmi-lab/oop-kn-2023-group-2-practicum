#include <iostream>
#include <fstream>
#include "bag.hpp"

int main() {
    Bag<int> bag("georgi");
    for (size_t i = 0; i < 5; i++)
    {
        bag.add(i);
    }
    Bag<int> bag1("mitko");
    bag1.add(5);
    Bag<int> result = bag + bag1;
    // std::cout << result;

    std::ofstream of("output.txt");
    of << result;
    of.close();
    
    std::ifstream ifs("output.txt");
    for (size_t i = 0; i < 6; i++)
    {
        int a;
        ifs >> a;
        result.add(a);
    }
    ifs.close();
    std::cout<<result;

    of.open("output.txt", std::ios::app);
    of << "a";
    of.close();
    char s[10];
    ifs.getline(s, 10);
    return 0;
}