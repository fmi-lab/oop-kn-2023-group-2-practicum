#include <cassert>
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
        characters[i] = other.characters[i]->clone();
    }
}
void Game::destroy()
{
    for (size_t i = 0; i < size; i++)
    {
        delete characters[i];
    }

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
        destroy();
        copy(other);
    }
    return *this;
}

void Game::remove(std::size_t index)
{
    assert(index < size);

    delete characters[index];
    for (size_t i = index; i < size - 1; i++)
    {
        std::swap(characters[i], characters[i + 1]);
    }
    --size;
}

std::size_t Game::findIndex(const Character *character) const
{
    for (size_t i = 0; i < size; i++)
    {
        if (characters[i] == character)
        {
            return i;
        }
    }
    return size;
}

void Game::add(const Character *character)
{
    if (size == capacity)
    {
        resize();
    }

    characters[size++] = character->clone();
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

    if (!defendingCharacter->isAlive())
    {
        remove(findIndex(defendingCharacter));
    }
}

void Game::print(std::ostream &os) const
{
    for (std::size_t i = 0; i < size; i++)
    {
        characters[i]->print();
    }
}

void Game::heal(double points)
{
    for (size_t i = 0; i < size; i++)
    {
        characters[i]->heal(points);
    }
}

std::ostream &Game::serialize(std::ostream &os) const
{
    print(os);
    return os;
}