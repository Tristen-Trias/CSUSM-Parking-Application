#ifndef STUDENTPARKINGSTRATEGY_H
#define STUDENTPARKINGSTRATEGY_H

#include "ParkingStrategy.hpp"

class StudentParkingStrategy : public ParkingStrategy 
{
    public:
        void park() override 
        {
            cout << "Student is implementing parking their parking strategy\n";
            



            
        }
};

#endif