//Deposit Transaction class derived from base class Transaction
#ifndef DEPOSIT_H
#define DEPOSIT_H
#include "transaction.h" //base class definition
#include "Date.h" //date class definition
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
class Deposit : public Transaction { //deposit class inherits from the Transaction class


public:
	explicit Deposit(); //default constructor
	explicit Deposit(double, const Date&, const string&); //Constructor for deposit class
	virtual ~Deposit() = default; //default destructor

	virtual string toString() const override;

	//intent to override virtuals from base-class
	virtual double operator+(double) noexcept override; //calculate the addition operator in the case of a Deposit object, should add the amount to the balance double

};
#endif
