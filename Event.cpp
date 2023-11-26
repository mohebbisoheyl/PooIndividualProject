#include "event.h"
#include <cstring>

  
Event::Event() {
    
        this->date = new char[strlen("date") + 1];
        strcpy(this->date, "date");
        this->time = new char[strlen("time") + 1];
        strcpy(this->time, "time");
        this->name = new char[strlen("name") + 1];
        strcpy(this->name, "name");

    
}

Event::Event(const char* date, const char* time, const char* name) : date(nullptr), time(nullptr), name(nullptr) {
    if (date) {
        this->date = new char[strlen(date) + 1];
        strcpy(this->date, date);
    }

    if (time) {
        this->time = new char[strlen(time) + 1];
        strcpy(this->time, time);
    }

    if (name) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
}

Event::Event(const Event& other) :  date(other.date),time(other.time), name(other.name) {
    if (date) {
        this->date = new char[strlen(other.date) + 1];
        strcpy(this->date, other.date);
    }

    if (time) {
        this->time = new char[strlen(other.time) + 1];
        strcpy(this->time, other.time);
    }

    if (name) {
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
    }
}

Event::~Event() {
    delete[] date;
    delete[] time;
    delete[] name;
}

  
Event& Event::operator=(const Event& other) {
    if (this != &other) {
        delete[] date;
        delete[] time;
        delete[] name;


        if (other.date) {
            date = new char[strlen(other.date) + 1];
            strcpy(date, other.date);
        }

        if (other.time) {
            time = new char[strlen(other.time) + 1];
            strcpy(time, other.time);
        }

        if (other.name) {
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
        }
    }

    return *this;
}


std::istream& operator>>(std::istream& in, Event& event) {
    char buffer[100];

    std::cout << "Enter date: ";
    in >> buffer;
    event.date = new char[strlen(buffer) + 1];
    strcpy(event.date, buffer);

    std::cout << "Enter time: ";
    in >> buffer;
    event.time = new char[strlen(buffer) + 1];
    strcpy(event.time, buffer);

    std::cout << "Enter name: ";
    in >> buffer;
    event.name = new char[strlen(buffer) + 1];
    strcpy(event.name, buffer);

    return in;
}
//commit : add get set & op== op!=
const char* Event::getDate() const {
    return date;
}

void Event::setDate(const char* date) {
  
    delete[] this->date;

    
    if (date) {
        this->date = new char[strlen(date) + 1];
        strcpy(this->date, date);
    }
    else {
        this->date = nullptr;
    }
}

const char* Event::getTime() const {
    return time;
}

void Event::setTime(const char* time) {
    
    delete[] this->time;

   
    if (time) {
        this->time = new char[strlen(time) + 1];
        strcpy(this->time, time);
    }
    else {
        this->time = nullptr;
    }
}

const char* Event::getName() const {
    return name;
}

void Event::setName(const char* name) {
    
    delete[] this->name;

    
    if (name) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
    else {
        this->name = nullptr;
    }
}


bool Event::operator==(const Event& other) const {
    return strcmp(date, other.date) == 0 && strcmp(time, other.time) == 0 && strcmp(name, other.name) == 0;
}

bool Event::operator!=(const Event& other) const {
    return !(*this == other);
}


std::ostream& operator<<(std::ostream& out, const Event& event) {
    out << "Date: " << event.date << ", Time: " << event.time << ", Name: " << event.name;
    return out;
}



