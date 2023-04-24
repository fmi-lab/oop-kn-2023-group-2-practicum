#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include "character.hpp"

class Game
{
private:
    Character **characters;
    std::size_t size, capacity;

    void resize();
    void copy(const Game &other);
    void destroy();
    Character *find(const std::string &name);
public:
    Game();
    Game(const Game &other);
    ~Game();
    Game &operator=(const Game &other);

    void add(Character *character);
    void battle(const std::string &attacker, const std::string &target);
    void print() const;
    // TODO: add heal method
};

#endif