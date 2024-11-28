#include "../../headers/parking/ParkingSpace.h"

// Constructors
ParkingSpace::ParkingSpace() {
    this->name = "";
    this->id = 0;
}

ParkingSpace::ParkingSpace(string name, int id) {
    this->name = name;
    this->id = id;
}

ParkingSpace::~ParkingSpace() {
    // Nothing to do here
}

// Getters
string ParkingSpace::get_section() {
    return this->name;
}

int ParkingSpace::get_id() {
    return this->id;
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

void ParkingSpace::set_section(string section) {
    this->name = section;
}

void ParkingSpace::set_id(int id) {
    this->id = id;
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
