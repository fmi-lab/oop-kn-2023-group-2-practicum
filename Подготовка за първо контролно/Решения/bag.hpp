#ifndef BAG_HPP
#define BAG_HPP

#include <cstddef>
#include <cstring>
#include <iostream>

template <typename T>
class Bag
{
private:
    T *arr;
    char *producer;
    std::size_t size, capacity;

    void resize();
    void copy(const Bag &other);
    void destroy();

public:
    Bag(const char *_producer, std::size_t _capacity = 0);
    Bag(const Bag &other);
    ~Bag();
    Bag &operator=(const Bag &other);

    void add(const T &element);
    T get();
    Bag operator+(const Bag &other) const;

    template <typename V>
    friend std::ostream& operator<<(std::ostream& os, const Bag<V>& other);

    template <typename V>
    bool operator==(const Bag<V> &other) const;
};

template <typename T>
void Bag<T>::resize()
{
    if (capacity == 0)
        capacity = 1;
    capacity = capacity * 2;
    T *newArr = new T[capacity];

    for (size_t i = 0; i < size; i++)
    {
        newArr[i] = arr[i];
    }

    delete[] arr;
    arr = newArr;
}

template <typename T>
void Bag<T>::copy(const Bag &other)
{
    size = other.size;
    capacity = other.capacity;
    producer = new char[strlen(other.producer) + 1];
    strcpy(producer, other.producer);
    arr = new T[other.capacity];
    for (size_t i = 0; i < other.size; i++)
    {
        arr[i] = other.arr[i];
    }
}

template <typename T>
void Bag<T>::destroy()
{
    delete[] arr;
    delete[] producer;
}

template <typename T>
Bag<T>::Bag(const char *_producer, std::size_t _capacity)
    : capacity(_capacity), size(0), producer(new char[strlen(_producer) + 1]),
      arr(new T[_capacity])
{
    strcpy(producer, _producer);
}

template <typename T>
Bag<T>::Bag(const Bag &other)
{
    copy(other);
}

template <typename T>
Bag<T>::~Bag()
{
    destroy();
}

template <typename T>
Bag<T> &Bag<T>::operator=(const Bag<T> &other)
{
    if (this != &other)
    {
        destroy();
        copy(other);
    }
    return *this;
}

template <typename T>
void Bag<T>::add(const T &element)
{
    if (size == capacity)
    {
        resize();
    }

    arr[size++] = element;
}

template <typename T>
T Bag<T>::get()
{
    T result = arr[--size];
    arr[size] = T(); // int a = int() -> 0 <=> int a{} = 0
    return result;
}

template <typename T>
Bag<T> Bag<T>::operator+(const Bag &other) const
{
    Bag<T> result = *this; // <=> Bag<T> result(*this);
    Bag<T> copy(other);

    while(copy.size)
    {
        result.add(copy.get());
    }

    return result;
}

template <typename T>
template <typename V>
bool Bag<T>::operator==(const Bag<V> &other) const
{
    if(size != other.size){
        return false;
    }

    for (size_t i = 0; i < size; i++)
    {
        if(arr[i] != other.arr[i]) {
            return false;
        }
    }
    
    return true;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Bag<T>& other) {
    for (size_t i = 0; i < other.size; i++)
    {
        os << other.arr[i]<<'\n';
    }
    return os;
}

#endif