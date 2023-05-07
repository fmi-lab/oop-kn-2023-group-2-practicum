#include <iostream>
#include "event_manager.hpp"

EventManager::EventManager(size_t _capacity) : size(0), capacity(_capacity), events(new Event *[_capacity]) {}

EventManager::EventManager(const EventManager &other) : size(other.size), capacity(other.capacity), events(new Event *[other.capacity])
{
    for (size_t i = 0; i < other.size; i++)
    {
        events[i] = other.events[i]->clone();
    }
}

EventManager::~EventManager()
{
    for (size_t i = 0; i < size; i++)
    {
        delete events[i];
    }
    delete[] events;
}

EventManager &EventManager::operator=(const EventManager &other)
{
    EventManager copy(other);
    swap(copy);
    return *this;
}

void EventManager::swap(EventManager &other)
{
    using std::swap;
    std::swap(size, other.size);
    std::swap(capacity, other.capacity);
    std::swap(events, other.events);
}

bool EventManager::addEvent(Event const *event)
{
    if (size >= capacity)
    {
        return false;
    }

    events[size++] = event->clone();
    return true;
}

size_t EventManager::ongoingEvents(double time) const
{
    size_t result = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (events[i]->getStart() <= time && time <= events[i]->getFinish() && !events[i]->isInIntermission(time))
        {
            ++result;
        }
    }
    return result;
}

Event *EventManager::at(size_t index)
{
    if (index >= 0 && index < size)
    {
        return events[index];
    }
    else {
        return nullptr;
    }
}
