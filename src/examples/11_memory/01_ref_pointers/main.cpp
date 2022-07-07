#include "ref_pointers.h"
#include <iostream>

int main() {
  int num{5};
  int &num_ref{num};
  std::cout << "num value via num_ref " << num_ref << std::endl;
  std::cout << "num address " << &num << std::endl;
  std::cout << "num_ref address pointed to " << &num_ref << std::endl;

  int *num_ptr{&num};
  std::cout << "Address that num_ptr points too: " << num_ptr << std::endl;
  std::cout << "The value num_ptr points to " << *num_ptr << std::endl;
  return 0;
}