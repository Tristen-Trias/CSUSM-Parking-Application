#include "../../headers/parking/ParkingSection.h"

// Constructors
ParkingSection::ParkingSection(string section) {
    this->name = section;
    this->num_spots = 0;
}

ParkingSection::~ParkingSection() {
    // Nothing to do here
}

// Getters
string ParkingSection::get_section() {
    return this->name;
}

int ParkingSection::get_num_spots() {
    return this->num_spots;
}

// Setters
void ParkingSection::set_section(string section) {
    this->name = section;
}

void ParkingSection::set_num_spots(int num_spots) {
    this->num_spots = num_spots;
}

// Other Methods
void ParkingSection::update() {
    cout << "Updating parking section" << endl;
}

Parking* ParkingSection::get_parking_spot(int spot) {
    return parking_spots[spot];
}
