#include "../../headers/users/Admin.h"

// Constructors
Admin::Admin() {
    this->first_name = "";
    this->last_name = "";
    this->uID = 0;
    this->user_type = 3;
    this->registered = false;
    this->rating = 0.0;
}

Admin::Admin(string first_name, string last_name, int uID, bool registered, double rating) {
    this->first_name = first_name;
    this->last_name = last_name;
    this->uID = uID;
    this->user_type = 3;
    this->registered = registered;
    this->rating = rating;
}

// Destructor
Admin::~Admin() {
    // Nothing to do here
}

// Other Methods
void Admin::create_parking_lot() {
    cout << "Creating a parking lot" << endl;
    
}

void Admin::reserve_parking() {
    cout << "Admin can reserve parking" << endl;
}

