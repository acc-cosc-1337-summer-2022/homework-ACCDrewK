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

void show_balance(Account account) {
  std::cout << "Display friend function: " << account.getBalance() << std::endl;
}

// Branch_bank methods
void Branch_bank::update_balance(double new_balance) {
  branch_balance += new_balance;
  Account::bank_balance += new_balance;
}

// Free Functions -----------------------------------

void display_balance(const Account &account) {
  // account.balance;
  std::cout << "Display balance function " << account.getBalance() << std::endl;
};

Account
get_account() { // don't add & after Account type, will return reference to null
  Account account;
  return account;
}

// initialize static bank balance
double Account::bank_balance{10000};