#include "graph.h"

graph::graph(const size_t& size) {
  this->size = size;

  // Simpler code for above looping and resizing
  adjacency_list = std::vector<std::vector<int> >(
      this->size, std::vector<int>(this->size, false));
}

graph::~graph() {}

bool graph::contains(std::vector<int> c, int v) {
  // for each loop and type inference
  for (auto i : c) {
    if (i == v) return true;
  }
}

void graph::add_edge(const int& u, const int& v) {
  // bound check
  // u!=v  because in simple graphs theree is no self loop
  if (u > 0 && u < this->size && v > 0 && v < this->size && v != u) {
    if (!contains(adjacency_list[u], v)) adjacency_list[u].push_back(v);
    if (!contains(adjacency_list[v], u)) adjacency_list[v].push_back(u);
  }
}

void graph::remove_edge(const int& u, const int& v) {
  if (u > 0 && u < this->size && v > 0 && v < this->size && v != u) {
    for (auto itr = adjacency_list[u].begin(); itr < adjacency_list[u].end();
         ++itr) {
      // itr represents a position
      if (*itr == v) adjacency_list[u].erase(itr);
    }
    for (auto itr = adjacency_list[v].begin(); itr < adjacency_list[v].end();
         ++itr) {
      if (*itr == v) adjacency_list[v].erase(itr);
    }
  }
}

bool graph::is_adjacent(const int& u, const int& v) {
  return contains(adjacency_list[u], v);
}
