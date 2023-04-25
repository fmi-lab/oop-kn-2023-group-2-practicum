#include "character.hpp"
#include "knight.hpp"
#include "archer.hpp"
#include "game.hpp"

int main()
{
    // Character knight = Knight("arthur", 150, 33, "Atreus");
    // knight.print();
    // Character* knight2 = new Knight("Arthur", 150, 30, "Atreus");
    // knight2->print();
    // delete knight2;
    Character* c = new Character("Kratos", 120, 30);
    Knight* k = new Knight("Arthur", 140, 50, "Gosho");
    Archer* a = new Archer("Legolas", 250, 100);
    Game game;
    game.add(c);
    game.add(k);
    game.add(a);
    delete k;
    delete a;
    game.battle("Legolas", "Kratos");
    game.print();
    delete c;
    return 0;
}