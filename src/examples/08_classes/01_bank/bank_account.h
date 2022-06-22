// bank_account.h
#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

class Account {
public:
  Account() : Account(0.0) {}       // default constructor
  Account(double b) : balance(b) {} /*for accounts with existing balance*/
  int getBalance() const {          // balance += 20;
    return balance;
  }; // method, function
  void deposit(double amount);
  void withdraw(double amount);

private:               // access specifier
  double balance{0.0}; // variable attribute, initial value 15
};

// Free Functions
void display_balance(const Account &);

Account get_account();

#endif // BASE_ACCOUNT_H