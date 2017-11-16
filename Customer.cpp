#include "Customer.h"
#include "Account.h"
#include <string>
#include <vector>

using namespace std;

//default Class Constructor for creating empty Customer objects
Customer::Customer(){};

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

void Customer::setAccounts(vector<Account*>& acnt){
	accounts = acnt;
}

void Customer::setCustomerId(const unsigned int& custId){
	customerId = custId;
}

string Customer::getFirstName() const {return firstName;} //get First name
string Customer::getLastName() const {return lastName;} //get the Last name
string Customer::getAddress() const {return address;} //get the Customers address
vector<Account*> Customer::getAccounts() const {return accounts;} //get the list of pointers to account object of the accounts associated with the indiviual customer
unsigned int Customer::getCustomerId() const {return customerId;} //returns the customers ID number


