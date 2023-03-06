#include <cstring>
#include <iostream>
#include "student.hpp"

bool Student::isValidYear(unsigned year) const {
    return year >= 1 && year <= 4;
}

bool Student::isValidGrade(double grade) const {
    return grade >= 2 && grade <= 6;
}

Student::Student(const char *_name, const char *_fn, unsigned _year, unsigned _group, double _grade)
                : name(new char[strlen(_name) + 1]{'\0'}),
                  fn(new char[strlen(_fn) + 1]{'\0'}),
                  year(1),
                  group(_group),
                  grade(2)
{
    if(isValidYear(_year)) {
        year = _year;
    }

    if(isValidGrade(_grade)) {
        grade = _grade;
    }
    strcpy(name, _name);
    strcpy(fn, _fn);
}

Student::Student(const Student& other)
                : name(new char[strlen(other.name)+1]{'\0'}),
                  fn(new char[strlen(other.fn) + 1]{'\0'}),
                  year(1),
                  group(other.group),
                  grade(2)
{
    year = other.year;

    grade = other.grade;
    
    strcpy(name, other.name);
    strcpy(fn, other.fn);
}

Student& Student::operator=(const Student& other) {
    // Student copy(other);
    // swap(copy);
    if(this != &other) {
        erase();
        copy(other);
    }

    return *this;
}

Student::~Student() {
    erase();
}

void Student::erase() {
    delete[] name;
    delete[] fn;
}

void Student::copy(const Student& other) {
    name = new char[strlen(other.name) + 1]{'\0'};
    fn = new char[strlen(other.fn) + 1]{'\0'};
    strcpy(name, other.name);
    strcpy(fn, other.fn);
    year = other.year;
    group = other.group;
    grade = other.grade;
}

void Student::swap(Student& other) {
    using std::swap;
    swap(name, other.name);
    swap(fn, other.fn);
    swap(year, other.year);
    swap(group, other.group);
    swap(grade, other.grade);
}

const char *Student::getName() const {
    return name;
}

double Student::getGrade() const {
    return grade;
}

void Student::setName(char* _name) {
    strcpy(name, _name);
}

void Student::setYear(unsigned _year) {
    if(isValidYear(_year)) {
        year = _year;
    }
}

void Student::setGrade(double _grade) {
    if(isValidGrade(_grade)) {
        grade = _grade;
    }
}

void Student::print() const {
    std::cout<<"Name: "<<name<<'\n'
             <<"Faculty Number: "<< fn<<'\n'
             <<"Year: "<<year<<'\n'
             <<"Group: "<<group<<'\n'
             <<"Average Grade: "<<grade<<'\n';
}

bool Student::canPass() const {
    return grade >= 3;
}
