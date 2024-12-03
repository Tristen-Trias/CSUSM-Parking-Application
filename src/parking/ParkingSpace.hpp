#ifndef PARKINGSPACE_H
#define PARKINGSPACE_H
#include <iostream>
#include <vector>

#include "ParkingAbstract.hpp"
using namespace std;

// ParkingSpace serves as the "leaf" for the composite pattern for
// ParkingAbstract and ParkingLot (shares display() uniformity)
class ParkingSpace : public Parking {
    int spaceNumber;
    string lot;
    static const int totalTimeSlots =
        17;  // numbrt of time slots from reservation 7am-12am
    bool timeSlots[totalTimeSlots];  //  creates bool array of total hours of
                                     //  time reservation
    bool isSpaceEmpty;
    int reservationEndTime, reservationStartTime;
    int userID;

   public:
    ParkingSpace(string name, int number, bool spaceEmpty = true,
                 const int user = 0) {
        lot = name;
        spaceNumber = number;
        isSpaceEmpty = spaceEmpty;
        for (int i = 0; i < totalTimeSlots; i++) {
            timeSlots[i] = true;
        }
    }

    string getLot() { return lot; }

    int getSpaceNumber() { return spaceNumber; }

    bool getIsSpaceEmpty() { return isSpaceEmpty; }

    int getReservationStartTime() { return reservationStartTime; }

    int getReservationEndTime() { return reservationEndTime; }

    void setSpaceNumber(int number) { spaceNumber = number; }

    void setSpacetoEmpty() { isSpaceEmpty = true; }

    void setSpacetoFull() { isSpaceEmpty = false; }

    void setLot(string lot) { this->lot = lot; }

    int getUserID() { return userID; }

    bool reserveTimeSlot(const int id, int startTime, int endTime) {
        if (startTime < 0 || endTime >= totalTimeSlots) {
            cout << "Time range invalid" << endl;
            return false;
        }

        // Validate availability of the time slots
        for (int i = startTime; i <= endTime; i++) {
            if (!timeSlots[i]) {
                cout << "Time slot between " << startTime + 7 << ":00 and "
                     << endTime + 7 << ":00 is already reserved for space # "
                     << spaceNumber << endl;
                return false;
            }
        }

        // Reserve the time slots
        for (int i = startTime; i <= endTime; i++) {
            timeSlots[i] = false;  // Mark slot as reserved
            // debug log cout << "Slot " << i + 7 << ":00 reserved." << endl;
        }

        updateSpaceStatus();

        userID = id;
        reservationStartTime = startTime + 7;
        reservationEndTime = endTime + 7;

        cout << "Parking Space " << spaceNumber << " reserved by id: " << userID
             << " for " << startTime + 7 << ":00"
             << " through " << endTime + 7 << ":00." << endl;

        return true;
    }

    void clearReservedTimeSlots() {
        for (int i = 0; i < totalTimeSlots; i++) {
            timeSlots[i] = true;
        }
    }

    void updateSpaceStatus() {
        // Assume the space is fully reserved initially
        isSpaceEmpty = false;

        // Check if any time slot is still available
        for (int i = 0; i < totalTimeSlots; i++) {
            if (!timeSlots[i]) {
                // Found an available slot, mark the space as not fully reserved
                isSpaceEmpty = false;
                return;  // Exits early
            }
        }

        // If no available slots are found, the space remains fully reserved
    }

    // Display the parking space information
    void display() override {
        cout << "Displaying Parking Space " << spaceNumber << endl;
        if (isSpaceEmpty) {
            cout << "This space is currently empty." << endl;
        } else {
            cout << "This space is currently occupied."
                 << " Space will be free at " << reservationEndTime << ":00"
                 << endl;
        }
    }
};

#endif
