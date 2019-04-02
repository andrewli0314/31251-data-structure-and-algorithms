#include <iostream>
#include <queue>
#include <vector>  //You will need to pick a suitable container to include

int main() {
  std::queue<int> q;  // How do you instantiate it?

  for (int i = 0; i < 20; i++) {
    q.push(i);  // the C++ queue uses "push" instead of "offer"
  }

  while (!q.empty()) {
    std::cout << q.front() << " ";
    q.pop();  // This is an odd choice by the C++ developers
              // Pop just removes the element, but doesn't return
              // it, you have to do two operations to return and
              // remove...
  }

  std::cout << std::endl;
}