#include "game.hpp"

void Game::resize()
{
    if (capacity == 0)
    {
        ++capacity;
    }

    capacity *= 2;
    Character **newCharacters = new Character *[capacity];
    for (std::size_t i = 0; i < size; i++)
    {
        newCharacters[i] = characters[i];
    }
    delete[] characters;
    characters = newCharacters;
}

void Game::copy(const Game &other)
{
    size = other.size;
    capacity = other.capacity;
    characters = new Character *[other.capacity];
    for (std::size_t i = 0; i < other.size; i++)
    {
        characters[i] = other.characters[i];
    }
}
void Game::destroy()
{
    delete[] characters;
}

Character *Game::find(const std::string &name)
{
    for (std::size_t i = 0; i < size; i++)
    {
        if (*characters[i] == name)
        {
            return characters[i];
        }
    }
    return nullptr;
}

Game::Game() : size(0), capacity(0), characters(nullptr) {}

Game::Game(const Game &other)
{
    copy(other);
}

Game::~Game()
{
    destroy();
}

Game &Game::operator=(const Game &other)
{
    if (this != &other)
    {
        copy(other);
        destroy();
    }
    return *this;
}

void Game::add(Character *character)
{
    if (size == capacity)
    {
        resize();
    }

    characters[size++] = character;
}

void Game::battle(const std::string &attacker, const std::string &target)
{
    Character *attackingCharacter = find(attacker);
    Character *defendingCharacter = find(target);

    if (!attackingCharacter)
    {
        std::cout << "No character with name " << attacker << '\n';
        return;
    }

    if (!defendingCharacter)
    {
        std::cout << "No character with name " << target << '\n';
        return;
    }

    attackingCharacter->dealDamageTo(*defendingCharacter);

    // TODO: remove character if health bellow 0
}

void Game::print() const
{
    for (std::size_t i = 0; i < size; i++)
    {
        characters[i]->print();
    }
}