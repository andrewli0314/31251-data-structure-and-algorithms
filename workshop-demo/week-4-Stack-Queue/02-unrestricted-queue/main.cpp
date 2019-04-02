#include <iostream>
#include "queue.h"

int main() {
  int capacity;
  std::cout << "Enter initial queue length: ";
  std::cin >> capacity;

  queue<int> q(capacity);

  for (int i = 0; i < capacity; i++) {
    q.offer(i);
  }

  while (!q.empty()) {
    std::cout << q.poll() << std::endl;
  }

  std::cout << "Overfilling the queue." << std::endl;

  for (int i = 0; i < 2 * capacity; i++) {
    q.offer(i);
  }

  while (!q.empty()) {
    std::cout << q.poll() << std::endl;
  }
}