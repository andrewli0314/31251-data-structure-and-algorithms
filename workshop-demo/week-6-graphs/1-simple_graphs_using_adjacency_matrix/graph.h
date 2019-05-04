#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>

class graph {
 private:
  // represents a matrix of boolean (if weight use int)
  std::vector<std::vector<bool> > adjacency_matrix;
  // store size of that matrix
  size_t size;

 public:
  // A constructor that takes the size of
  // the graph.
  graph(const size_t&);

  // You may or may not need a destructor, depending on how you do things
  ~graph();

  // Methods to add or remove edges between two vertices.
  void add_edge(const int&, const int&);
  void remove_edge(const int&, const int&);

  // A method to test whether two vertices are adjacent.
  bool is_adjacent(const int&, const int&);

  void to_string(const size_t&);
};

#endif