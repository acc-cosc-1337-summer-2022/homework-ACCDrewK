// write include statements
#include "dna.h"
#include <iostream>
// write using statements
using std::cin;
using std::cout;
using std::endl;
using std::string;

/*
Write code that prompts user to enter 1 for Get GC Content,
or 2 for Get DNA Complement.  The program will prompt user for a
DNA string and call either get gc content or get dna complement
function and display the result. Program runs as long as
user enters a y or Y.
*/
int main() {
  cout << "\n***DNA Sequence GC Content Calculator and Sequence Complement "
          "Generator***\n";
  cout << "\nThis program will allow you to calculate the GC content of a "
          "sequence of DNA, as well as display the complement of that "
          "sequence.\n";
  bool cont_program{true};
  char confirm{'\0'};
  char menu_flag{'Y'};

  do {
    do {
      int choice{display_menu()};
      if (choice == 0) {
        cont_program = false;
        menu_flag = 'N';
      } else if (choice == 1 || choice == 2) {
        const string dna_strand = get_dna_string();
        if (choice == 1) {
          double gc_content = get_gc_content(dna_strand);
          cout << "GC content of entered DNA strand: " << gc_content << endl;
        } else {
          string dna_complement = get_dna_complement(dna_strand);
          cout << "DNA complement of entered DNA: " << dna_complement << endl;
        }
      } else {
        cout << "Invalid input, please choose one of the three menu options."
             << endl;
      }
      if (toupper(menu_flag) == 'Y') {
        cout << "Do you wish to return to the program menu? (y/n) ";
        cin >> menu_flag;
      }

    } while (toupper(menu_flag) == 'Y');
    cout << "Do you really wish to quit? (y/n): ";
    cin >> confirm;
    if (toupper(confirm) == 'Y') {
      cont_program = false;
    } else {
      menu_flag = 'Y';
      cont_program = true;
    }
  } while (cont_program);
  return 0;
}