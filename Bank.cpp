#include <string>
#include <fstream>
#include "bittypes.h"
#include "Account.h"
#include "Savings.h"
#include "Checking.h"
#include "Cd.h"

#include "Customer.h"

#include "Transaction.h"
#include "Withdrawl.h"
#include "Deposit.h"
#include "Fee.h"

#include "Bank.h"

Bank::Bank(){}

Bank::~Bank(){
  for(Customer *customer : customers)
    delete customer;

  for(Transaction *transaction : transactions)
    delete transaction;
}

void Bank::addTransaction(double startBalance, const Date &date, const std::string &payee){
  // TODO: get transaction type as well
  //transactions.push_back(new Transaction(startBalance, date, payee));
}


bool Bank::loadCustomers(const char *path){
  std::ifstream ifs(path, std::ifstream::in);
  if(!ifs.good()) return false;
  
  while(ifs.good()){
    std::string strin;
    
    Customer *customer = new Customer();
    ifs >> strin;
    customer->setLastName(strin);

    ifs >> strin;
    customer->setFirstName(strin);

    ifs >> strin;
    if(!ifs.good()){
      ifs.close();
      return false;
    }
    
    customer->setSSN(strin);

    std::getline(ifs, strin);
    customer->setAddress(strin);
    
    customers.insert(customer);
  }
  
  ifs.close();
  return true;
}

bool Bank::loadAccounts(const char *path){
  std::ifstream ifs(path, std::ifstream::in);
  if(!ifs.good()) return false;
  
  while(ifs.good()){
    Date date;
    double openingBalance;
    char accountType;

    ifs >> date;
    ifs >> openingBalance;
    if(!ifs.good()){
      ifs.close();
      return false;
    }
    
    ifs >> accountType;
    
    Account *account;
    switch(accountType){
    case 's':
      account = new Savings();
      break;
    case 'c':
      account = new Checking();
      break;
    case 'C':
      account = new Cd();
      break;
    default:
      ifs.close();
      return false;
    }
    
    accounts.insert(account);
  }

  ifs.close();
  return true;
}

bool Bank::loadTransactions(const char *path){
  std::ifstream ifs(path, std::ifstream::in);
  if(!ifs.good()) return false;
  
  while(ifs.good()){
    Date date;
    char transactionType;
    u64 accountNumber;
    double amount;
    std::string payee;
    
    ifs >> date;
    ifs >> transactionType;
    ifs >> accountNumber;
    ifs >> amount;
    if(!ifs.good()){
      ifs.close();
      return false;
    }
    
    getline(ifs, payee);
    Transaction *transaction;
    
    switch(transactionType){
    case 'w':
      transaction = new Withdrawl(amount, date, payee);
      break;
    case 'd':
      transaction = new Deposit(amount, date, payee);
      break;
    case 'f':
      transaction = new Fee(amount, date, payee);
      break;
    default:
      ifs.close();
      return false;
    }

    transactions.push_back(transaction);
    // TODO: add transaction to account with corresponding account number
  }
  
  ifs.close();
  return true;
}

std::string Bank::showAccounts() const {
  std::string ret = "";
  for(Account *account: accounts){
    ret += account->toString();
    ret += "\n";
  }

  return ret;
}

std::string Bank::monthlyStatement() const {
  // TODO: 
  std::string ret = "";
  return ret;
}

double Bank::totalSaving() const {
  double sum = 0;
  
  for(Account *account : accounts){
    if(account->getType() == SAVINGS_ACCOUNT)
      sum += account->getBalance();
  }

  return sum;
}

double Bank::totalChecking() const {
  double sum = 0;
  
  for(Account *account : accounts){
    if(account->getType() == CHECKING_ACCOUNT)
      sum += account->getBalance();
  }

  return sum;
}

double Bank::totalCD() const {
  double sum = 0;
  
  for(Account *account : accounts){
    if(account->getType() == CD_ACCOUNT)
      sum += account->getBalance();
  }

  return sum;
}

/*std::string Bank::showCustomers() const {
  std::string ret = "";
  for(Customer *customer: customers){
    ret += customer->toString();
    ret += "\n";
  }

  return ret;
  }*/

std::string Bank::customerTotals() const {
  std::string ret = "";
  for(Customer *customer : customers){
    ret += customer->getLastName();
    ret += ", ";
    ret += customer->getFirstName();
    ret += ": ";

    double total = 0;
    for(Account *account : customer->getAccounts())
      total += account->getBalance();
    
    ret += total;
  }
  
  return ret;
}

bool Bank::save() const {
  // // TODO: check for err
  // std::ofstream ofs("outCustomer.txt");
  // do same for accounts and transactions
  // // TODO: write
  // ofs.close();
  // return true;
}
