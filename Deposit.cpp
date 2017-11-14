//Deposit class member function defintions
#include "Deposit.h"
#include "transaction.h"
#include "Date.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cmath> //include math library

using namespace std;

string Deposit::toString() const{
	ostringstream output;
	output << " Deposit, " << Transaction::toString(); //output deposit as type
	return output.str(); //enables cascading
}

//default constructor
Deposit::Deposit(){};

//class constructor
Deposit::Deposit(double amt, const Date& day, const string& payeeInfo) : Transaction(amt, day, payeeInfo){} //call to Transaction constructor

//define meaning of the + operator
double Deposit::operator+(double x) noexcept{
	double temp; //ititalize a temporary variable
	temp = x + getAmount(); //add value to amount 
	
	return temp; //return new amount
}
