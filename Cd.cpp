#include "Cd.h"
#include "Account.h"
#include "Date.h"
#include <string>

using namespace std;

Cd::Cd(){}; //default class constructor

//set the interest rate
void Cd::setInterestRate(const double rate){
	interestRate = rate;
}

//set the maturity date 
void Cd::setMaturityDate(const Date& day){
	maturityDate = day;
}

//return the interest rate
double Cd::getInterestRate(){return interestRate;}

//return the maturity Date
Date Cd::getMaturityDate(){return maturityDate;}
