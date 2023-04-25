#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include "serializable.hpp"
#include "character.hpp"

class Game : public Serializable
{
private:
    Character **characters;
    std::size_t size, capacity;

    void resize();
    void copy(const Game &other);
    void destroy();
    Character *find(const std::string &name);
    std::size_t findIndex(const Character* character) const;

    void remove(std::size_t index);
public:
    Game();
    Game(const Game &other);
    ~Game();
    Game &operator=(const Game &other);

    void add(const Character *character);
    void battle(const std::string &attacker, const std::string &target);
    void print(std::ostream& os = std::cout) const;
    void heal(double points);

    std::ostream& serialize(std::ostream& os) const final;
};

#endif