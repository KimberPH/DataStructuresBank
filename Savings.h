#include "Account.h"
#include "Transaction.h"
#include "Date.h"
#include <vector>
#include <string>

using namespace std;

#ifndef SAVINGS_H
#define SAVINGS_H
//Savings class is a sub-class of the Account class
class Savings : public Account {
	
public:
	explicit Savings(); //default constructor
	virtual ~Savings() = default; //default destructor
	
	void setInterestRate(const double&); //set the interest rate for the account
	
	double getInterestRate() const; // return the associated interest amount   

private:
	double interestRate; //interest rate data member only fo rthis savings account
};
#endif

