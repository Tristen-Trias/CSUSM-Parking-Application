#ifndef VISITOR_H
#define VISITOR_H

#include <string>
#include <iostream>

#include "User.h"

using namespace std;

class Visitor : public User {
    public:

        // Constructors and Destructors
        Visitor();
        Visitor(string first_name, string last_name, int uID, bool registered, double rating);
        ~Visitor();

        // Other Methods
        void reserve_parking();
};

#endif