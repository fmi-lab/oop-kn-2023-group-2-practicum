#include <iostream>
#include "event_with_fixed_intermission.hpp"

EventWithFixedIntermission::EventWithFixedIntermission(double _start, double _finish, double _antractStart) : Event(_start, _finish), antractStart(_antractStart)
{
    if(_finish - _start > 4.33 || _start > 24 || _finish > 24 || _start < 0 || _finish < 0 || _antractStart > 24 || _antractStart < 0) {
        std::cout<<"Invalid Time!\n";
        setStart(0);
        setFinish(0);
        antractStart = 0;
    }
}

EventWithFixedIntermission *EventWithFixedIntermission::clone() const
{
    return new EventWithFixedIntermission(*this);
}
bool EventWithFixedIntermission::isInIntermission(double time) const
{
    if(time >= antractStart && time <= antractStart+0.33) {
        return true;
    }
    return false;
}
