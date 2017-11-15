#include <iostream>
#include <string>
#include <sstream>
#include "Transaction.h"
//#include "Date.cpp"
#include "Date.h"
#include <cmath> //include math library

using namespace std;

//overload stream extraction operator, cannot be a member function
istream& operator >>(istream& input, Transaction& t){
	input >> t.amount; //input amount into Transaction object
	input >> t.date; //input date
    getline(input, t.payee); //input payee information
    return input; //enables cascading cin >> a >> b
}

//default constructor
Transaction::Transaction(){};

//constructor initializes each data member
Transaction::Transaction(double amt, const Date& day, const string& payeeInfo)
: amount(amt), date(day), payee(payeeInfo){} 

//set amount value
void Transaction::setAmount(double amt){
		if(amt>0){
			amount = amt;
		}
}

//set Date
void Transaction::setDate(const Date& day){
		date = day;
}
//set Payee information
void Transaction::setPayee(const string& payeeInfo){
	payee = payeeInfo;
}

//print transaction object
string Transaction::toString() const{
	ostringstream output;
	output << date.toString() << " $" << amount << " " << payee;
	return output.str();
}



//return amount
double Transaction::getAmount() const {return amount;}
//return the date
Date Transaction::getDate() const {return date;}
//return payee information
string Transaction::getPayee() const {return payee;}


//overloading the < operator for Transaction objects, compares the Date values of each Transaction object Returns Truw or False
bool Transaction::operator <(const Transaction* trans){

	return this->date < trans->date; //if dates are not equal return True or False
	
}




