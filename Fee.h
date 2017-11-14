// Fee class derived from base-class Transaction
#ifndef FEE_H
#define FEE_H
#include "transaction.h"
#include "Date.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Fee : public Transaction{


public:
	explicit Fee();//default constructor
	explicit Fee(double, const Date&, const string&);//Constructor
	virtual ~Fee() = default; //default destructor
	
	virtual string toString() const override;
	
	//intent to override virtuals from base-class
	virtual double operator+(double) override; //meaning for the + operator

};
#endif
