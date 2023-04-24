#ifndef KNIGHT_HPP
#define KNIGHT_HPP

#include "character.hpp"

class Knight : public Character
{
private:
    // TODO: add squire name as char*
    void do_print() const final;
public:
    Knight(const std::string &_name = "<anonymous>", double _hp = 0, double _dmg = 0); // TODO: add squire name here as well

    void takeDamage(double points) final;
    void heal(double points) final;
};

#endif