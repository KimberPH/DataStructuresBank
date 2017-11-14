/* 
 * File:   Customer.h
 * Author: Aatish, Kimber, Richard
 *
 * This is the header class for Account.
 */

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "Transaction.h"
#include "Date.h"

class Account {

public:
    //constructor
    Account(); 
    
    //getter functions
    long getAccountNumber();
    double getOpeningBalance() const;
    Date getDate() const;
    vector <Customer> getCustomer();
    vector <Transaction> getTransactionList();
    
    
    //setter functions
    void setAccountNumber(long num);
    void setDate(Date d);
    void setOpeningBalance(double amt);
    void setTransactionList(vector <Transaction> c);
    void setCustomer(vector <Customer*> c);
    
    
private:
    unsigned long accountNumber;
    Date date;
    double openingBalance;
    vector <Transaction> transactionsList;
    vector <Customer*> customerList;
    
}

#endif /* ACCOUNT_H */

