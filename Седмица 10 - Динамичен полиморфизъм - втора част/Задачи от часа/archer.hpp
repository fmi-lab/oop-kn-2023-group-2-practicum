#ifndef ARCHER_HPP
#define ARCHER_HPP

#include "character.hpp"

class Archer : public Character
{
private:
    void do_print() const final;
public:
    Archer(const std::string &_name = "<anonymous>", double _hp = 0, double _dmg = 0);
    void takeDamage(double points) final;

    Character* clone() const final;
};

#endif