// atm.cpp
#include "atm.h"
#include "bank_account.h"
#include <cctype>
// #include <cstdio>  // NULL
#include <chrono> // time
#include <iostream>
#include <random> // rand and srand

void ATM::display_balance() {
  std::cout << "Your balance is $" << accounts[account_index].getBalance()
            << std::endl;
}

void ATM::make_deposit() {
  int seed = std::chrono::steady_clock::now().time_since_epoch().count();
  std::mt19937_64 atm_rand(seed);
  std::uniform_int_distribution<int> dist(1, 1000);

  int amount{dist(atm_rand)};
  std::cout << "Validate deposit amount: $" << amount
            << std::endl; // between 1 and 100
  accounts[account_index].deposit(amount);
}

void ATM::make_withdraw() {
  int amount;
  std::cout << "Enter withdraw amount: ";
  std::cin >> amount;
  accounts[account_index].withdraw(amount);
}

void ATM::scan_card() {
  using std::chrono::steady_clock;
  int seed = steady_clock::now().time_since_epoch().count();
  std::mt19937_64 atm_rand(seed);
  std::uniform_int_distribution<int> dist(0, accounts.size());

  int account_index{dist(atm_rand)};
  std::cout << account_index << std::endl;
}

// FREE FUNCTIONS--------------------------------------

void display_menu() {
  std::cout << "1. Make deposit" << std::endl;
  std::cout << "2. Make withdraw" << std::endl;
  std::cout << "3. Display balance" << std::endl;
  std::cout << "4. Exit" << std::endl;
  std::cout << "Enter your choice: ";
  //   int choice;
  //   std::cin >> choice;
}

void run_menu(ATM &atm) {
  auto choice{'y'};
  int menu_choice{0};
  auto confirm = 'N';
  do {
    atm.scan_card();
    //   Account account{500}; // not how it should work, quick and dirty
    //   example ATM atm{account};
    do {
      display_menu();
      std::cin >> menu_choice;
      transaction menu_choice_ = static_cast<transaction>(menu_choice);
      // call ATM Functions
      handle_transaction(atm, menu_choice_);
      std::cout << "Do another transaction? (y/n) ";
      std::cin >> choice;
    } while (toupper(choice) == 'Y');
    std::cout << "Do you really wish to log out? (Y/N) ";
    std::cin >> confirm;
  } while (toupper(confirm) != 'Y');
}

void handle_transaction(ATM &atm, transaction choice) {
  switch (choice) {
  case DEPOSIT:
    atm.make_deposit();
    break;
  case WITHDRAW:
    atm.make_withdraw();
    break;
  case DISPLAY:
    atm.display_balance();
    break;
  case EXIT:
    break;
  default:
    std::cout << "Invalid choice." << std::endl;
    break;
  };
}