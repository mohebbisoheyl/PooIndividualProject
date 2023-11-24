#include "eventLocation.h"
#include <cstring>

EventLocation::EventLocation() : maxSeats(0), numRows(0), zones(nullptr), seatsPerRow(0) {}

EventLocation::EventLocation(int maxSeats, int numRows, const char* zones, int seatsPerRow) : maxSeats(maxSeats), numRows(numRows), seatsPerRow(seatsPerRow) {
    if (zones) {
        this->zones = new char[strlen(zones) + 1];
        strcpy(this->zones, zones);
    }
}

EventLocation::~EventLocation() {
    releaseMemory();
}

EventLocation::EventLocation(const EventLocation& other) : maxSeats(other.maxSeats), numRows(other.numRows), seatsPerRow(other.seatsPerRow) {
    if (other.zones) {
        this->zones = new char[strlen(other.zones) + 1];
        strcpy(this->zones, other.zones);
    }
}

EventLocation& EventLocation::operator=(const EventLocation& other) {
    if (this != &other) {
        releaseMemory();

        maxSeats = other.maxSeats;
        numRows = other.numRows;
        seatsPerRow = other.seatsPerRow;

        if (other.zones) {
            this->zones = new char[strlen(other.zones) + 1];
            strcpy(this->zones, other.zones);
        }
    }

    return *this;
}

std::istream& operator>>(std::istream& in, EventLocation& eventLocation) {
    // Implementarea citirii de la tastatură a atributele obiectului
    return in;
}

std::ostream& operator<<(std::ostream& out, const EventLocation& eventLocation) {
    // Implementarea afișării atributele obiectului în consolă
    return out;
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

void EventLocation::setNumRows(int numRows) {
    this->numRows = numRows;
}

const char* EventLocation::getZones() const {
    return zones;
}

void EventLocation::setZones(const char* zones) {
    if (zones) {
        this->zones = new char[strlen(zones) + 1];
        strcpy(this->zones, zones);
    }
}

int EventLocation::getSeatsPerRow() const {
    return seatsPerRow;
}

void EventLocation::setSeatsPerRow(int seatsPerRow) {
    this->seatsPerRow = seatsPerRow;
}

void EventLocation::releaseMemory() {
    delete[] zones;
}
