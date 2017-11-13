#include "Customer.h"
#include <string>
#include <vector>

using namespace std;

//Class Constructor initalizes each data member
Customer::Customer(const string& fName, const string& lName, 
	const string& adrs, vector<Account*>& acntList, 
	const unsigned int& custId) : firstName(fName), lastName(lName),
	address(adrs), accounts(acntList), customerId(custId){}
	
void Customer::setFirstName(const string& fName){
	firstName = fName;
}

void Customer::setLastName(const string& lName){
	lastName = lName;
}

void Customer::setAddress(const string& adrs){
	address = adrs;
}

void Customer::setAccounts(vector<Account*>& 
