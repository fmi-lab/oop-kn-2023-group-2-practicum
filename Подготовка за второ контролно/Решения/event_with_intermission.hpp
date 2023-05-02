#ifndef __EVENT_WITH_INTERMISSION_HPP
#define __EVENT_WITH_INTERMISSION_HPP

#include "event.hpp"

class EventWithIntermission : public Event {
private:
    double antractStart;
    double antractFinish;
public:
    EventWithIntermission(double _start = 0, double _finish = 0, double _antractStart = 0, double _antractFinish = 0);
    EventWithIntermission* clone() const final;
    double getAntractStart() const {return antractStart;}
    double getAntractFinish() const {return antractFinish;}
    bool isInIntermission(double time) const final;
};

#endif