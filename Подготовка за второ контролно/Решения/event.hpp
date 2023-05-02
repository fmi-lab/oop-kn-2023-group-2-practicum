#ifndef __EVENT_HPP
#define __EVENT_HPP

//time is in double since I dont have time to make new class for it - 1 hour is 1.00, 1 hour 30 min is 1.50
class Event {
private:
    double start;
    double finish;
public:
    Event(double _start = 0, double _finish = 0) : start(_start), finish(_finish) {}
    virtual ~Event() = default;
    virtual Event* clone() const = 0;
    double getStart() const {return start;}
    double getFinish() const {return finish;}
    virtual bool isInIntermission(double time) const = 0;
    void setStart(double _start) {start = _start;}
    void setFinish(double _finish) {finish = _finish;}
};

#endif