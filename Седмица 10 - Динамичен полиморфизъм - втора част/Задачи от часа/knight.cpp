#include "knight.hpp"

void Knight::do_print() const
{
    std::cout << "Type: Knight\n";
}

Knight::Knight(const std::string &_name, double _hp, double _dmg)
    : Character(_name, _hp, _dmg)
{
}

void Knight::takeDamage(double points)
{
    points *= 0.75;
    Character::takeDamage(points);
}

void Knight::heal(double points)
{
    points *= 1.05;
    Character::heal(points);
}