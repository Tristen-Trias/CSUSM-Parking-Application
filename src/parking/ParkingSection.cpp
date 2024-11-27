#include "ParkingSection.h"

// Constructors
ParkingSpace::ParkingSpace(string section) {
    this->name = section;
    this->num_spots = 0;
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

// Setters
string ParkingSpace::set_section(string section) {
    this->name = section;
}

void ParkingSpace::set_num_spots(int num_spots) {
    this->num_spots = num_spots;
}

// Other Methods
void ParkingSpace::update() {
    cout << "Updating parking section" << endl;
}

Parking* ParkingSpace::get_parking_spot(int spot) {
    return parking_spots[spot];
}