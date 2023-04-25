#ifndef SERIALIZABLE_HPP
#define SERIALIZABLE_HPP

#include <iostream>

//interface
class Serializable {
public:
    virtual std::ostream& serialize(std::ostream& os) const = 0;
    virtual ~Serializable() = default;
};
#endif