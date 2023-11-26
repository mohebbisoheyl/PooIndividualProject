#include "eventLocation.h"
#include <string.h>

using namespace std;

EventLocation::EventLocation() : maxSeats(0), numRows(0), numZones(0), zones(nullptr), seatsPerRow(nullptr) {}

EventLocation::EventLocation(int maxSeats, int numRows, int numZones, const std::string* zones, int* seatsPerRow) {
    this->maxSeats = maxSeats;

    if (numRows > 0 && seatsPerRow != nullptr) {
        this->numRows = numRows;
        this->seatsPerRow = new int[numRows];
        for (int i = 0; i < numRows; i++) {
            this->seatsPerRow[i] = seatsPerRow[i];
        }
    }
    else {
        this->numRows = 0;
        this->seatsPerRow = nullptr;
    }

    if (numZones > 0 && zones != nullptr) {
        this->numZones = numZones;
        this->zones = new std::string[numZones];
        for (int i = 0; i < numZones; i++) {
            this->zones[i] = zones[i];
        }
    }
    else {
        this->numZones = 0;
        this->zones = nullptr;
    }
}


EventLocation::~EventLocation() {
    delete[] zones;
    delete[] seatsPerRow;
}

EventLocation::EventLocation(const EventLocation& l){
    this->maxSeats = l.maxSeats;

    if (l.numRows > 0 && l.seatsPerRow != nullptr) {
        this->numRows = l.numRows;
        this->seatsPerRow = new int[l.numRows];
        for (int i = 0; i < l.numRows; i++) {
            this->seatsPerRow[i] = l.seatsPerRow[i];
        }
    }
    else {
        this->numRows = 0;
        this->seatsPerRow = nullptr;
    }
    if (l.numZones > 0 && l.zones != nullptr) {
        this->numZones = l.numZones;
        this->zones = new string[l.numZones];
        for (int i = 0; i < l.numZones; i++) {
            this->zones[i] = l.zones[i];
        }
    }
    else {
        this->numZones = 0;
        this->zones = nullptr;
    }

   
}

EventLocation& EventLocation::operator=(const EventLocation& l) {
    if (this != &l) {
        delete[] zones;
        delete[] seatsPerRow;

        maxSeats = l.maxSeats;
        numRows = l.numRows;
        this->seatsPerRow = new int[l.numRows];
        for (int i = 0; i < l.numRows; i++) {
            this->seatsPerRow[i] = l.seatsPerRow[i];
        }
        numZones = l.numZones;
        this->zones = new string[l.numZones];
        for (int i = 0; i < l.numZones; i++) {
            this->zones[i] = l.zones[i];
        }

       
    }
    return *this;
}

std::istream& operator>>(std::istream& is, EventLocation& eventLocation) {
    cout << "nomax: ";
    is >> eventLocation.maxSeats >> eventLocation.numRows;
    delete[] eventLocation.zones;
    delete[] eventLocation.seatsPerRow;
    cout << "no of zones";
    is >> eventLocation.numZones;
    eventLocation.zones = new string[eventLocation.numZones];
    cout << "zones: ";
 
    for (int i = 0; i < eventLocation.numZones; i++) {
        is >> eventLocation.zones[i];
    } 
    cout << "no of rows";
    is >> eventLocation.numRows;
    eventLocation.seatsPerRow = new int[eventLocation.numRows];
    cout << "seats: ";
    for (int i = 0; i < eventLocation.numRows; i++) {
        is >> eventLocation.seatsPerRow[i];
    }

    return is;
}

 std::ostream& operator<<(std::ostream& os, const EventLocation& eventLocation) {
    os << "Max Seats: " << eventLocation.maxSeats << "endl";
    os << "Num Rows: " << eventLocation.numRows << "endl";
    os << "Num zones: " << eventLocation.numZones << "endl";
    os << "Zones: "  << "endl";
    for (int i = 0; i < eventLocation.numZones; i++) {
        os << eventLocation.zones[i] << " ";
    }
    
    os << "Seats Per Row: ";
    for (int i = 0; i < eventLocation.numRows; i++) {
        os << eventLocation.seatsPerRow[i] << " ";
    }
    os << "endl";

    return os;
}

int EventLocation::getMaxSeats() const {
    return maxSeats;
}

void EventLocation::setMaxSeats(int maxSeats) {
    this->maxSeats = maxSeats;
}

int EventLocation::getNumRows() const {
    return numRows;
}


void EventLocation::setZones(const std::string* newZones, int newNumZones) {
    delete[] zones;
    numZones = newNumZones;
    if (newZones) {
        zones = new std::string[numZones];
        for (int i = 0; i < numZones; i++) {
            zones[i] = newZones[i];
        }
    }
    else {
        zones = nullptr;
    }
}


int*  EventLocation:: getSeatsPerRow()const  {
    return seatsPerRow;
}

void  EventLocation::setSeatsPerRow(int* newSeatsPerRow,int num) {
    delete[] seatsPerRow;
    numRows = num;
    seatsPerRow = new int[numRows];
    for (int i = 0; i < numRows; i++) {
        seatsPerRow[i] = newSeatsPerRow[i];
    }
}

int& EventLocation::operator[](int rowIndex) {

    if (rowIndex < 0 && rowIndex >= numRows) {
        throw std::out_of_range("Invalid row index");
    } 

    return seatsPerRow[rowIndex];
}


int EventLocation::operator()() const {
    int totalSeats = 0;
    for (int i = 0; i < numRows; i++) {
        totalSeats += seatsPerRow[i];
    }
    return totalSeats;
}
