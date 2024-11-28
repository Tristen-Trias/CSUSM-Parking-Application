#ifndef PARKINGSECTION_H
#define PARKINGSECTION_H

#include "Parking.h"

using namespace std;

class ParkingSection : public Parking {

    public:
        // Constructors and Destructors
        ParkingSection();
        ParkingSection(string section);
        ~ParkingSection();

        // Getters
        string get_section();
        int get_num_spots();

        // Setters
        void set_section(string section);
        void set_num_spots(int num_spots);

        // Other Methods
        void update();
        Parking* get_parking_spot(int spot);

    private:
        vector<Parking*> parking_spots;
        string name;
        int num_spots;

};

#endif
