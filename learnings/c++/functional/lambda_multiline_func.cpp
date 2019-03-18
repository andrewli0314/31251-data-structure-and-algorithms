#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

auto main() -> int {
  std::cout << "[lambda_multiline_func.cpp]" << '\n';
  vector<int> vect;

  for (int i = 0; i < 10; ++i) vect.push_back(i);

  for_each(begin(vect), end(vect), [](int n) {
    std::cout << n << " is";
    if (n < 2) {
      if (n == 0) cout << " not";
    } else {
      for (int j = 2; j < n; ++j) {
        if (n % j == 0) {
          std::cout << " not";
          break;
        }
      }
    }
    std::cout << " prime number " << endl;
  });
  return 0;
}