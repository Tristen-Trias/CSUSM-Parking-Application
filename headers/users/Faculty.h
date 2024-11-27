#ifndef FACULTY_H
#define FACULTY_H

#include <string>
#include <iostream>

#include "User.h"

using namespace std;

class Faculty : public User {
    public:

        // Constructors and Destructors
        Faculty();
        Faculty(string first_name, string last_name, int uID, bool registered, double rating);
        ~Faculty();

        // Other Methods
        void reserve_parking();
};

#endif