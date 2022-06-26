#ifndef DNA_H
#define DNA_H
// add include statements
#include <string>
/*
Write prototype for function(s)
*/
double get_gc_content(const std::string &);
std::string get_reverse_string(std::string);
std::string get_dna_complement(std::string);
int display_menu();
std::string get_dna_string();
#endif