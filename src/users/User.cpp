#include "../../headers/users/User.h"

// Constructors
User::User() {
    this->first_name = "";
    this->last_name = "";
    this->uID = 0;
    this->registered = false;
    this->rating = 0.0;
}

User::User(string first_name, string last_name, int uID, bool registered, int type) {
    this->first_name = first_name;
    this->last_name = last_name;
    this->uID = uID;
    this->registered = registered;
    this->user_type = type;
    this->rating = 0.0;
}

// Destructor
User::~User() {
    // Nothing to do here
}

// Getters

User* User::get_user() {
    return this;
}

bool User::is_registered() {
    return registered;
}

double User::get_rating() {
    return rating;
}

string User::get_first_name() {
    return first_name;
}

string User::get_last_name() {
    return last_name;
}

int User::get_uID() {
    return uID;
}

int User::get_user_type() {
    return user_type;
}

// Setters

void User::set_status(bool registered) {
    this->registered = registered;
}

void User::set_rating(double rating) {
    this->rating = rating;
}

void User::set_first_name(string first_name) {
    this->first_name = first_name;
}

void User::set_last_name(string last_name) {
    this->last_name = last_name;
}

void User::set_uID(int uID) {
    this->uID = uID;
}


// Other Methods

void User::print_user() {
    cout << "User ID: " << uID << endl;
    cout << "User Type: " << user_type << endl;
    cout << "First Name: " << first_name << endl;
    cout << "Last Name: " << last_name << endl;
    cout << "Current Parking: " << current_parking << endl;
    cout << "Registered: " << registered << endl;
    cout << "Rating: " << rating << endl;
}

void User::reserve_parking(ParkingSpace* space, int startTime, int endTime) {
    if (space->reserveTimeSlot(uID, startTime, endTime)) {
        current_parking = space->getSpaceNumber();
        cout << "Parking reserved successfully" << endl;
    } else {
        cout << "Parking reservation failed" << endl;
    }
    cout << "Reserving parking" << endl;
}
