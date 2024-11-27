#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

#include "User.h"

using namespace std;

class Student : public User {
    public:

        // Constructors and Destructors
        Student();
        Student(string first_name, string last_name, int uID, bool registered, double rating);
        ~Student();

        // Other Methods
        void reserve_parking();
};

#endif