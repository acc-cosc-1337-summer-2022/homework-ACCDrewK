// checking_account.h
#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H
#include "bank_account.h"
#include "savings_account.h"

class CheckingAccount : public Account {
public:
  CheckingAccount() = default;
  explicit CheckingAccount(double amt) : Account(amt) {}
  int getBalance() const override;
  void deposit(double amount) override{};
};
#endif // CHECKING_ACCOUNT_H