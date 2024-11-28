#include "../../headers/parking/ParkingLot.h"

// Constructors
ParkingLot::ParkingLot(string lot) {
    this->name = lot;
    this->num_sections = 0;
}

ParkingLot::~ParkingLot() {
    // Nothing to do here
}

// Getters
string ParkingLot::get_lot() {
    return this->name;
}

int ParkingLot::get_num_sections() {
    return this->num_sections;
}

// Setters
void ParkingLot::set_lot(string lot) {
    this->name = lot;
}

void ParkingLot::set_num_sections(int num_sections) {
    this->num_sections = num_sections;
}

// Other Methods
void ParkingLot::update() {
    for (int i = 0; i < parking_sections.size(); i++) {
        this->parking_sections[i]->update();
    }
    cout << "Updating parking lot" << endl;
}

void ParkingLot::add(Parking* section) {
    this->parking_sections.push_back(section);
}

Parking* ParkingLot::get_parking_section(int section) {
    return this->parking_sections[section];
}

vector<Parking*> ParkingLot::get_parking_sections() {
    return this->parking_sections;
}
