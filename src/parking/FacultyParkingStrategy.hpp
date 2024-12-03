#ifndef FACULTYPARKINGSTRATEGY_H
#define FACULTYPARKINGSTRATEGY_H

#include "ParkingStrategy.hpp"

class FacultyParkingStrategy : public ParkingStrategy 
{
    public:
        void park() override 
        {
            cout << "Faculty is imlementing faculty parking strategy\n";
            




        }
};

#endif