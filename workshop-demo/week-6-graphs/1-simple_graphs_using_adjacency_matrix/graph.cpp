#include "graph.h"

graph::graph(const size_t& size) {
  this->size = size;

  // // we need to resize the vector
  // adjacency_matrix.resize(this->size);

  // // BUt above code will not resizze the inner vecctor of
  // // std::vector<std::vector<bool> > so we need to loop thru each and resize
  // // those

  // for (int i = 0; i < this->size; i++) {
  //   adjacency_matrix[i].resize(this->size);
  //   // also set those inner vector's value to false
  //   for (int j = 0; j < this->size; j++) {
  //     adjacency_matrix[i][j] = false;
  //   }
  // }

  // Simpler code for above looping and resizing
  adjacency_matrix = std::vector<std::vector<bool> >(
      this->size, std::vector<bool>(this->size, false));
}

graph::~graph() {}

void graph::add_edge(const int& u, const int& v) {
  // bound check
  // u!=v  because in simple graphs theree is no self loop
  if (u > 0 && u < this->size && v > 0 && v < this->size && u != u) {
    adjacency_matrix[u][v] = true;
    adjacency_matrix[v][u] = true;
  }
}

void graph::remove_edge(const int& u, const int& v) {
  if (u > 0 && u < this->size && v > 0 && v < this->size && u != u) {
    adjacency_matrix[u][v] = false;
    adjacency_matrix[v][u] = false;
  }
}

bool graph::is_adjacent(const int& u, const int& v) {
  return adjacency_matrix[u][v];
}
