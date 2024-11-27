#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include "Parking.h"

using namespace std;

class ParkingLot : public Parking {

    public:
        // Constructors and Destructors
        ParkingLot(string lot);
        ParkingLot();
        ~ParkingLot();

        // Getters
        string get_lot();
        int get_num_sections();

        // Setters
        string set_lot(string lot);
        void set_num_sections(int num_sections);

        // Other Methods
        void update();
        void add(Parking* section);
        Parking* get_parking_section(int section);
        vector<Parking*> get_parking_sections();
    
    private:
        vector<Parking*> parking_sections;
        string name;
        int num_sections;

};

#endif
