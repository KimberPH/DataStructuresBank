
#include <cstdlib>
#include "Customer.h"
#include "Transaction.h"
#include "Date.h"

using namespace std;

Account::Account(){
  //in derivided, something like type = SAVINGS_TYPE;
};

//setter functions
void Account::setAccountNumber(long num){
    accountNumber=num;
}
void Account::setDate(Date d){
    date=d;
}
void Account::setOpeningBalance(double amt){
    openingBalance=amt;
}
void setTransactionList(vector <Transaction> t){\
    transactionsList=t;
}

void setCustomer(vector <Customer*> c){
    customerList=c;
}

//getter functions

long Account::getAccountNumber(){
    return accountNumber;
}
double Account::getOpeningBalance() const{
    return openingBalance;
}

Date Account::getDate() const{
    return date;
}

vector Account::<Customer*> getCustomer(){
    return customerList;
}

vector Account::<Transaction> getTransactionList(){
    return transactionsList;
}
