#include <iostream>
#include "stack.h"

int main() {
  stack<int> s;

  for (int i = 0; i < 20; i++) {
    s.push(i);
  }

  while (!s.empty()) {
    std::cout << s.pop() << " ";
  }
  std::cout << std::endl;
}