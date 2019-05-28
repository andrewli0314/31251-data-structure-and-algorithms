/*
 * A main function for you to build and run your
 * own tests with.
 * This file is not part of the marking, so you
 * can do anything you want here.
 */
#include <iostream>

#include "directed_graph_algorithms.cpp"

int main() {
  directed_graph<int> d;
  d.add_vertex(1);
  d.add_vertex(131);
  d.add_vertex(231);
  d.add_vertex(123);
  d.add_vertex(141);

  d.add_edge(1, 231);
  d.add_edge(231, 123);
  d.add_edge(123, 131);
  d.add_edge(123, 141);

  topological_sort(d);
}