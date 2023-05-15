#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

class BinarySerializable
{
public:
    virtual void serialize(const std::string &filename) = 0;
    virtual void serializeAt(const std::string &filename, std::size_t pos) = 0;
    virtual void deserialize(const std::string &filename) = 0;
    virtual void deserializeAt(const std::string &filename, std::size_t pos) = 0;
};

class Book : public BinarySerializable
{
private:
    static constexpr std::size_t NAME_MAX_LENGHT = 100;
    static constexpr std::size_t AUTHOR_MAX_LENGTH = 50;

public:
    Book(const char _name[NAME_MAX_LENGHT] = "",
         const char _author[AUTHOR_MAX_LENGTH] = "",
         unsigned _id = 0) : id(_id)
    {
        strcpy(name, _name);
        strcpy(author, _author);
    }

    void print() const {
        std::cout<<name<<" "<<author<<" "<<id<<'\n';
    }

    void serialize(const std::string &filename)
    {
        std::fstream os(filename, std::ios::out | std::ios::binary);
        os.write(reinterpret_cast<const char *>(this), sizeof(Book));
        os.close();
    }
    void serializeAt(const std::string &filename, std::size_t pos)
    {
        std::fstream os(filename, std::ios::out | std::ios::binary | std::ios::app); // !
        os.seekp(0, std::ios::end); // !
        std::streampos size = os.tellp();
        std::size_t booksSize = size / sizeof(Book);
        if (pos <= booksSize)
        {
            os.seekp((pos - 1) * sizeof(Book));
            os.write(reinterpret_cast<const char *>(this), sizeof(Book));
        }
        os.close();
    }
    void deserialize(const std::string &filename)
    {
        std::fstream is(filename, std::ios::in);
        is.read(reinterpret_cast<char *>(this), sizeof(Book));
        is.close();
    }
    void deserializeAt(const std::string &filename, std::size_t pos)
    {
    }

private:
    char name[NAME_MAX_LENGHT];
    char author[AUTHOR_MAX_LENGTH];
    unsigned id;
};

void swap(int &a, int &b)
{
    a = a ^ b; // a ^= b;
    b = a ^ b;
    a = a ^ b;
}

bool even(int a)
{
    return a != (a | 1);
}

int change_sign(int a)
{
    return ~a + 1;
}

int main()
{
    // int a = 5, b = 4;
    // swap(a, b);
    // std::cout<<a<<' '<<b<<'\n';
    // std::cout<<std::boolalpha<<even(5)<<' ' <<even(4)<<'\n';
    // std::cout << change_sign(-7) << '\n';
    Book book("LOTR", "Tolkien", 5);
    book.serialize("book.bin");
    Book next;
    next.deserialize("book.bin");
    next.print();
    next.serializeAt("book.bin", 0);
    return 0;
}