//Withdrawl class member function definitions
#include "Withdrawl.h"
#include "Transaction.h"
#include "Date.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cmath> //include math library
#include <stdexcept> //standard exceptions library

using namespace std;

string Withdrawl::toString() const{
	ostringstream output;
	output << " Withdrawal, " << Transaction::toString(); //output deposit as type
	return output.str(); //enables cascading
}
//default constructor
Withdrawl::Withdrawl(){};

//class constructor
Withdrawl::Withdrawl(double amt, const Date& day, const string& payeeInfo) : Transaction(amt, day, payeeInfo){}//call to Transaction class constructor

//define the meaning of the + operator for the Withdrawl class
double Withdrawl::operator+(double x){
	double temp; //ititalize a temporary variable
	temp = x - getAmount(); // subtract value from amount
	if(temp<0){
		throw logic_error("This action will cause an overdraft of the account"); //if amount will cause an overdraft fee then throw error message
	}
	else{
		return temp; //return temp as the new balance
	}
}

