#include "ParkingLotFactory.hpp"
#include "ParkingLotDecorator.hpp"

int main() {
    // Create a parking lot "LotB" with 2 spaces
    ParkingLot lot2 = ParkingLotFactory::createParkingLot("Lot B ", 3);
    cout << "There are " <<lot2.countEmptySpaces() << " empty spaces in this lot." << endl;  //displays the number on empty spaces in the lot
    lot2.getSpaces(); // 
    lot2.reserveSpace("ded",1, 6 , 8 ); 
    cout << "There are now " <<lot2.countEmptySpaces() << " empty spaces in this lot." << endl; 
    lot2.display();
    lot2.reserveSpace("lol", 1, 7 , 9 ); // reserve space 1 through time ranges 6 - 8 

    //creates a parking lot "lotA" with 3 spaces in 
    //ParkingLot lotA = ParkingLotFactory::createParkingLot("Lot A", 3);
    //lotA.display();    
    //lotA.reserveSpace(1, 7, 9);
    //lotA.display();
    
    //ParkingSpace space4(4, true);  // example of a parking space object being created to be added to lotA  (space4, empty)
    //lotA.addSpace(space4);
    //lotA.display();

    ///   Below is test for decortors for student and faculty parking lots

    ParkingLot* decoratedFacultyLot = new ParkingLot (ParkingLotFactory::createParkingLot("Faculty Lot", 3));
    FacultyLotDecorator* falcultyLot1 = new FacultyLotDecorator(decoratedFacultyLot);

    falcultyLot1->display();
    falcultyLot1->reserveFacultySpot("rag", 1, 2,5);


    ParkingLot* decoratedStudentLot = new ParkingLot (ParkingLotFactory::createParkingLot("Student Lot", 3));
    StudentLotDecorator* studentLot1 = new StudentLotDecorator(decoratedStudentLot);
    
    studentLot1->display();
    studentLot1->reserveStudentSpot("blip", 1, 2, 5);
    studentLot1->reserveStudentSpot("dip", 1, 2, 6);



    return 0;
}
