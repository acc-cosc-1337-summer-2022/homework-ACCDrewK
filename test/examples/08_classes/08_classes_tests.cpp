#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this
                          // in one cpp file
#include "bank_account.h"
#include "catch.hpp"
#include "checking_account.h"
#include "savings_account.h"
#include <chrono>
#include <random>

TEST_CASE("Verify Test Configuration", "verification") {
  REQUIRE(true == true);
}

TEST_CASE("Test bank initial value is 15") {
  CheckingAccount account;
  REQUIRE(account.getBalance() == 5);
}

TEST_CASE("Test account constructor") {
  CheckingAccount account{100};
  REQUIRE(account.getBalance() == 100);
}

TEST_CASE("Test deposit function") {
  Account account(100);
  REQUIRE(account.getBalance() == 100);
  account.deposit(50);
  REQUIRE(account.getBalance() == 150);
}

TEST_CASE("Test withdraw function") {
  Account account(100);
  account.withdraw(50);
  REQUIRE(account.getBalance() == 50);
  account.withdraw(60);
  REQUIRE(account.getBalance() == 50);
  account.deposit(50);
  account.withdraw(-1);
  REQUIRE(account.getBalance() == 100);
}

TEST_CASE("TEST random number generation") {
  int seed = std::chrono::steady_clock::now().time_since_epoch().count();
  std::mt19937_64 atm_rand(seed);
  std::uniform_int_distribution<int> dist(0, 4);
  int num{dist(atm_rand)};

  REQUIRE((num >= 0 && num <= 4));
}