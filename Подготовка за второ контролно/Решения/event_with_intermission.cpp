#include <iostream>
#include "event_with_intermission.hpp"

EventWithIntermission::EventWithIntermission(double _start, double _finish, double _antractStart, double _antractFinish) : Event(_start, _finish), antractStart(_antractStart), antractFinish(_antractFinish)
{
    if (_antractFinish - _antractStart > 1 || _antractFinish - _antractStart < 0.5 || _finish - _start - (_antractFinish - _antractStart) > 6  || _start > 24 || _finish > 24 || _start < 0 || _finish < 0 || _antractStart > 24 || _antractStart < 0 || _antractFinish < 0 || _antractFinish > 24)
    {
        std::cout << "Invalid Time!\n";
        setStart(0);
        setFinish(0);
        antractStart = 0;
        antractFinish = 0;
    }
}
EventWithIntermission *EventWithIntermission::clone() const
{
    return new EventWithIntermission(*this);
}
bool EventWithIntermission::isInIntermission(double time) const
{
    if (time >= antractStart && time <= antractFinish)
    {
        return true;
    }
    return false;
}