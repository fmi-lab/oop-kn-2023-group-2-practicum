// link to the exam: https://learn.fmi.uni-sofia.bg/mod/assign/view.php?id=205744

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector>

template <typename T>
class Set
{
public:
    virtual bool member(const T &x) const = 0;
    virtual ~Set() = default;
    virtual Set<T> *clone() const = 0;
};

template <typename T>
class Range : public Set<T>
{
public:
    Range(const T &_a, const T &_b) : a(_a), b(_b)
    {
        if (a > b)
        {
            throw std::invalid_argument("Range start can not be bigger than range end");
        }
    }
    bool member(const T &x) const final
    {
        return a <= x && x <= b;
    }
    Range<T> *clone() const final
    {
        return new Range<T>(*this);
    }

private:
    T a, b;
};

class EvenNumbers : public Set<int>
{
public:
    bool member(const int &x) const final
    {
        return x % 2 == 0;
    }
    EvenNumbers *clone() const final
    {
        return new EvenNumbers(*this);
    }
};

template <typename T>
class Container : public Set<T>
{
public:
    bool member(const T &x) const final
    {
        // return std::any_of(data, data + size, [&](const T& el){
        //     return el == x;
        // });

        for (std::size_t i = 0; i < size; i++)
        {
            if (data[i] == x)
            {
                return true;
            }
        }
        return false;
    }

    Container(std::size_t _capacity = 0) : size(0), capacity(_capacity), data(new T[_capacity]) {}
    Container(const Container<T> &other) : size(other.size), capacity(other.capacity),
                                           data(new T[other.capacity])
    {
        for (std::size_t i = 0; i < other.size; i++)
        {
            data[i] = other.data[i];
        }
    }
    Container(Container<T> &&other) : size(other.size), capacity(other.capacity), data(other.data)
    {
        other.size = 0;
        other.data = nullptr;
    }
    Container<T> &operator=(const Container<T> &other)
    {
        Container<T> copy(other);
        swap(copy);
        return *this;
    }
    Container<T> &operator=(Container<T> &&other)
    {
        Container<T> copy(std::move(other));
        swap(copy);
        return *this;
    }
    ~Container()
    {
        delete[] data;
    }

    void add(const T &element)
    {
        if (size == capacity)
        {
            resize();
        }

        if (!member(element))
            data[size++] = element;
    }

    Container<T> operator+(const Container<T> &other) const
    {
        Container<T> result;
        for (std::size_t i = 0; i < size; i++)
        {
            result.add(data[i]);
        }
        for (std::size_t i = 0; i < other.size; i++)
        {
            result.add(other.data[i]);
        }
        return result;
    }

    bool operator<=(const Container<T> &other) const
    {
        for (std::size_t i = 0; i < size; i++)
        {
            if (!other.member(data[i]))
            {
                return false;
            }
        }
        return true;
    }

    Container<T> *clone() const final
    {
        return new Container<T>(*this);
    }

    class Iterator
    {
    private:
        T *pointer;

    public:
        Iterator(T *_pointer = nullptr) : pointer(_pointer) {}
        Iterator &operator++()
        {
            // return Iterator(pointer + 1);
            pointer++;
            return *this;
        }
        bool operator!=(const Iterator &other) const
        {
            return pointer != other.pointer;
        }
        T &operator*()
        {
            return *pointer;
        }
        const T &operator*() const
        {
            return *pointer;
        }
    };

    Iterator begin() const
    {
        return Iterator(data);
    }

    Iterator end() const
    {
        return Iterator(data + size);
    }

private:
    std::size_t size, capacity;
    T *data;

    void swap(Container<T> &other)
    {
        using std::swap;

        swap(size, other.size);
        swap(capacity, other.capacity);
        swap(data, other.data);
    }

    void resize()
    {
        if (!capacity)
        {
            capacity = 1;
        }

        capacity *= 2;
        T *newData = new T[capacity];
        for (std::size_t i = 0; i < size; i++)
        {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
};

template <typename T>
class ManySets : public Set<T>
{
public:
    bool member(const T &x) const final
    {
        for (std::size_t i = 0; i < data.size(); i++)
        {
            if (!data[i]->member(x))
            {
                return false;
            }
        }
        return true;
    }

    ManySets() = default;
    ManySets(const ManySets<T> &other) : data(other.data)
    {
        for (std::size_t i = 0; i < other.data.size(); i++)
        {
            data[i] = other.data[i]->clone();
        }
    }
    ManySets(ManySets<T> &&other) : data(other.data)
    {
        other.data.clear();
    }
    ManySets<T> &operator=(const ManySets<T> &other)
    {
        ManySets<T> copy(other);
        swap(copy);
        return *this;
    }
    ManySets &operator=(ManySets<T> &&other)
    {
        ManySets<T> copy(std::move(other));
        swap(copy);
        return *this;
    }
    ~ManySets()
    {
        for (std::size_t i = 0; i < data.size(); i++)
        {
            delete data[i];
        }
    }

    ManySets<T> *clone() const final
    {
        return new ManySets<T>(*this);
    }

    void add(const Set<T> &element)
    {
        data.push_back(element.clone());
    }

private:
    std::vector<Set<T> *> data;

    void swap(ManySets<T> &other)
    {
        using std::swap;

        swap(data, other.data);
    }
};

template <typename T>
struct Node {
    T data;
    Node* next;
    Node(const T& _data, Node* _next = nullptr) : data(_data), next(_next) {}
};

template <typename T>
bool unique(Node<T>* list) {
    Node<T>* current = list;
    while (current)
    {
        Node<T>* inner = current->next;
        while (inner)
        {
            if(inner->data == current->data) {
                return false;
            }
            inner = inner->next;
        }
        current = current->next;
    }
    return true;
}

int main()
{
    Container<int> set;
    set.add(5);
    set.add(7);
    set.add(2);
    set.add(6);
    set.add(5);

    EvenNumbers even;
    ManySets<int> many;
    try
    {
        Range<int> range(3, 8);
        many.add(range);
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << e.what() << '\n';
    }

    many.add(set);
    many.add(even);
    ManySets<int> too_many;
    too_many.add(many);
    Container<int> container;
    container.add(6);
    container.add(8);
    too_many.add(container);

    try
    {
        Range<int> second(5, 3);
        too_many.add(second);   
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << std::boolalpha << too_many.member(6) << '\n';

    Node<int>* list = new Node<int>(5, new Node<int>(7, new Node<int>(4, new Node<int>(5))));
    std::cout<<std::boolalpha<<unique(list)<<'\n';

    while (list)
    {
        Node<int>* next = list->next;
        delete list;
        list = next;
    }
    
    return 0;
}