#include "../../headers/parking/ParkingSpace.h"

// Constructors
ParkingSpace::ParkingSpace() {
    this->name = "";
    this->num_spots = 0;
}

ParkingSpace::ParkingSpace(string name) {
    this->name = name;
}

ParkingSpace::~ParkingSpace() {
    // Nothing to do here
}

// Getters
string ParkingSpace::get_section() {
    return this->name;
}

int ParkingSpace::get_num_spots() {
    return this->num_spots;
}

User *ParkingSpace::get_user() {
    return this->user;
}

time_t ParkingSpace::get_arrival_time() {
    return this->arrival_time;
}

time_t ParkingSpace::get_departure_time() {
    return this->departure_time;
}

bool ParkingSpace::is_occupied() {
    return this->occupied;
}

// Setters

string ParkingSpace::set_section(string section) {
    this->name = section;
}

void ParkingSpace::set_num_spots(int num_spots) {
    this->num_spots = num_spots;
}

void ParkingSpace::set_user(User* user) {
    this->user = user;
}

void ParkingSpace::set_arrival_time(time_t arrival_time) {
    this->arrival_time = arrival_time;
}

void ParkingSpace::set_departure_time(time_t departure_time) {
    this->departure_time = departure_time;
}

// Other Methods
void ParkingSpace::update() {
    cout << "Updating parking section " << this->name << endl;
}
