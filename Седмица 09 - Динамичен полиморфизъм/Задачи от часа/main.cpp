#include <iostream>
#include <string>

class Character
{
private:
    std::string name;
    double hp, dmg;

    virtual void do_print() const
    {
        std::cout << "Type: Ordinary Character\n";
    }

public:
    Character(const std::string &_name = "<anonymous>", double _hp = 0, double _dmg = 0)
        : name(_name), hp(_hp), dmg(_dmg) {}

    virtual void dealDamageTo(Character &other) const
    {
        other.takeDamage(dmg);
    }

    virtual void takeDamage(double points)
    {
        hp -= points;
    }

    virtual void heal(double points)
    {
        hp += points;
    }

    bool operator==(const std::string &_name) const
    {
        return name == _name;
    }

    void print() const
    {
        std::cout << "Name: " << name << '\n';
        do_print();
        std::cout << "HP: " << hp << '\n'
                  << "DMG: " << dmg << '\n';
    }
};

class Knight : public Character
{
private:
    void do_print() const final
    {
        std::cout << "Type: Knight\n";
    }

public:
    Knight(const std::string &_name = "<anonymous>", double _hp = 0, double _dmg = 0)
        : Character(_name, _hp, _dmg) {}

    void takeDamage(double points) final
    {
        points *= 0.75;
        Character::takeDamage(points);
    }

    void heal(double points) final
    {
        points *= 1.05;
        Character::heal(points);
    }
};

class Archer : public Character
{
private:
    void do_print() const final
    {
        std::cout << "Type: Archer\n";
    }

public:
    Archer(const std::string &_name = "<anonymous>", double _hp = 0, double _dmg = 0)
        : Character(_name, _hp, _dmg * 1.33) {}

    void takeDamage(double points) final
    {
        points *= 1.15;
        Character::takeDamage(points);
    }
};

class Game
{
private:
    Character **characters;
    std::size_t size, capacity;

    void resize()
    {
        if (capacity == 0)
        {
            ++capacity;
        }

        capacity *= 2;
        Character **newCharacters = new Character *[capacity];
        for (size_t i = 0; i < size; i++)
        {
            newCharacters[i] = characters[i];
        }
        delete[] characters;
        characters = newCharacters;
    }

    void copy(const Game &other)
    {
        size = other.size;
        capacity = other.capacity;
        characters = new Character *[other.capacity];
        for (size_t i = 0; i < other.size; i++)
        {
            characters[i] = other.characters[i];
        }
    }
    void destroy()
    {
        delete[] characters;
    }

    Character *find(const std::string &name)
    {
        for (size_t i = 0; i < size; i++)
        {
            if (*characters[i] == name)
            {
                return characters[i];
            }
        }
        return nullptr;
    }

public:
    Game() : size(0), capacity(0), characters(nullptr) {}

    Game(const Game &other)
    {
        copy(other);
    }
    
    ~Game()
    {
        destroy();
    }

    Game &operator=(const Game &other)
    {
        if (this != &other)
        {
            copy(other);
            destroy();
        }
        return *this;
    }

    void add(Character *character)
    {
        if (size == capacity)
        {
            resize();
        }

        characters[size++] = character;
    }

    void battle(const std::string &attacker, const std::string &target)
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
    }

    void print() const
    {
        for (size_t i = 0; i < size; i++)
        {
            characters[i]->print();
        }
    }
};

int main()
{
    Character kratos("Kratos", 200, 50);
    Knight artorias("Artorias", 175, 25);
    Game game;
    game.add(&kratos);
    game.add(&artorias);
    game.battle("Kratos", "Artorias");
    game.print();
    return 0;
}