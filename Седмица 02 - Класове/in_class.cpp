#include <iostream>

class Triangle
{
private:
    float a;
    float b;
    float c;

    bool valid_side(const float &side) const
    {
        return side > 0;
    }
    bool valid_triangle(const float &a, const float &b, const float &c) const
    {
        return (a + b > c && b + c > a && a + c > b);
    }

public:
    Triangle(const float &_a = 1, const float &_b = 1,
             const float &_c = 1) : a(1), b(1), c(1)
    {
        std::cout << "Triangle(a, b, c)\n";
        if (valid_triangle(_a, _b, _c))
        {
            a = _a;
            b = _b;
            c = _c;
        }
        // a = _a;
        // b = _b;
        // c = _c;
    }

    Triangle(const Triangle &other)
        : a(other.a), b(other.b), c(other.c)
    {
        std::cout << "Triangle(const Triangle& other)\n";
    }

    Triangle &operator=(const Triangle &other)
    {
        std::cout << "Triangle& operator=(const Triangle& other)\n";
        // Triangle copy(other);
        // swap(copy);

        if (this != &other)
        {
            a = other.a;
            b = other.b;
            c = other.c;
        }

        return *this;
    }

    void swap(Triangle &other)
    {
        std::swap(a, other.a);
        std::swap(b, other.b);
        std::swap(c, other.c);
    }

    void set_a(const float &_a)
    {
        if (valid_side(_a) && valid_triangle(_a, b, c))
        {
            a = _a;
        }
    }

    float get_a() const
    {
        return a;
    }

    void set_b(const float &_b)
    {
        if (valid_side(_b) && valid_triangle(a, _b, c))
        {
            b = _b;
        }
    }

    float get_b() const
    {
        return b;
    }

    void set_c(const float &_c)
    {
        if (valid_side(_c) && valid_triangle(a, b, _c))
        {
            c = _c;
        }
    }

    float get_c() const
    {
        return c;
    }

    void print() const
    {
        std::cout << get_a() << ' ' << get_b() 
                  << ' ' << get_c() << '\n';
    }
};

int main()
{
    Triangle t1;
    Triangle t2(20, 25, 30);
    Triangle t3(t1);
    Triangle t4;
    t4 = t4;
    t1.set_a(25.05);
    t1.set_b(25.05);
    t1.set_c(25.05);
    // std::cout<<t3.get_a()<<std::endl;
    // std::cout<<t3.get_b()<<std::endl;
    // std::cout<<t3.get_c()<<std::endl;
    // print(t2);
    t4.print();
}