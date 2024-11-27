#include "Visitor.h"

// Constructors
Visitor::Visitor() {
    this->first_name = "";
    this->last_name = "";
    this->uID = 0;
    this->user_type = 0;
    this->registered = false;
    this->rating = 0.0;
}

Visitor::Visitor(string first_name, string last_name, int uID, bool registered, double rating) {
    this->first_name = first_name;
    this->last_name = last_name;
    this->uID = uID;
    this->user_type = 0;
    this->registered = registered;
    this->rating = rating;
}

// Destructor
Visitor::~Visitor() {
    // Nothing to do here
}

// Other Methods

void Visitor::reserve_parking() {
    cout << "Visitor cannot reserve parking" << endl;
}

