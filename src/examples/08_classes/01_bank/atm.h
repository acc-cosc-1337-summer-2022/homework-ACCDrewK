// atm.h
#ifndef ATM_H
#define ATM_H
#include "bank_account.h"
#include <vector>

class ATM {
public:
  // ATM() {}
  ATM(std::vector<Account> &a) : accounts(a) {}
  void display_balance();
  void make_deposit();
  void make_withdraw();
  void scan_card();

private:
  // Account account;
  std::vector<Account> accounts;
  int account_index{0};
};

// FREE FUNCTIONS

void display_menu();
void run_menu(ATM &atm);
void handle_transaction(ATM &, transaction);

#endif