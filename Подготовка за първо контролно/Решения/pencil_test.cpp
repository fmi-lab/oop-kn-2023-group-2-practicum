#include <iostream>
#include <fstream>
#include <functional>
#include "pencil.hpp"
#include "bag.hpp"

int main() {
    Bag<Pencil> pencilList("Gosho");
    std::ifstream is("pencils.txt");
    while (!is.eof())
    {
        Pencil pencil;
        is >> pencil;
        pencilList.add(pencil);   
    }
    is.close();

    char name[101]{'\0'};
    std::cin.getline(name, 101);
    pencilList.filter([&name](const Pencil& pencil){
        return strcmp(pencil.getBrand(), name) == 0;
    });

    std::ofstream os("brand.txt");
    os << pencilList;
    os.close();
    
    return 0;
}