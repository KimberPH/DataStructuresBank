#include "Account.h"
#include "Date.h"
#include <vector>
#include <string>

using namespace std;

#ifndef CD_H
#define CD_H

class Cd : public Account{
	
public:
	explicit Cd(); //default constructor
	virtual ~Cd() = default; //default destructor
	
	//set functions
	void setInterestRate(const double); //set the rate of interest for the account
	void setMaturityDate(const Date&); //set the date at which the account is done earning interest
	
	//get functions
	double getInterestRate(); //return interest rate for the specific CD account
	Date getMaturityDate(); //return the date that the account stops earning interest
	
	
private:
	double interestRate; //interest rate for the CD account
	Date maturityDate; //date at which the account is matured
	
};
#endif
