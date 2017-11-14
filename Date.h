// Fig. 9.14: Date.h
// Date class declaration.  Member functions are defined in Date.cpp.
//*comments with * are changes I have made to this code that is from the book*
#include <string>
#include <iostream> //*I added this to the book code for easier acess to i/o actions*

using namespace std; //*I added this to make overloading the extraction op slightly easier*

// prevent multiple inclusions of header
#ifndef DATE_H
#define DATE_H

// class Date definition
class Date {

    //*Overloading the extraction operator for the Date class*
    friend istream& operator >>(istream&, Date&); 

public:

    //*Overloading the < operator for the date class*
    bool operator <(const Date&)const; //should compare dates and return True or False
    
    //*Overloading the = operator for the date class*
    bool operator ==(const Date&)const; //should compare the dates and return True or False 

   explicit Date(unsigned int = 1, unsigned int = 1, unsigned int = 2000);
   std::string toString() const;
private:
   unsigned int month;
   unsigned int day;
   unsigned int year;
};

#endif

/**************************************************************************
 * (C) Copyright 1992-2017 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/
