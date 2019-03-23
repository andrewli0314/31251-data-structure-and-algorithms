#include <iostream>
using namespace std;
int main() {
  int foo = 5;
  int* a = &foo;
  int** b = &a;
  // cout << a << ", " << *a << ", " << &a << ", " << b << endl;
  // prints 0x61ff08, 5, 0x61ff04, 0x61ff04

  for (int i = 0; i < 10; ++i) {
    cout << (b + i) << endl;  // adding value to pointer
  }
}
