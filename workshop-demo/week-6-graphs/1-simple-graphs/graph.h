#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>

class graph {
 private:
  // You will need to build some sort of internal
  // representation of the graph here.
  // If in doubt, have a look at the lecture slides.
  std::vector<std::vector<bool> > graphy;

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