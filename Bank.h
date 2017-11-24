#pragma once
#include <string>
#include <set>
#include <vector>
#include "Account.h"
#include "Customer.h"
#include "Transaction.h"

class Bank {
private:
  //TODO: maybe map depending on how program goes
  std::set<Customer*> customers; //TODO: sort by customer ID
  std::vector<Transaction*> transactions;
  std::set<Account*> accounts; //TODO: sort by account number
  
public:
  Bank();
  ~Bank();

  // TODO: add args when known
  void addTransaction(double startBalance, const Date &date, const std::string &payee);
  
  bool loadCustomers(const char *path);
  bool loadAccounts(const char *path);
  bool loadTransactions(const char *path);

  std::string showAccounts() const;

  //need an account and date range
  std::string monthlyStatement() const;

  double totalSaving() const;
  double totalChecking() const;
  double totalCD() const;
  //std::string showCustomers() const;
  std::string customerTotals() const;
  bool save() const;
};
