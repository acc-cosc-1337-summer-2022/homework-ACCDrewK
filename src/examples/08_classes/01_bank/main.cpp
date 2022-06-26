#include "atm.h"
#include "bank_account.h"
//#include "branch_bank.h"
#include <iostream>
#include <string>
#include <vector>

int main() {
  using std::cout;
  using std::endl;
  using std::vector;
  // set random seed
  // srand(time(NULL));
  Branch_bank b_bank(500);
  Account account(50);
  cout << account.get_bank_balance() << "\n";
  b_bank.update_balance(25);
  cout << account.get_bank_balance() << endl;

  vector<Account> accounts;
  accounts.push_back(Account(100));
  accounts.push_back(Account(200));
  accounts.push_back(Account(300));
  accounts.push_back(Account(400));
  accounts.push_back(Account(500));

  // Account account = Account(accounts);
  ATM atm(accounts);
  //   ATM atm(account);
  //   for (auto account : accounts) {
  //     cout << account.getBalance() << endl;
  //   }

  //   cout << account.getBalance() << std::endl;

  run_menu(atm);
  //   display_balance(accounts[1]);
  //   show_balance(accounts[1]);

  // atm.display_balance();

  // Account account = get_account();
  // account.balance = 200;  bad code
  //// cout << account.getBalance() << "\n";
  // account.deposit(123.45);

  // display_balance(account);

  // atm.make_deposit();
  // atm.display_balance();

  // atm.make_withdraw();
  // atm.display_balance();
  // display_menu();
  return 0;
}