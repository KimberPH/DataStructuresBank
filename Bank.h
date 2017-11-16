#pragma once
#include <string>
#include <vector>
#include "Account.h"
#include "Customer.h"
#include "Transaction.h"

class Bank {
private:
  std::vector<Customer*> customers;
  std::vector<Transaction*> transactions;
  std::vector<Account*> accounts;
  
public:
  Bank();
  ~Bank();

  // TODO: add args when known
  void addTransaction(double startBalance, const Date &date, const std::string &payee);
  
  bool loadCustomers(const char *path);
  bool loadAccounts(const char *path);
  bool loadTransactions(const char *path);

  std::string showAccounts() const;
  std::string monthlyStatement() const;
  float totalSaving() const;
  float totalChecking() const;
  float totalCD() const;
  std::string showCustomers() const;
  std::string customerTotals() const;
  bool save() const;
};
