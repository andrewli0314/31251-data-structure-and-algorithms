#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <queue>
#include <stack>
#include <vector>

class graph {
 private:
  // Just for fun, an awful way to do it.
  // You may want to change this, but if you're unsure, it
  // definitely works.
  bool** adj_matrix;
  size_t size;

 public:
  // Same stuff as before
  graph(const size_t&);
  ~graph();

  void add_edge(const int&, const int&);
  void remove_edge(const int&, const int&);

  bool is_adjacent(const int&, const int&) const;

  // Depth-first traversal
  std::vector<int> dft(const int&) const;

  // Breadth-first traversal
  std::vector<int> bft(const int&) const;
};

#endif