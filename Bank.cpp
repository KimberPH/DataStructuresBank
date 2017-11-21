#include <string>
#include <fstream>
#include "Account.h"
#include "Customer.h"
#include "Transaction.h"
#include "Bank.h"

Bank::Bank(){}

Bank::~Bank(){
  for(Customer *customer : customers)
    delete customer;

  for(Transaction *transaction : transactions)
    delete transaction;
}

void Bank::addTransaction(double startBalance, const Date &date, const std::string &payee){
  //transactions.push_back(new Transaction(startBalance, date, payee));
}


bool Bank::loadCustomers(const char *path){
  std::ifstream ifs(path, std::ifstream::in);
  if(!ifs.good()) return false;
  
  while(ifs.good()){
    Customer *customer = new Customer();
    // TODO: get info from stream and check good
    // return false if error
    customers.insert(customer);
  }
  
  ifs.close();
  return true;
}

bool Bank::loadAccounts(const char *path){
  // std::ifstream ifs(path, std::ifstream::in);
  // if(!ifs.good()) return false;
  
  // while(ifs.good()){
  //   // get account type
  //   Account *account = new Account();
  //   // TODO: get info from stream and check good
  //   // return false if error
  //   accounts.push_back(account);
  // }
  
  // ifs.close();
  return true;
}

bool Bank::loadTransactions(const char *path){
  std::ifstream ifs(path, std::ifstream::in);
  if(!ifs.good()) return false;
  
  while(ifs.good()){
    // get transaction type
    // Transaction *transaction = new Transaction();
    // TODO: get info from stream and check good
    // return false if error
    // transactions.push_back(transaction);
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
  
}

float Bank::totalSaving() const {
  // TODO: code to figure out what savings and then sum
}

float Bank::totalChecking() const {
  
}

float Bank::totalCD() const {

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
