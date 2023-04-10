#include <iostream>
#include <cstring>

class Animal
{
private:
    char *name;
    unsigned age;
    double weight;
    
// protected:
//     double weight;

private:
    void copy(const Animal &other)
    {
        age = other.age;
        weight = other.weight;
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    }

    void destroy()
    {
        delete[] name;
    }

public:
    Animal(const char *_name, unsigned _age, double _weight)
        : name(new char[strlen(_name) + 1]), age(_age), weight(_weight)
    {
        strcpy(name, _name);
    }

    Animal(const Animal &other)
    {
        copy(other);
    }

    ~Animal()
    {
        std::cout << "~Animal()\n";
        destroy();
    }

    Animal &operator=(const Animal &other)
    {
        if (this != &other)
        {
            destroy();
            copy(other);
        }

        return *this;
    }

    void print() const
    {
        std::cout << "Name: " << name << '\n'
                  << "Age: " << age << '\n'
                  << "Weight: " << weight << '\n';
    }
};

class Feline : public Animal
{
private:
    unsigned remainingLives;

public:
    Feline(const char *_name, unsigned _age, double _weight, unsigned _lives)
        : Animal(_name, _age, _weight), remainingLives(_lives) // , Animal()
    {
    }

    void print() const
    {
        Animal::print();
        std::cout << "Remaining lives: " << remainingLives << '\n';
        // std::cout<<weight<<'\n' << age;
    }
};

class Cat : public Feline
{
private:
    char *owner;

public:
    Cat(const char *_name,
        unsigned _age,
        double _weight,
        unsigned _lives,
        const char *_owner)
        : Feline(_name, _age, _weight, _lives),
          owner(new char[strlen(_owner) + 1])
    {
        strcpy(owner, _owner);
    }

    Cat(const Cat &other)
        : Feline(other),
          owner(new char[strlen(other.owner) + 1])
    {
        strcpy(owner, other.owner);
    }

    ~Cat() {
        delete[] owner;
    }

    Cat& operator=(const Cat& other) {
        if(this != &other) {
            Feline::operator=(other);
            delete[] owner;
            owner = new char[strlen(other.owner)+1];
            strcpy(owner, other.owner);
        }

        return *this;
    }

    void print() const {
        Feline::print();
        std::cout<<"Owner: "<<owner<<'\n';
        // std::cout<<weight;
    }
};

int main()
{
    Animal a("dog", 4, 25);
    Feline b("tiger", 2, 75, 2);
    Feline c(b);
    // c.weight;
    Cat rumen("Rumen", 36, 5, 0, "Julgena");
    a.print();
    c.print();
    rumen.print();

    Animal lion = Feline("Simba", 2, 60, 7);
    std::cout<<'\n';
    lion.print();

    return 0;
}