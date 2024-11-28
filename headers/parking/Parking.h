#ifndef PARKING_H
#define PARKING_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Parking {
    public:

        // Constructors and Destructors
        Parking();
        ~Parking();

        // Other Methods
        virtual void update();
        virtual void add(Parking* section);
        virtual vector<Parking*> get_parking_sections();

    protected:
        string name;

};

#endif
