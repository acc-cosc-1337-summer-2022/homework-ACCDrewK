// atm.h
#ifndef ATM_H
#define ATM_H
#include "bank_account.h"

class ATM {
public:
  // ATM() {}
  ATM(Account a) : account(a){};
  void display_balance();
  void make_deposit();
  void make_withdraw();

private:
  Account account;
};

// FREE FUNCTIONS

void display_menu();
void run_menu();
void handle_transaction(ATM&, int);

#endif