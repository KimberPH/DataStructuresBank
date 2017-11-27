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
  bool addTransaction(double startBalance, const Date &date, const std::string &payee, char transactionType, u64 accountNumber);
  
  bool loadCustomers(const char *path);
  bool loadAccounts(const char *path);
  bool loadTransactions(const char *path);

  std::string showAccounts() const;

  //need an account and date range
  std::string monthlyStatement(uf8 month, uf16 year) const;

  double totalSaving() const;
  double totalChecking() const;
  double totalCD() const;
  //std::string showCustomers() const;
  std::string customerTotals() const;
  bool save() const;
};
