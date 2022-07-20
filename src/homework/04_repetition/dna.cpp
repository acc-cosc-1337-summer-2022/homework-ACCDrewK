// add include statements
#include "dna.h"
#include <cctype>
#include <iostream>
// add function(s) code here
double get_gc_content(const std::string &raw_dna) {
  int c_count{0}, g_count{0};
  for (int n = 0; n < raw_dna.size(); ++n) {
    if (raw_dna[n] == 'G') {
      g_count++;
    } else if (raw_dna[n] == 'C') {
      c_count++;
    }
  }
  int gc_total = c_count + g_count;
  double percent_gc = gc_total / static_cast<double>(raw_dna.size());
  return percent_gc;
}

std::string get_reverse_string(std::string to_reverse) {
  std::string reverse_string{""};
  for (int i = 0; i < to_reverse.size(); ++i) {
    reverse_string = to_reverse[i] + reverse_string;
  }
  return reverse_string;
}

std::string get_dna_complement(std::string dna_strand) {
  std::string dna_reversed = get_reverse_string(dna_strand);
  std::string complement{""};
  for (int i = 0; i < dna_strand.size(); ++i) {
    switch (dna_reversed[i]) {
    case 'A':
      complement += 'T';
      break;
    case 'T':
      complement += 'A';
      break;
    case 'G':
      complement += 'C';
      break;
    case 'C':
      complement += 'G';
      break;
    default:
      std::cout << "Warning: invalid DNA base detected." << std::endl;
      break;
    }
  }
  return complement;
}
int display_menu() {
  int choice{0};
  std::cout << "Choose a menu option below:\n";
  std::cout << "0. Exit Program\n1. Get GC content of DNA strand\n2. Get "
               "complement of DNA strand\nEnter your selection: ";
  std::cin >> choice;
  return choice;
}

std::string get_dna_string() {
  std::string dna_string{""};
  std::cout << "Enter DNA strand: ";
  std::cin >> dna_string;
  return dna_string;
}