#include <iostream>
#include "simple_event.hpp"

SimpleEvent::SimpleEvent(double _start, double _finish) : Event(_start, _finish)
{
    if(_finish - _start > 2 || _start > 24 || _finish > 24 || _start < 0 || _finish < 0) {
        std::cout<<"Invalid Time!\n";
        setStart(0);
        setFinish(0);
    }
}
SimpleEvent *SimpleEvent::clone() const
{
    return new SimpleEvent(*this);
}