// Fee class member function definitions
#include "Fee.h"
#include "Transaction.h"
#include "Date.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cmath> //include math library

using namespace std;

string Fee::toString() const{
	ostringstream output;
	output << " Overdraft Fee, " << Transaction::toString(); //output deposit as type
	return output.str(); //enables cascading
}

//default constructor
Fee::Fee(){};

//class constructor
Fee::Fee(double flatFee, const Date& day, const string& payeeInfo) : Transaction(flatFee, day, payeeInfo){}// call to Transaction class constructor

//define the meaning of the + operator for the Fee class
double Fee::operator+ (double x){
	double temp; //ititalize a temporary variable
	double overdraftFee = 25; //fee is $25
	temp = x - overdraftFee; // subtract value from amount
	return temp; //return new amount
}
