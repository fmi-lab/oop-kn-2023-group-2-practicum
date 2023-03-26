#ifndef MY_STRING_HPP
#define MY_STRING_HPP

#include <iostream>

class MyString {
private:
    char* str;
public:
    MyString(const char* _str = "");
    MyString(const MyString&);
    ~MyString();
    MyString& operator=(const MyString&);

    size_t length() const;
    bool operator==(const MyString&) const;
    bool operator<(const MyString&) const;
    friend std::ostream& operator<<(std::ostream&, const MyString&);
};

#endif