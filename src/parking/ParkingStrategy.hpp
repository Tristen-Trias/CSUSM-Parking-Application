#ifndef PARKINGSTRATEGY_H
#define PARKINGSTRATEGY_H

#include <iostream>
using namespace std;

class ParkingStrategy {
    public:
        // pur virtual fxn defines interface for parking behavior
        virtual void park() = 0;  
};

#endif