// write include required statements
#include <iostream>
#include <string>
#include <vector>
// Write a function(s) prototype  here

double calculate_gpa(int credit_hours, double credit_points);
int get_grade_points(std::string letter_grade);
int calc_credits_earned(std::string letter_grade, int credit_hours);
bool check_input_letter_grade(std::string user_input);

// user input functions
std::string get_class_name();
int get_class_credits();
std::string get_letter_grade();