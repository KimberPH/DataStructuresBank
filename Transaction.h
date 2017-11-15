#include <string>
#include <iostream>
#include <sstream>
#include "Date.h"
//#include "Date.cpp"
using namespace std;
//Transaction class definition
#ifndef TRANSACTION_H
#define TRANSACTION_H

class Transaction {

	//overloading operators
	//overloads the extraction operator reads a single line of input in order: type, amount, date, payee
	friend istream& operator >>(istream&, Transaction&);
	
	

public:
	explicit Transaction(); //default constructor
	explicit Transaction(double, const Date&, const string&);
	virtual ~Transaction() = default; //default destructor

	virtual string toString() const;
    
    //overload the + operator for the Transaction class return type is int
    virtual double operator+(double) = 0;//addition operator, should add an int to the amount and returns an int||pure virtual function
    
    //overload the < operator for the Transaction class. return True or False, compare date aspects of Transaction objects
    bool operator <(const Transaction*); 
	
	
    //set functions
	void setAmount(double);
	void setDate(const Date&);
	void setPayee(const string&);
    
    //get functions
	double getAmount() const;//get amount
	Date getDate() const; //get the date
	string getPayee() const; //get the payee information


private:
	double amount; // transaction amount
	Date date; //Date of Transaction, a Date object
	string payee; //Payee information for transaction


};
#endif
