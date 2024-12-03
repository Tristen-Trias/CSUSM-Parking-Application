#ifndef PARKINGABSTRACT_H // Parking Abstracting 
#define PARKINGABSTRACT_H
#include <iostream>
#include <string>
using namespace std;

class Parking
{
 public: 
    virtual ~Parking(){} // Parking deconstructor
    virtual void display() = 0; //  Abstract display fuction, will be overidden through Parkinglot and Parkingspace hiles
  //  virtual string getName() const = 0;  

};

#endif
