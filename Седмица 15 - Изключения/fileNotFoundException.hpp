#ifndef FILE_NOT_FOUND_EXCEPTION_HPP
#define FILE_NOT_FOUND_EXCEPTION_HPP

#include <exception>
#include <string>

class FileNotFoundException : public std::exception {
private:
    std::string message;
public:
    FileNotFoundException(const std::string& _message) : message(_message) {}

    const char* what() const noexcept final {
        return message.c_str();    
    }
};

#endif