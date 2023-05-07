#ifndef __EVENT_MANAGER_HPP
#define __EVENT_MANAGER_HPP

#include "event.hpp"

class EventManager {
private:
    Event** events;
    size_t size;
    size_t capacity;
public:
    EventManager(size_t _capacity = 0);
    EventManager(const EventManager& other);
    ~EventManager();
    EventManager& operator=(const EventManager& other);
    void swap(EventManager& other);

    bool addEvent(Event const* event);
    size_t ongoingEvents(double time) const;
    size_t getSize() const {return size;}
    Event* at(size_t index);
};

#endif