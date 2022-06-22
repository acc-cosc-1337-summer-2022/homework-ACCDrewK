// atm.cpp
#include "atm.h"
#include <cctype>
// #include <cstdio>  // NULL
#include <chrono> // time
#include <iostream>
#include <random> // rand and srand

void ATM::display_balance() {
  std::cout << "Your balance is $" << account.getBalance() << std::endl;
}

void ATM::make_deposit() {
  int seed = std::chrono::steady_clock::now().time_since_epoch().count();
  std::mt19937_64 atm_rand(seed);
  std::uniform_int_distribution<int> dist(1, 1000);

  int amount{dist(atm_rand)};
  std::cout << "Validate deposit amount: $" << amount
            << std::endl; // between 1 and 100
  account.deposit(amount);
}

void ATM::make_withdraw() {
  int amount;
  std::cout << "Enter withdraw amount: ";
  std::cin >> amount;
  account.withdraw(amount);
}

// FREE FUNCTIONS

void display_menu() {
  std::cout << "1. Make deposit" << std::endl;
  std::cout << "2. Make withdraw" << std::endl;
  std::cout << "3. Display balance" << std::endl;
  std::cout << "4. Exit" << std::endl;
  std::cout << "Enter your choice: ";
  //   int choice;
  //   std::cin >> choice;
}

void run_menu() {
  auto choice{'y'};
  auto menu_choice{0};
  Account account{500}; // not how it should work, quick and dirty example
  ATM atm{account};
  do {
    display_menu();
    std::cin >> menu_choice;
    // call ATM Functions
    handle_transaction(atm, menu_choice);
    std::cout << "Continue? ";
    std::cin >> choice;
  } while (toupper(choice) == 'Y');
}

void handle_transaction(ATM &atm, int choice) {
  switch (choice) {
  case 1:
    atm.make_deposit();
    break;
  case 2:
    atm.make_withdraw();
    break;
  case 3:
    atm.display_balance();
    break;
  case 4:
    break;
  default:
    std::cout << "Invalid choice." << std::endl;
    break;
  }
}