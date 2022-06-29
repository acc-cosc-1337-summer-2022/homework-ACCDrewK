// checking_account.cpp
#include "checking_account.h"

int CheckingAccount::getBalance() const { return Account::getBalance() + 5; }