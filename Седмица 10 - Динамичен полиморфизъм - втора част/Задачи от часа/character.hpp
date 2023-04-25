#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>

class Character
{
private:
    std::string name;
    double hp, dmg;

    virtual void do_print() const;

public:
    Character(const std::string &_name = "<anonymous>", double _hp = 0, double _dmg = 0);
    virtual void dealDamageTo(Character &other) const;
    virtual void takeDamage(double points);
    virtual void heal(double points);

    bool operator==(const std::string &_name) const;

    void print() const;

    virtual ~Character() = default;

    virtual Character* clone() const;
    bool isAlive() const;
};

#endif