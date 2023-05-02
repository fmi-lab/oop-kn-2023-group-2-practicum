#ifndef __SIMPLE_EVENT_HPP
#define __SIMPLE_EVENT_HPP

#include "event.hpp"

class SimpleEvent : public Event {
public:
    SimpleEvent(double _start = 0, double _finish = 0);
    SimpleEvent* clone() const final;
    bool isInIntermission(double time) const final { return false;}
};

#endif