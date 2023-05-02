#ifndef __EVENT_WITH_FIXED_INTERMISSION_HPP
#define __EVENT_WITH_FIXED_INTERMISSION_HPP

#include "event.hpp"

class EventWithFixedIntermission : public Event {
private:
    double antractStart;
public:
    EventWithFixedIntermission(double _start = 0, double _finish = 0, double _antractStart = 0);
    EventWithFixedIntermission* clone() const final;
    double getAntractStart() const {return antractStart;}
    bool isInIntermission(double time) const final;
};

#endif