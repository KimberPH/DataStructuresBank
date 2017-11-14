// Fig. 9.15: Date.cpp
// Date class member-function definitions.
//*comments with * are changes I have made to this code that is from the book*
#include <sstream>
#include <string>
#include "Date.h" // include definition of class Date from Date.h
using namespace std;

//*Overload the stream extraction operator, cannot be a member function*
istream& operator>>(istream& input, Date& d){
    input >> d.month; //*input int into month*
    input.ignore(); //*skip or ignore '/' after the month*
    input >> d.day; //*input into day*
    input.ignore(); //*skip the '/' after the day*
    input >> d.year; //*input into year*
    return input; //*enables cascading with the >> operator*
}


// Date constructor (should do range checking)
Date::Date(unsigned int m, unsigned int d, unsigned int y) 
   : month{m}, day{d}, year{y} {}

// print Date in the format mm/dd/yyyy
string Date::toString() const {
   ostringstream output;
   output << month << '/' << day << '/' << year;
   return output.str();
}

//*Overloading the < operator for comparing two Date objects, returns True or False*
bool Date::operator<(const Date& d)const{
    auto otherDay = this; //*variable for the date objecvt before the <* 
    if(otherDay->year == d.year){ //*if years are equal check month*
        if(otherDay->month == d.month){//*if months are equal check days* 
            if(otherDay->day == d.day){//*if days are equal return True*
                return true;
            }
            else if (otherDay->day < d.day){//*if otherDay.day is less than return True*
                return true;
            }
            else{ return false;}//*otherwise return false for not less than*
        }
        else if(otherDay->month < d.month){//*check months for less than if they are not equal*
            return true;
        }
        else{ return false;}
    }
    else if(otherDay->year < d.year){//*if years are not equal check years for less than*
        return true;
    }
    else{ return false;}
}

bool Date::operator==(const Date& d)const{
		auto otherDay = this; //*Variable for the object before the = sign*
		if(otherDay->year == d.year){ //*if years are equal check the months*
			if(otherDay->month == d.month){ //*if months are equal then check the days*
				if(otherDay->day == d.day){ //*if days are equal then the dates are equal, return True*
					return true;
				}
				else
					return false; //*return false if year, month, date are not equal*
			}
			else
				return false; //*return false if year, month, date are not equal*
		} 
		else
			return false; //*return false if year, month, date are not equal*
}


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
