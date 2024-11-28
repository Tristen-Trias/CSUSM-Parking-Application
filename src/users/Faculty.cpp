#include "../../headers/users/Faculty.h"

// Constructors
Faculty::Faculty() {
    this->first_name = "";
    this->last_name = "";
    this->uID = 0;
    this->user_type = 2;
    this->registered = false;
    this->rating = 0.0;
}

Faculty::Faculty(string first_name, string last_name, int uID, bool registered, double rating) {
    this->first_name = first_name;
    this->last_name = last_name;
    this->uID = uID;
    this->user_type = 2;
    this->registered = registered;
    this->rating = rating;
}

// Destructor
Faculty::~Faculty() {
    // Nothing to do here
}

// Other Methods
void Faculty::reserve_parking() {
    cout << "Faculty can reserve parking" << endl;
}
