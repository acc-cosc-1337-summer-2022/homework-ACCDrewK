// savings_account.h
#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H
#include "bank_account.h"

class SavingsAccount : public Account {
public:
  SavingsAccount() = default;
  explicit SavingsAccount(double amt) : Account(amt) {}
};
#endif // SAVINGS_ACCOUNT_H