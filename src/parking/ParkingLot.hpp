#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include <iostream>
#include <vector>

#include "ParkingAbstract.hpp"
#include "ParkingSpace.hpp"
using namespace std;

class ParkingLot : public Parking {
    std::vector<ParkingSpace> space;  // vector of lots will contain objects of
                                      // spaces from ParkingSpace class
    string lotName;                   // name of the lot(section)
    int userID;

   public:
    ParkingLot(const string& name) {
        lotName = name;  // name assigned to lotname variable
    }

    void addSpace(ParkingSpace& xspace) {
        space.push_back(xspace);  // add space takes in space object into
                                  // parameter and pushes onto space vector
    }

    vector<ParkingSpace>& getSpaces()  // retrieves spaces in vector
    {
        return space;
    }

    vector<ParkingSpace>
    getOccupiedSpaces()  // returns spaces which are occupied in vector
    {
        vector<ParkingSpace> occupied;  // local vector "occupied" created to
                                        // hold tracked occupied spaces
        for (int i = 0; i < space.size(); i++)  // iterators for space vector
        {
            if (!space[i].getIsSpaceEmpty())  // if condition uses
                                              // getIsSpaceEmpty function to
                                              // verify that its NOT empty
            {
                occupied.push_back(
                    space[i]);  // if grabs occupied spaes and pushes it onto
                                // the occupied vector to later be displayed
                                // back to user
            }
        }
        return occupied;  // returns the object of occupied spaces in the space
                          // vector
    }

    vector<ParkingSpace> getEmptySpaces()  // returns empty spaces in vector
    {
        vector<ParkingSpace> empty;
        for (int i = 0; i < space.size(); i++) {
            if (space[i].getIsSpaceEmpty()) {
                empty.push_back(space[i]);
            }
        }
        return empty;
    }

    string getLotName() { return lotName; }

    // Displays the parking lot
    void display() override {
        cout << "Displaying parking lot: " << lotName << endl;  //
        for (int i = 0; i < space.size(); i++) {
            space[i].display();
        }
    }

    // Counts the number of empty spaces in the lot
    int countEmptySpaces() {
        int emptySpace = 0;
        for (int i = 0; i < space.size(); i++) {
            if (space[i].getIsSpaceEmpty()) {
                emptySpace++;
            }
        }
        return emptySpace;
    }

    // Counts the number of full spaces in the lot
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
    bool reserveSpace(int id, int spaceNumber, int startTime, int endTime) {
        bool statFlag = false;
        int fullendTime;
        for (int i = 0; i < space.size(); i++) {
            // condition checks if the entered
            // space number is empty if so, reserve
            // by setting space to occupied

            if (space[i].getSpaceNumber() == spaceNumber &&
                space[i].getIsSpaceEmpty()) {
                return space[i].reserveTimeSlot(id, startTime, endTime);
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

    // clears the reserve spot with number in spot
    bool clearSpace(int spaceNumber) {

         // iterates through lot vector of spaces
        for (int i = 0; i < space.size(); i++) {
            if (space[i].getSpaceNumber() == spaceNumber &&
                !space[i].getIsSpaceEmpty())  // condition checks if the entered
                                              // space number is not empty, if
                                              // true set space to empty
            {
                space[i].setSpacetoEmpty();
                cout << "Space #" << spaceNumber << " is now free." << endl;
                return false;
            }
        }
    }

    // string getName() const override
    // {
    //   return lotName;
    //}
};

#endif
