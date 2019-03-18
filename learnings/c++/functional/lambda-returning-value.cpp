#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

auto main() -> int {
  cout << "[Lambda_returning_value.cpp]" << '\n';

  vector<int> vect;
  for (int i = 0; i < 10; ++i) vect.push_back(i);

  cout << "Original Data:" << '\n';

  for_each(begin(vect), end(vect), [](int n) { cout << n << " "; });
  cout << endl;

  vector<int> vect2;
  vect2.resize(vect.size());
  transform(begin(vect), end(vect), begin(vect2), [](int n) { return n * n; });

  cout << "Squared Data:" << endl;
  for_each(begin(vect2), end(vect2), [](int n) { cout << n << " "; });

  vector<double> vect3;
  vect3.resize(vect2.size());
  transform(begin(vect2), end(vect2), begin(vect3),
            [](int n) -> double { return n / 2.0; });

  cout << "Averaged Data:" << endl;
  for_each(begin(vect3), end(vect3), [](double d) { cout << d << " "; });

  cout << endl;
  return 0;
}