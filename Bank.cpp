#include "Bank.h"
#include <fstream>

Bank::Bank(){}

Bank::~Bank(){
  for(Customer *customer : customers)
    delete customer;

  for(Tranasaction *transaction : transactions)
    delete transaction;
}

void Bank::addTransaction(double startBalance, const Date &date, const std::string &payee){
  transactions.push_back(new Transaction(startBalance, date, payee));
}


bool Bank::loadCustomers(const char *path){

}

bool Bank::loadAccounts(const char *path){

}

bool Bank::loadTransactions(const char *path){

}

std::string Bank::showAccounts() const {

}

std::string Bank::monthlyStatement() const {

}

float Bank::totalSavings() const {
  // TODO: code to figure out what savings and then sum
}

float Bank::totalChecking() const {
  
}

float Bank::totalCD() const {

}

std::string Bank::showCustomers() const {
  std::string ret = "";
  for(Customer *customer: customers){
    ret += customer->toString();
    ret += "\n";
  }

  return ret;
}

bool Bank::save() const {
  /*
  // TODO: check for err
  std::ofstream ofs("out.txt");
  // TODO: write
  ofs.close();
  return true;
  */
}
