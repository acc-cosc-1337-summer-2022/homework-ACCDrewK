// bank_account.cpp
#include "bank_account.h"
#include <iostream>

void Account::deposit(double amount) {
  if (amount > 0) {
    balance += amount;
  };
};

void Account::withdraw(double amount) {
  if (amount <= balance && amount > 0) {
    balance -= amount;
  }
};

// Free Functions -----------------------------------

void display_balance(const Account &account) {
  std::cout << "Display balance function " << account.getBalance() << std::endl;
};

Account
get_account() { // don't add & after Account type, will return reference to null
  Account account;
  return account;
}