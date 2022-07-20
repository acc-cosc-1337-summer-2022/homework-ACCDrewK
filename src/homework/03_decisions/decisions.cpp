// write include statement for decisions header
#include "decisions.h"
#include <cctype>

// Write code for function(s) code here
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

double calculate_gpa(const int credit_hours, const double credit_points) {
  double gpa = -1.0;

  if (credit_hours <= 0) {
    cout << "Error: credit hours must be greater than 0." << endl;
  } else if (credit_points <= 0) {
    cout << "Error: credit points must be greater than 0." << endl;
  } else {
    gpa = credit_points / credit_hours;
  }
  return gpa;
}

int get_grade_points(string letter_grade) {
  int grade_points;
  if (letter_grade == "a" || letter_grade == "A") {
    grade_points = 4;
  } else if (letter_grade == "b" || letter_grade == "B") {
    grade_points = 3;
  } else if (letter_grade == "c" || letter_grade == "C") {
    grade_points = 2;
  } else if (letter_grade == "d" || letter_grade == "D") {
    grade_points = 1;
  } else if (letter_grade == "f" || letter_grade == "F") {
    grade_points = 0;
  } else {
    grade_points = -1;
  };
  return grade_points;
}

int calc_credits_earned(string letter_grade, int credit_hours) {
  return get_grade_points(letter_grade) * credit_hours;
}

// Checks if the user's input is invalid for the letter_grade; it should not be
// a digit, whitespace, or more than one character. It also can't be any other
// character than A, B, C, D, or F. Returns true if the input is one of those.
bool check_input_letter_grade(string user_input) {
  bool invalid = true;
  if (user_input.size() != 1) {
  } else {
    char input_letter = user_input[0];
    if (isalpha(input_letter)) {
      if (toupper(input_letter) == 'A' || toupper(input_letter) == 'B' ||
          toupper(input_letter) == 'C' || toupper(input_letter) == 'D' ||
          toupper(input_letter) == 'F') {
        invalid = false;
      }
    }
  }
  return invalid;
}

// get class name from user
string get_class_name() {
  string class_name = "";
  cout << "\nEnter the name of the class: ";
  getline(cin, class_name);
  while (cin.fail()) {
    cout << "Error processing input, please re-enter the name again." << endl;
    cin.clear();
    cin.ignore(100, '\n');
    cout << "Enter the name of the class: ";
    getline(cin, class_name);
  }
  return class_name;
}

// get the letter grade for the class from the user
string get_letter_grade() {
  string letter_grade = "";
  cout << "Enter the letter grade received for this class: ";
  cin >> letter_grade;
  while (cin.fail() || check_input_letter_grade(letter_grade)) {
    cout << "Error: invalid input; please enter a single letter for the letter "
            "grade. ";
    cout << "Valid letter grades are 'A', 'B', 'C', 'D', and 'F'." << endl;
    cin.clear();
    cin.ignore(100, '\n');
    cout << "Enter the letter grade received for this class: ";
    cin >> letter_grade;
  }
  return letter_grade;
}

// get class credits from the user
int get_class_credits() {
  int credit_hours = 0;
  cout << "Enter the number of credits for this class: ";
  cin >> credit_hours;
  while (cin.fail() || credit_hours <= 0) {
    cout << "Error: invalid input; please enter a positive number for the "
            "number of credits."
         << endl;
    cin.clear();
    cin.ignore(100, '\n');
    cout << "Enter the number of credits for this class: ";
    cin >> credit_hours;
  }
  return credit_hours;
}