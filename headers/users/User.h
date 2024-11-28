#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>

#include "../../headers/parking/Parking.h"

using namespace std;

class User {
    public:

        // Constructors and Destructors
        User();
        User(string first_name, string last_name, int uID, int user_type, bool registered, double rating);
        ~User();

        // Getters
        bool is_registered(); //get_status
        double get_rating();
        string get_first_name();
        string get_last_name();
        int get_uID();  //0: Visitor, 1: Student, 2: Faculty, 3: Admin
        int get_user_type();
        User* get_user();
        Parking* get_current_parking();
        vector<Parking*> get_reserved_parking();

        // Setters
        void set_status(bool registered);
        void set_rating(double rating);
        void set_first_name(string first_name);
        void set_last_name(string last_name);
        void set_uID(int uID);
        void set_current_parking(Parking* current);

        // Other Methods
        void print_user();
        virtual void reserve_parking();
        
    protected:
        string first_name, last_name;
        int uID, current_parking, user_type;
        bool registered;
        double rating;
        Parking* current;
        vector<Parking*> parking;
};

#endif
