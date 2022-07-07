#include <iostream>
#include <memory>
#include <string>
using std::cout;
using std::make_unique;
using std::unique_ptr;
using std::endl;
using std::string;

using namespace std;
int main() {
  // this is the use of raw pointers; have to manually manage memory, new and
  // delete
  int *num{new int(5)};
  cout << *num << endl;
  delete num;
  num = nullptr;
  cout << num << endl;

  // Now using smart pointers
  unique_ptr<int> num_ptr{make_unique<int>(10)};
  cout << *num_ptr << endl;
  return 0;
}