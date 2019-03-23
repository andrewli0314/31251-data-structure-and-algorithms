// refer to a variable in another namespace.
// use scope resolution operator (::) -> refering to a variable in local or
// global scope or particular namespace
#include <iostream>
using namespace std;
int a = 10;  // This is a global variable

namespace private_space {
int a = -10;
}

int main() {
  int a = 20;
  cout << "Variable a (local) = " << a << endl;
  cout << "Variable a (global) = " << ::a << endl;
  cout << "Variable a (private_space) = " << private_space::a << endl;
  return 0;
}
