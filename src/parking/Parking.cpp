#include "../../headers/parking/Parking.h"

using namespace std;

// Constructors
Parking::Parking() {
    this->name = "";
}

Parking::~Parking() {
    // Nothing to do here
}

// Other Methods
void Parking::update() {
    // Placeholder
    cout << "Updating parking" << endl;
}

void Parking::add(Parking* section) {
    // Placeholder
    cout << "Adding parking section" << endl;
}

vector<Parking*> Parking::get_parking_sections() {
    // Placeholder
    cout << "Getting parking sections" << endl;
    return vector<Parking*>();
}
