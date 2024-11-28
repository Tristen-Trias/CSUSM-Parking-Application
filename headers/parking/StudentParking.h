#ifndef STUDENTPARKING_H
#define STUDENTPARKING_H

#include <string>

#include "Parking.h"
#include "../users/User.h"

using namespace std;

class StudentParking : public Parking {
    public:
        // Constructors and Destructors
        StudentParking();
        StudentParking(string section, int num_spots);
        ~StudentParking();

        // Getters
        string get_section();
        int get_num_spots();
        User* get_user();
        time_t get_arrival_time();
        time_t get_departure_time();
        bool is_occupied();

        // Setters
        string set_section(string section);
        void set_num_spots(int num_spots);
        void set_user(User* user);
        void set_arrival_time(time_t arrival_time);
        void set_departure_time(time_t departure_time);

        // Other Methods
        void update();

    private:
        vector<Parking*> parking_spots;
        string name;
        bool occupied;
        int num_spots;

        User* user;
        time_t arrival_time;
        time_t departure_time;

};

#endif
