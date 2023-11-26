#pragma once
#ifndef TICKET_H
#define TICKET_H

#include "event.h"
#include "eventlocation.h"

class Ticket {
private:
    static int uniqueIdCounter;
    int ticketId;
    Event event;
    EventLocation location;

public:
    static void DisplayCates(int noOfTickets, Ticket* t);
    int getTicketId() const;
    const Event& getEvent() const;
    const EventLocation& getLocation() const;
   
    void setEvent(const Event& ev);
    void setLocation(const EventLocation& location);
   
    Ticket();
    Ticket(const Event& event, const EventLocation& location);
    bool operator<(const Ticket& other) const;
    bool operator>(const Ticket& other) const;
    
    friend std::ostream& operator<<(std::ostream& os, const Ticket& ticket);
    friend std::istream& operator>>(std::istream& is, Ticket& ticket);

  static void DisplayDates(int noOfTickets, Ticket* t);

};

#endif // TICKET_H

