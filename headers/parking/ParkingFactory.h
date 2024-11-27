#ifndef PARKINGFACTORY_H
#define PARKINGFACTORY_H

#include <string>
#include <iostream>

#include "StudentParking.h"
#include "FacultyParking.h"
#include "VisitorParking.h"

using namespace std;

class ParkingFactory {
   public:
    void create_parking_lot(string name, int sections);
    void create_parking_lot(string name);
};

#endif