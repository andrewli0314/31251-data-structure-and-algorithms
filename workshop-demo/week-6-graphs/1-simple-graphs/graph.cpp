#include "graph.h"

graph::graph(const size_t& size) {
  // Create adjacency matrix
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; i++) {
      graphy[i][j] = false;
    }
  }
}

graph::~graph() {}

void graph::add_edge(const int& u, const int& v) {
    graphy[u].pu
}

void graph::remove_edge(const int& u, const int& v) {}

bool graph::is_adjacent(const int& u, const int& v) { return false; }

void graph::to_string(const size_t& size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; i++) {
      graphy[i][j] = false;
    }
  }
}
