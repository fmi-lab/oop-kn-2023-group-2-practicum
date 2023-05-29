#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include <new>
#include <stdexcept>
#include "../../Седмица 15 - Изключения/fileNotFoundException.hpp"

class BinarySerializable
{
public:
    virtual void serialize(const std::string &filename) noexcept = 0;
    virtual void serializeAt(const std::string &filename, std::size_t pos) noexcept = 0;
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

    void print() const
    {
        std::cout << name << " " << author << " " << id << '\n';
    }

    void serialize(const std::string &filename) noexcept
    {
        std::fstream os(filename, std::ios::out | std::ios::binary | std::ios::app);
        os.write(reinterpret_cast<const char *>(this), sizeof(Book));
        os.close();
    }
    void serializeAt(const std::string &filename, std::size_t pos) noexcept
    {
        std::fstream os(filename, std::ios::out | std::ios::binary | std::ios::app);
        os.seekp(0, std::ios::end);                                                  
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

        if (!is.good())
        {
            std::string message = "Could not open file with name: ";
            message += filename;
            is.close();
            throw FileNotFoundException(message);
        }
        
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

class Library : public BinarySerializable
{
public:
    Library(const std::string &_name) : name(_name) {}

    void serialize(const std::string &filename) noexcept
    {
        std::fstream os(filename, std::ios::out | std::ios::binary);

        std::size_t nameLength = name.size();
        os.write(reinterpret_cast<const char *>(&nameLength), sizeof(std::size_t));
        os.write(name.c_str(), nameLength);

        std::size_t booksLength = books.size();
        os.write(reinterpret_cast<const char *>(&booksLength), sizeof(std::size_t));

        os.close();
        for (Book &book : books)
        {
            book.serialize(filename);
        }
    }

    void serializeAt(const std::string &filename, std::size_t pos) noexcept
    {
    }

    void deserialize(const std::string &filename)
    {
        std::fstream is(filename, std::ios::in);

        if (!is.good())
        {
            std::string message = "Could not open file with name: ";
            message += filename;
            is.close();
            throw FileNotFoundException(message);
        }

        std::size_t nameSize;
        is.read(reinterpret_cast<char *>(&nameSize), sizeof(std::size_t));
        char *binaryName = new (std::nothrow) char[nameSize + 1];

        if(!binaryName) {
            std::string message = "Could not allocate memory of size: ";
            message += nameSize + 1;
            throw std::runtime_error(message);
        }

        is.read(binaryName, nameSize);

        name = std::string();
        for (size_t i = 0; i < nameSize; i++)
        {
            name.push_back(binaryName[i]);
        }
        delete[] binaryName;

        std::size_t booksSize;
        is.read(reinterpret_cast<char *>(&booksSize), sizeof(std::size_t));
        is.close();
        for (size_t i = 0; i < booksSize; i++)
        {
            Book book;
            book.deserialize(filename);
            books.push_back(book);
        }
    }

    void deserializeAt(const std::string &filename, std::size_t pos)
    {
    }

    void add(const Book &book) noexcept
    {
        books.push_back(book);
    }

    std::size_t getListSize() const noexcept
    {
        return books.size();
    }

    const std::string &getName() const noexcept
    {
        return name;
    }

private:
    std::string name;
    std::vector<Book> books;
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
    
    try
    {
        next.deserialize("book1.bin");
        next.print();
        next.serializeAt("book.bin", 1);

        Library library("Kalin");
        library.add(book);
        library.add(next);
        library.serialize("library.bin");

        Library copy("placeholder");
        copy.deserialize("library1.bin");
        std::cout << copy.getName() << '\n';
    }
    catch (const FileNotFoundException &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}