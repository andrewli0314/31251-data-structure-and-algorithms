#include <iostream>

int fib_rec(int n) {
  // Code goes here.
  // 1, 1, 2, 3, 5, 8, 13,....

  /* Without recursion
  int a = 1;
  int b = 1;
  int x = 0;

  for(int i = 0; i <10; i++){
          if(i == 0) {
                  x = 1;
                  std::cout<<x<<", ";
                  continue;
          }
          if( i == 1){
                  x = 1;
                  continue;
          }
          std::cout<<x<<", ";
          x = a + b;
  a = b;
  b = x;
  }
  */
  return 0;
}

int main() {
  std::cout << "Enter a number: " << std::endl;

  int n;
  std::cin >> n;

  std::cout << "The nth Fibonacci number is: " << fib_rec(n) << std::endl;
}