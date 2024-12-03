#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include <algorithm>
#include <iostream>
#include <vector>

#include "Observer.hpp"
#include "ParkingAbstract.hpp"
#include "ParkingSpace.hpp"
using namespace std;

// Parking lot serves as the component for the Decorator
// Parking lot serves as a composite between the  parkinglotabstract and
// parkingspace Parking lot serves as subject for obsevers student and faculty

class Subject {
   private:
    vector<Observer*> observers;

   public:
    void registerObserver(Observer* observer) { observers.push_back(observer); }

    void removeObserver(Observer* observer) {
        observers.erase(find(observers.begin(), observers.end(), observer));
    }

    void notify(const string& message) {
        for (int i = 0; i < observers.size(); i++) {
            observers[i]->update(message);
        }
    }
};

class ParkingLot : public Parking, public Subject {
    vector<ParkingSpace> space;   // vector of lots will contain objects of
                                  // spaces from ParkingSpace class
    vector<Observer*> observers;  //  vector will contain list of observers to
                                  //  notify subscribers of changes in lots
    string lotName;               // name of the lot(section)
    int userID;

   public:
    ParkingLot(const string& name) {
        lotName = name;  // name assigned to lotname variable
    }

    void addSpace(ParkingSpace& xspace) {
        space.push_back(xspace);  // add space takes in space object into
                                  // parameter and pushes onto space vector
    }

    // Returns spaces vector
    vector<ParkingSpace> getSpaces() { return space; }

    // returns spaces which are occupied in vector
    vector<ParkingSpace> getOccupiedSpaces() {
        vector<ParkingSpace> occupied;  // local vector "occupied" created to
                                        // hold tracked occupied spaces
        for (int i = 0; i < space.size(); i++) {
            // if space is not empty, push onto occupied vector
            if (!space[i].getIsSpaceEmpty()) {
                occupied.push_back(space[i]);
            }
        }
        return occupied;
    }

    vector<ParkingSpace> getEmptySpaces() {
        vector<ParkingSpace> empty;
        for (int i = 0; i < space.size(); i++) {
            if (space[i].getIsSpaceEmpty()) {
                empty.push_back(space[i]);
            }
        }
        return empty;
    }

    string getLotName() { return lotName; }

    void display() override {
        cout << "Displaying parking lot: " << lotName << endl;
        for (int i = 0; i < space.size(); i++) {
            space[i].display();
        }
    }

    // counts the number emptyspaces in the lot
    int countEmptySpaces() {
        int emptySpace = 0;
        for (int i = 0; i < space.size(); i++) {
            if (space[i].getIsSpaceEmpty()) {
                emptySpace++;
            }
        }
        return emptySpace;
    }

    // counts  the number of full spaces in the lot
    int countFullSpaces() {
        int occupiedSpaces = 0;
        for (int i = 0; i < space.size(); i++) {
            if (space[i].getIsSpaceEmpty()) {
                occupiedSpaces++;
            }
        }
        return occupiedSpaces;
    }

    // reserves space, with the space number
    bool reserveSpace(const int id, int spaceNumber, int startTime,
                      int endTime) {
        bool statFlag = false;
        int fullendTime;

        // iterates through lot vector of spaces
        for (int i = 0; i < space.size(); i++) {
            // condition checks if the entered space number is not empty
            // if true set space to empty
            if (space[i].getSpaceNumber() == spaceNumber &&
                space[i].getIsSpaceEmpty()) {
                if (space[i].reserveTimeSlot(id, startTime, endTime)) {
                    notify("Space " + to_string(spaceNumber) +
                           " reservered by " + to_string(id) + " from " +
                           to_string(startTime + 7) + ":00 " +
                           to_string(endTime + 7) + ":00");
                    return true;
                }
            } else if (space[i].getSpaceNumber() == spaceNumber &&
                       space[i].getIsSpaceEmpty() == false) {
                fullendTime = space[i].getReservationEndTime();
                statFlag = true;
            }
        }

        if (statFlag == true) {
            cout << "Space " << spaceNumber
                 << " is already occupied. will be free to reserve after "
                 << fullendTime << ":00." << endl;
            return false;
        } else {
            cout << "Space " << spaceNumber << " not found."
                 << endl;  // displays to user that space wasnt able to be
                           // reserved or found due  conflict
            return false;  // Return false if the space is not found
        }
    }

    // clears space, with the space number
    void clearSpace(int spaceNumber) {
        for (int i = 0; i < space.size(); i++) {
            if (space[i].getSpaceNumber() == spaceNumber &&
                !space[i].getIsSpaceEmpty()) {
                space[i].clearReservedTimeSlots();
                space[i].setSpacetoEmpty();
                notify("Space " + to_string(spaceNumber) + " is now free.");
                cout << "Space " << spaceNumber << " is now free." << endl;
                return;
            } else {
                notify("Space" + to_string(spaceNumber) + " is not occupied.");
                cout << "Space " << spaceNumber << " is not occupied." << endl;
                return;
            }
            cout << "Space " << spaceNumber
                 << " does not exist. Input correct space number." << endl;
        }
    }

};

#endif
