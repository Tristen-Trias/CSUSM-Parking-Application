#include "ParkingFactory.h"

void ParkingFactory::create_parking_lot(string name, int sections) {
    if (name == "student") {
        Parking* student_parking = new StudentParking();
        cout << "Creating a student parking lot with " << sections << " sections" << endl;
    } else if (name == "faculty") {
        cout << "Creating a faculty parking lot with " << sections << " sections" << endl;
    } else {
        cout << "Creating a visitor parking lot with " << sections << " sections" << endl;
    }
    cout << "Creating a parking lot with " << sections << " sections" << endl;
}

void ParkingFactory::create_parking_lot(string name) {
    if (name == "student") {
        cout << "Creating a student parking lot" << endl;
    } else if (name == "faculty") {
        cout << "Creating a faculty parking lot" << endl;
    } else {
        cout << "Creating a visitor parking lot" << endl;
    }
}