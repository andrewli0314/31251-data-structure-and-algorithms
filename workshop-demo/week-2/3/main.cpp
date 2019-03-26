#include <iostream>
#include "node.h"

int main() {
  node* head = new node(0);

  node* curr = head;

  for (int i = 1; i < 10; i++) {
    node* n = new node(i, nullptr);
    curr->set_next(n);
    curr = n;
  }

  curr = head;
  while (curr != nullptr) {
    std::cout << curr->get_data() << " ";
    curr = curr->get_next();
  }
  std::cout << std::endl;

  delete head;
}