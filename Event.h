#pragma once
#ifndef EVENT_H
#define EVENT_H

#include <iostream>

class Event {

private:
unsignet const int id;
    char* date;
    char* time;
    char* name;
static int counter;

public:
    
    Event();
    Event(const char* date, const char* time, const char* name);

   
    ~Event();

  
    Event& operator=(const Event& other);


    friend std::istream& operator>>(std::istream& in, Event& event);

    friend std::ostream& operator<<(std::ostream& out, const Event& event);



   
};
int Event::counter=1;
#endif

