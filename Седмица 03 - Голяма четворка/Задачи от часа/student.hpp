// #pragma once
#ifndef __STUDENT_HPP
#define __STUDENT_HPP

class Student {
private:
    char* name;
    char* fn;
    unsigned year;
    unsigned group;
    double grade;

    bool isValidYear(unsigned year) const;
    bool isValidGrade(double grade) const;

    void erase();
    void copy(const Student& other);
public:
    Student(const char* _name = "<anonymous>",
            const char* _fn = "<fn>",
            unsigned _year = 1,
            unsigned _group = 1,
            double _grade = 2);
    Student(const Student& other); // copy constructor
    Student& operator=(const Student& other); // assignment operator
    ~Student(); // destructor

    void swap(Student& other);

    const char* getName() const;
    double getGrade() const;

    void setName(char* _name);
    void setYear(unsigned _year);
    void setGrade(double _grade);

    void print() const;
    bool canPass() const;
};

#endif