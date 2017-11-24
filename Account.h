/* 
 * File:   Account.h
 * Author: Aatish, Kimber, Richard
 *
 * This is the header class for Account.
 */

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <vector>

//#include "Customer.h"
#include "Transaction.h"
#include "Date.h"

enum AccountType {
  SAVINGS_ACCOUNT, CHECKING_ACCOUNT, CD_ACCOUNT
};

class Account {

public:
    Account(); //default class constructor
    
    //getter functions
    long getAccountNumber();
    double getOpeningBalance() const;
    Date getDate() const;
    std::vector <Transaction*> getTransactionList();
    //vector <Customer*> getCustomer();
    AccountType getType() const;    
    double getBalance() const;
    
    //setter functions
    void setAccountNumber(long num);
    void setDate(Date d);
    void setOpeningBalance(double amt);
    void setTransactionList(std::vector <Transaction> c);
    //void setCustomer(vector <Customer*> c);
    
    //misc functions
    //states the initial balance, transaction that took place, and the ending balance
    std::string monthlyStatement() const;

    std::string toString() const;
private:
    unsigned long accountNumber;
    Date date;
    double openingBalance;
    std::vector <Transaction*> transactionsList;
    //vector <Customer*> customerList;
    AccountType type;
};

#endif /* ACCOUNT_H */

