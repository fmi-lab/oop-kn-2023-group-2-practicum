#include "character.hpp"

void Character::do_print() const
{
    std::cout << "Type: Ordinary Character\n";
}

Character::Character(const std::string &_name, double _hp, double _dmg)
    : name(_name), hp(_hp), dmg(_dmg) {}

void Character::dealDamageTo(Character &other) const
{
    other.takeDamage(dmg);
}

void Character::takeDamage(double points)
{
    hp -= points;
}

void Character::heal(double points)
{
    hp += points;
}

bool Character::operator==(const std::string &_name) const
{
    return name == _name;
}

void Character::print() const
{
    std::cout << "Name: " << name << '\n';
    do_print();
    std::cout << "HP: " << hp << '\n'
              << "DMG: " << dmg << '\n';
}