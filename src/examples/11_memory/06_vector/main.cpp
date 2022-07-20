//
#include "my_vector.h"
#include <iostream>
#include <vector>
using namespace std;

template <typename T> T add(T x, T y) { return x + y; }
int main() {
  // vector<int>
  // use_stack_vector();
  // use_heap_vector();
  // Vector v(3);
  // std::cout << "Exiting program..." << std::endl;

  // Vector<int> v{1};
  // std::cout << v[0];
  // v[0] = 15;
  // return 0;

  /* cout << "int " << add(3, 3) << std::endl;
  cout << "double " << add(6.1, 6.2) << std::endl; */

  //   Vector<int> nums;
  //   nums.Push_Back(5);
  //   cout << nums[0] << std::endl;
  //   Vector<double> doubles;
  //   doubles.Push_Back(7.9);
  //   cout << doubles[0] << std::endl;

  Vector<int> nums;
  nums.Push_Back(4);
  nums.Push_Back(9);
  nums.Push_Back(10);
  cout << nums.Capacity() << endl;

  /*     vector<int> nums{4, 9, 10};
      cout << "Size: " << nums.size() << endl;
      cout << "Capacity: " << nums.capacity() << endl;
      nums.push_back(30);
      cout << "Size: " << nums.size() << endl;
      cout << "Capacity: " << nums.capacity() << endl;
   */
}
