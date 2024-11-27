#include "Student.h"

// Constructors
Student::Student() {
    this->first_name = "";
    this->last_name = "";
    this->uID = 0;
    this->user_type = 1;
    this->registered = false;
    this->rating = 0.0;
}

Student::Student(string first_name, string last_name, int uID, bool registered, double rating) {
    this->first_name = first_name;
    this->last_name = last_name;
    this->uID = uID;
    this->user_type = 1;
    this->registered = registered;
    this->rating = rating;
}

// Destructor
Student::~Student() {
    // Nothing to do here
}

// Other Methods
void Student::reserve_parking() {
    cout << "Student can reserve parking" << endl;
}