#pragma once
#ifndef EVENT_H
#define EVENT_H

#include <iostream>

class Event {
private:
    char* date;
    char* time;
    char* name;

public:
    
    Event();
    Event(const char* date, const char* time, const char* name);
    Event(const Event& e);
    ~Event();

    
    Event& operator=(const Event& other);

   
    const char* getDate() const;
    void setDate(const char* date);

    const char* getTime() const;
    void setTime(const char* time);

    const char* getName() const;
    void setName(const char* name);

   
    bool operator==(const Event& other) const;
    bool operator!=(const Event& other) const;

   
    friend std::istream& operator>>(std::istream& in, Event& event);
    friend std::ostream& operator<<(std::ostream& out, const Event& event);
};

#endif // EVENT_H
