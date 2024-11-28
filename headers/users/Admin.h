#ifndef ADMIN_H
#define ADMIN_H

#include <string>
#include <iostream>

#include "User.h"
#include "../parking/ParkingFactory.h"

class Admin : public User {
    public:
        // Constructors and Destructors
        Admin();
        Admin(string first_name, string last_name, int uID, bool registered, double rating);
        ~Admin();

        // Other Methods
        void create_parking_lot();
        void reserve_parking();
};

#endif
