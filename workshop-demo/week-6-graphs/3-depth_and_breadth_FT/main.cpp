#include <iomanip>
#include <iostream>
#include "graph.h"

int main() {
  std::cout << std::boolalpha;

  graph g(5);

  g.add_edge(0, 1);
  g.add_edge(1, 2);
  g.add_edge(1, 3);
  g.add_edge(0, 3);
  g.add_edge(3, 4);
  g.add_edge(2, 4);

  std::vector<int> ord = g.dft(0);

  std::cout << "Depth-first order starting at 0:" << std::endl;
  for (auto i : ord) {
    std::cout << i << ' ';
  }
  std::cout << std::endl;

  ord = g.dft(3);

  std::cout << "Depth-first order starting at 3:" << std::endl;
  for (auto i : ord) {
    std::cout << i << ' ';
  }
  std::cout << std::endl;

  ord = g.bft(2);

  std::cout << "Breadth-first order starting at 2:" << std::endl;
  for (auto i : ord) {
    std::cout << i << ' ';
  }
  std::cout << std::endl;
}