#include <iomanip>
#include <iostream>
#include "graph.h"

int main() {
  std::cout << std::boolalpha;

  graph g(4);

  g.add_edge(0, 1);
  g.add_edge(1, 2);
  g.add_edge(1, 3);
  g.add_edge(0, 3);

  std::cout << "Is vertex 0 adjacent to vertex 3? " << g.is_adjacent(0, 3)
            << std::endl;
  std::cout << "Is vertex 0 adjacent to vertex 2? " << g.is_adjacent(0, 2)
            << std::endl;
  std::cout << "Is vertex 1 adjacent to vertex 2? " << g.is_adjacent(1, 2)
            << std::endl;
  std::cout << "Is vertex 1 adjacent to vertex 3? " << g.is_adjacent(1, 3)
            << std::endl;
  std::cout << "Is vertex 2 adjacent to vertex 3? " << g.is_adjacent(2, 3)
            << std::endl;
  std::cout << "Is vertex 3 adjacent to itself? " << g.is_adjacent(3, 3)
            << std::endl;

  std::cout << "Removing some edges." << std::endl;
  g.remove_edge(0, 3);
  g.remove_edge(1, 2);

  std::cout << "Is vertex 0 still adjacent to vertex 3? " << g.is_adjacent(0, 3)
            << std::endl;
  std::cout << "Is vertex 0 still adjacent to vertex 2? " << g.is_adjacent(0, 2)
            << std::endl;
  std::cout << "Is vertex 1 still adjacent to vertex 2? " << g.is_adjacent(1, 2)
            << std::endl;
}