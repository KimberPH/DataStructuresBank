#include "Savings.h"

using namespace std;

Savings::Savings(){}; //default constructor

void Savings::setInterestRate(const double& rate){
	interestRate = rate; //set interest rate
}

double Savings::getInterestRate() const{
	return interestRate; //return interest rate
}

