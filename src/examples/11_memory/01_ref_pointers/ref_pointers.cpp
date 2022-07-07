#include "ref_pointers.h"

//

void ref_ptr(int &num, int *num1) {
  num = 100;
  *num1 = 200;
}