#include "archer.hpp"

void Archer::do_print() const
{
    std::cout << "Type: Archer\n";
}

Archer::Archer(const std::string &_name, double _hp, double _dmg)
    : Character(_name, _hp, _dmg * 1.33) {}

void Archer::takeDamage(double points)
{
    points *= 1.15;
    Character::takeDamage(points);
}