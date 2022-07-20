// bank_account.h
#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H
#ifndef BRANCH_BANK_H
#define BRANCH_BANK_H
#include <iostream>

enum transaction { DEPOSIT = 1, WITHDRAW = 2, DISPLAY = 3, EXIT = 4 };
// enum class MENU_OPTION { DEPOSIT = 1, WITHDRAW = 2, DISPLAY = 3, EXIT = 4 };

class Branch_bank {
public:
  Branch_bank(double b) : branch_balance(b) {}
  void update_balance(double b);
  double get_branch_balance() const { return branch_balance; }

private:
  double branch_balance;
};

class Account {
  friend void show_balance(Account &account);
  friend void Branch_bank::update_balance(double);
  friend std::ostream &operator<<(std::ostream &out, const Account &account);
  friend std::istream &operator>>(std::istream &in, Account &account);

public:
  // Account() : Account(0.0) {}       // default constructor
  Account() = default;
  explicit Account(double b)
      : balance(b) {}              /*for accounts with existing balance*/
  virtual int getBalance() const { // balance += 20;
    return balance;
  }; // method, function
  virtual void deposit(double amount);
  virtual void withdraw(double amount);
  static double get_bank_balance() { return bank_balance; }

private:               // access specifier
  double balance{0.0}; // variable attribute, initial value 15
  static double bank_balance;
};

// Free Functions
void display_balance(const Account &);

Account get_account();

#endif // BRANCH_BANK_H
#endif // BASE_ACCOUNT_H