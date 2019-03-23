#include <iostream>
#include <string>

using namespace std;

int main() {
  int a, b, c;
  cout << "Enter 2 nos" << '\n';
  cin >> a >> b;
  c = a + b; 
  cout << "Sum is " << c << endl;

  string str;
  cout << "Whats your name?";
  cin >> str;
  getline(cin, str);
  std::cout << "Hello" << str;
}