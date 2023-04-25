#ifndef KNIGHT_HPP
#define KNIGHT_HPP

#include "character.hpp"
#include "serializable.hpp"

class Knight : public Character //, public Serializable
{
private:
    char* squire;
    void do_print() const final;
    void copy(const Knight& other);
    void destroy();
public:
    Knight(const std::string &_name = "<anonymous>", double _hp = 0, double _dmg = 0, const char* _squire = "<anonymous>");
    Knight(const Knight& other);
    ~Knight();
    Knight& operator=(const Knight& other);

    void takeDamage(double points) final;
    void heal(double points) final;

    Knight* clone() const final;
};

#endif