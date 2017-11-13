#include <string>
#include <vector>

using namespace std;

#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer{
	
public:
	explicit Customer(const string&, const string&, const string&, const string&, vector<Account*>&, const unsigned int&);//class constructor
	~Customer() = default; //default destructor
	
	//set fucntions
	void setFirstName(const string&);
	void setLastName(const string&);
	void setAddress(const string&);
	void setAccounts(const vector<Account*>&);
	void setCustomerId(const unsigned int&);
	
	//get Functions
	string getFirstName() const;
	string getLastName() const;
	string getAddress() const;
	vector<Account*> getAccounts() const; 
	unsigned int getCustomerId() const;
	
private:
	string firstName;
	string lastName;
	string address;
	vector<Account*> accounts;
	unsigned int customerId;
	
};
#endif


