#ifndef ADMINPARKINGSTRATEGY_H
#define ADMINPARKINGSTRATEGY_H

#include "ParkingStrategy.hpp"

class AdminParkingStrategy : public ParkingStrategy 
{
    public:
        void park() override 
        {
            cout << "Implementing administrator parking strategy\n";
            


            
        }
};

#endif