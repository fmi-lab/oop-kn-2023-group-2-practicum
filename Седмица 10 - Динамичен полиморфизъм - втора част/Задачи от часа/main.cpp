#include "character.hpp"
#include "knight.hpp"
#include "game.hpp"

int main()
{
    Character kratos("Kratos", 200, 50);
    Knight artorias("Artorias", 175, 25); // TODO: show pointer casting
    Game game;
    game.add(&kratos);
    game.add(&artorias);
    game.battle("Kratos", "Artorias");
    game.print();
    return 0;
}