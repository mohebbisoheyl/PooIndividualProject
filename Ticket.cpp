#include "ticket.h"
#include <iostream>
#include <cstdlib>  


#include "Ticket.h" // Asigurați-vă că includeți fișierul header corespunzător pentru clasa Ticket

int Ticket::uniqueIdCounter = 0;

Ticket::Ticket() : ticketId(++uniqueIdCounter) {}

Ticket::Ticket(const Event& ev, const EventLocation& location) : event(ev), location(location) {
    ticketId = ++uniqueIdCounter;
}

std::ostream& operator<<(std::ostream& os, const Ticket& ticket) {
    os << "Ticket ID: " << ticket.ticketId ;
    os << "Event Details: " << ticket.event ;
    os << "Location Details: " << ticket.location ;
    return os;
}

std::istream& operator>>(std::istream& is, Ticket& ticket) {
    
     is >> ticket.event;       
     is >> ticket.location;   
    return is;
}

int Ticket::getTicketId() const {
    return ticketId;
}

const Event& Ticket::getEvent() const {
    return event;
}

bool Ticket::operator<(const Ticket& other) const {
    return ticketId < other.ticketId;
}

const EventLocation& Ticket::getLocation() const {
    return location;
}



void Ticket::setEvent(const Event& ev) {
    event = ev;
}


void Ticket::setLocation(const EventLocation& loc) {
    location = loc;
}


bool Ticket::operator>(const Ticket& other) const {
    return ticketId > other.ticketId;
}

void Ticket::DisplayDates(int noOfTickets, Ticket* t) {
    for (int i = 0; i < noOfTickets; i++) {
        cout << t[i].getEvent().getDate() << std::endl;
    }
}
