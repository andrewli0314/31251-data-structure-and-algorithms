#include <iostream>

long fib_itr(long n) {
  // Code goes here
  long a = 1;
  long b = 1;
  long x = 0;

  for (long i = 0; i < n; i++) {
    if (i == 0) {
      x = 0;
      continue;
    }

    if (i == 1) {
      x = 1;
      continue;
    }

    x = a + b;
    a = b;
    b = x;
  }

  return b;
}

int main() {
  std::cout << "Enter a number: " << std::endl;

  long n;
  std::cin >> n;

  std::cout << "The nth Fibonacci number is: " << fib_itr(n) << std::endl;
}