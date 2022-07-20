#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "hwexpressions.h"

TEST_CASE("Verify Test Configuration", "verification")
{
    REQUIRE(true == true);
}

TEST_CASE("Verify sum_numbers function")
{
    REQUIRE(add_numbers(5, 5) == 10);
    REQUIRE(add_numbers(10, 10) == 20);
}

// return product of meal_amount and tax_rate, tax_rate is 0.0675
TEST_CASE("Test Case 1, Name: Test Get Sales Tax")
{
    REQUIRE(get_sales_tax_amount(10) == 0.675);
    REQUIRE(get_sales_tax_amount(20) == 1.35);

    // sanity check
    REQUIRE(get_sales_tax_amount(0) == 0.0);
}

// return product of meal_amount and tip_rate, both doubles
TEST_CASE("Test Case 2, Name: Test Get Tip Amount")
{
    REQUIRE(get_tip_amount(20, 15) == 3);
    REQUIRE(get_tip_amount(20, 20) == 4);

    // sanity check
    REQUIRE(get_tip_amount(1, 0) == 0);
    REQUIRE(get_tip_amount(2, 200) == 4);
}

// tests for main program
TEST_CASE("Test Case 3, Name: Test Main Function Logic")
{
    double meal_amount = 20;
    double tax_amount = get_sales_tax_amount(meal_amount);
    REQUIRE(tax_amount == 1.35);
    double tip_rate = 15;
    double tip_amount = get_tip_amount(meal_amount, tip_rate);
    REQUIRE(tip_amount == 3);
    REQUIRE(tip_amount + tax_amount + meal_amount == 24.35);
}