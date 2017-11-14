// Withdrawl class derived from base-class Transaction
#ifndef WITHDRAWL_H
#define WITHDRAWL_H
#include "transaction.h"
#include "Date.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Withdrawl : public Transaction {



public:
	explicit Withdrawl(); //default constructor
	explicit Withdrawl(double, const Date&, const string&); //constructor for withdrawl
	virtual ~Withdrawl() = default; //default destructor
	
	virtual string toString() const override;
	
	//intent to override virtuals from base-class
	virtual double operator+(double) override; //meaning for + operator within withdrawl class with subtract amount from Balance that is passed to it
};
#endif
