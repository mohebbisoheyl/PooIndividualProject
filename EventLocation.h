#ifndef EVENT_LOCATION_H
#define EVENT_LOCATION_H

#include <iostream>

class EventLocation {
public:
    EventLocation();
    EventLocation(int maxSeats, int numRows, const char* zones, int seatsPerRow);
    ~EventLocation();
    EventLocation(const EventLocation& other);
    EventLocation& operator=(const EventLocation& other);

    friend std::istream& operator>>(std::istream& in, EventLocation& eventLocation);
    friend std::ostream& operator<<(std::ostream& out, const EventLocation& eventLocation);

    // Getteri ?i setteri
    int getMaxSeats() const;
    void setMaxSeats(int maxSeats);

    int getNumRows() const;
    void setNumRows(int numRows);

    const char* getZones() const;
    void setZones(const char* zones);

    int getSeatsPerRow() const;
    void setSeatsPerRow(int seatsPerRow);

private:
    int maxSeats;
    int numRows;
    char* zones;
    int seatsPerRow;

    void releaseMemory();
};

#endif // EVENT_LOCATION_H
