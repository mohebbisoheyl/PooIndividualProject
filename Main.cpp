#include "ticket.h"
#include "event.h"
#include "eventLocation.h"
#include <iostream>

using namespace std;


void main() {
    Event ev;
    cout << ev<< endl;

    Event event("Concert", "2023-12-01", "Artist Name");
    cout << event << endl;

    Event event1(event);
    cout << event1 << endl;

    ev = event1;
    cout << ev << endl;

    ev.setDate("25.11.2023");
    ev.setTime("21:00");
    ev.setName("Craciun");

    cout << ev.getDate() << endl;
    cout << ev.getTime() << endl;
    cout << ev.getName() << endl;

    if (ev == event) {
        cout << "DA" << endl;
    }
    else cout << "NU" << endl;

    if (ev != event) {
        cout << "DA" << endl;
    }
    else cout << "NU" << endl;



    EventLocation location1;
    cout << location1 << endl;
    EventLocation location(100, 3, 2, new string[2]{ "zone1","zone2" }, new int[3]{ 10,15,10 });
    cout << location << endl;
    EventLocation location2(location);
    cout << location2 << endl;
    location1 = location;
    cout << location1 << endl;
    location1.setMaxSeats(120);
    location1.setSeatsPerRow( new int[3]{10,10,10},3);
    location1.setZones(new string[3]{"Z1","Z2","Z3"},3);
    cout << location1.getMaxSeats()<<endl;
    cout << location1.getNumRows()<<endl;
    cout << location1.getSeatsPerRow()<<endl;


    std::cout << "Seats in row 2: " << location[1] << std::endl;
    std::cout << "Total seats in the venue: " << location() << std::endl;


   
   Ticket ticket;
   cout << ticket << endl;
   Ticket ticket1(ev, location1);
   cout << ticket1 << endl;
   Ticket tk2(ticket1);
   cout << tk2 << endl;
   tk2 = ticket;
   cout << tk2 << endl;
   if (tk2 < ticket1) {
       cout << "DA" << endl;
   }
   else cout << "NU" << endl;

   if (tk2 > ticket) {
       cout << "DA" << endl;
   }
   else cout << "NU" << endl;


   
   int id = tk2.getTicketId();
   const Event& eventInfo = tk2.getEvent();
   const EventLocation& locationInfo = tk2.getLocation();
   
   cout << id;
   cout << eventInfo;
   cout << locationInfo;

  
    tk2.setEvent(ev);
    tk2.setLocation(location1);

 
    cout << tk2.getEvent();
   cout << tk2.getLocation();
   
   const int noOfTickets = 3;  
   Ticket tickets[noOfTickets]; 

   Ticket::DisplayDates(noOfTickets, tickets);



   cin >> ev;
   cin >> location;
   cin >> tk2;

   

}
