#ifndef PARKINGLOTFACTORY
#define PARKINGLOTFACTORY

#include <iostream>

#include "ParkingLot.hpp"
// single static method in single class turns into simple Factory pattern to
// create Parking lots
class ParkingLotFactory {
   public:
   
    // creates and adds spaces, based on numSpaces input, and
    // sets parking spaces to empty.
    static ParkingLot createParkingLot(const string& name, int numSpaces) {
        ParkingLot lot(name);
        for (int i = 1; i <= numSpaces; i++) {
            ParkingSpace space(name, i, true);
            lot.addSpace(space);
        }
        return lot;
    }
};

#endif

#ifndef PARKINGLOTFACTORY
#define PARKINGLOTFACTORY

#include <iostream>

#include "ParkingLot.hpp"
// single static method in single class turns into simple Factory pattern to
// create Parking lots
class ParkingLotFactory {
   public:
    static ParkingLot createParkingLot(const string& name, int numSpaces) {
        ParkingLot lot(name);  // creates new parking lot object with name
        for (int i = 1; i <= numSpaces;
             i++) {  // creates and adds spaces, based on numSpaces input, and
                     // sets parking spaces to empty.
            ParkingSpace space(i, true);
            lot.addSpace(space);
        }
        return lot;
    }
};

#endif
