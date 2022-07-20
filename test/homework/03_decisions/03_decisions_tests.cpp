#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this
                          // in one cpp file
#include "catch.hpp"
#include "decisions.h"

TEST_CASE("Verify Test Configuration", "verification") {
  REQUIRE(true == true);
}

TEST_CASE("Test calculate_gpa function") {
  REQUIRE(calculate_gpa(0, 0) == -1);
  REQUIRE(calculate_gpa(1, 0) == -1);
  REQUIRE(calculate_gpa(1, 1) == 1.0);
  REQUIRE(calculate_gpa(120, 390) == 3.25);
  REQUIRE(calculate_gpa(12, 45) == 3.75);
  REQUIRE(calculate_gpa(90, 180) == 2.0);
  REQUIRE(calculate_gpa(7, 27) - 3.85714285 <= 0.00001);
}

TEST_CASE("Test get_grade_points function") {
  REQUIRE(get_grade_points("a") == 4);
  REQUIRE(get_grade_points("b") == 3);
  REQUIRE(get_grade_points("c") == 2);
  REQUIRE(get_grade_points("d") == 1);
  REQUIRE(get_grade_points("e") == -1);
  REQUIRE(get_grade_points("f") == 0);
}

TEST_CASE("Test calc_credits_earned function") {
  REQUIRE(calc_credits_earned("A", 3) == 12);
  REQUIRE(calc_credits_earned("b", 3) == 9);
  REQUIRE(calc_credits_earned("C", 4) == 8);
  REQUIRE(calc_credits_earned("D", 3) == 3);
  REQUIRE(calc_credits_earned("f", 4) == 0);
}

TEST_CASE("Test check_input_letter_grade function") {
  REQUIRE(check_input_letter_grade("a") == false);
  REQUIRE(check_input_letter_grade("b") == false);
  REQUIRE(check_input_letter_grade("c") == false);
  REQUIRE(check_input_letter_grade("d") == false);
  REQUIRE(check_input_letter_grade("e") == true);
  REQUIRE(check_input_letter_grade("f") == false);
  REQUIRE(check_input_letter_grade("1") == true);
  REQUIRE(check_input_letter_grade(" ") == true);
}