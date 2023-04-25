#include <cstring>
#include "knight.hpp"

void Knight::do_print() const
{
    std::cout << "Type: Knight\n";
}

void Knight::copy(const Knight &other)
{
    squire = new char[strlen(other.squire) + 1];
    strcpy(squire, other.squire);
}

void Knight::destroy()
{
    delete[] squire;
}

Knight::Knight(const std::string &_name, double _hp, double _dmg, const char *_squire)
    : Character(_name, _hp, _dmg), squire(new char[strlen(_squire) + 1])
{
    strcpy(squire, _squire);
}

Knight::Knight(const Knight &other) : Character(other)
{
    copy(other);
}
Knight::~Knight()
{
    destroy();
}
Knight &Knight::operator=(const Knight &other)
{
    if (this != &other)
    {
        destroy();
        copy(other);
    }
    return *this;
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

Knight *Knight::clone() const
{
    return new Knight(*this);
}