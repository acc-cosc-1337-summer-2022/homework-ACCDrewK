// write include statements
#include "decisions.h"
#include <iomanip>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  vector<string> letter_list = {};
  vector<int> credit_hours_list = {};
  vector<string> class_names = {};
  int total_credits_earned = 0, total_credit_hours = 0, list_size = 0;
  double total_gpa = 0.0;
  bool continue_flag = true;
  string should_continue;

  cout << "*** GPA Calculator ***" << endl;
  cout << "\nThis program will calculate the GPA of all your classes, and tell "
          "you what your total GPA will be. It "
          "will also tell you how many credits you have earned through your "
          "classes.\n";
  cout << "To begin, enter your class information in the prompt below, then "
          "follow the on-screen instructions.\n";
  do {
    class_names.push_back(get_class_name());
    letter_list.push_back(get_letter_grade());
    credit_hours_list.push_back(get_class_credits());

    cout << "Do you wish to enter another class?: (y/n) ";
    cin >> should_continue;
    if (!(should_continue == "y" || should_continue == "Y"))
      continue_flag = false;
    cin.ignore(100, '\n');
  } while (continue_flag);

  list_size = letter_list.size();
  for (int n = 0; n < list_size; ++n) {
    total_credits_earned +=
        calc_credits_earned(letter_list[n], credit_hours_list[n]);
    total_credit_hours += credit_hours_list[n];
  }
  total_gpa = calculate_gpa(total_credit_hours, total_credits_earned);
  if (total_gpa < 0) {
    cout << "The program was unable to calculate a valid GPA for your classes, "
            "please re-run the program and try again."
         << endl;
  } else {
    cout << std::fixed << std::showpoint << std::setprecision(2) << endl;
    for (int n = 0; n < list_size; ++n) {
      cout << "For " << class_names[n] << ", you earned "
           << calc_credits_earned(letter_list[n], credit_hours_list[n])
           << " credits, with a class GPA of "
           << static_cast<double>(get_grade_points(letter_list[n])) << endl;
    }
    cout << "\nYour total number of credits is " << total_credits_earned
         << endl;
    cout << "Your total GPA is " << total_gpa;
  }
  return 0;
}