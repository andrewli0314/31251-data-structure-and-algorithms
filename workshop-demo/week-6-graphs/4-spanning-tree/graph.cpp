#include "graph.h"
#include <iostream>

graph::graph(const size_t& size) {
  this->size = size;
  adj_matrix.resize(this->size);

  for (unsigned i = 0; i < this->size; i++) {
    adj_matrix[i].resize(this->size);
    for (unsigned j = 0; j < this->size; j++) {
      adj_matrix[i][j] = false;
    }
  }
}

graph::~graph() {}

void graph::add_edge(const int& u, const int& v) {
  if ((u >= 0) && (u < size) && (v >= 0) && (v < size) && (u != v)) {
    adj_matrix[u][v] = true;
    adj_matrix[v][u] = true;
  }
}

void graph::remove_edge(const int& u, const int& v) {
  if ((u >= 0) && (u < size) && (v >= 0) && (v < size) && (u != v)) {
    adj_matrix[u][v] = false;
    adj_matrix[v][u] = false;
  }
}

bool graph::is_adjacent(const int& u, const int& v) {
  if ((u >= 0) && (u < size) && (v >= 0) && (v < size)) {
    return adj_matrix[u][v];
  }
  return false;
}

std::vector<int> graph::dft(const int& start) const {
  bool visited[size];
  for (unsigned i = 0; i < size; i++) {
    visited[i] = false;
  }

  std::stack<int> unprocessed;
  unprocessed.push(start);

  std::vector<int> ordered;

  while (!unprocessed.empty()) {
    int n = unprocessed.top();
    unprocessed.pop();
    if (!visited[n]) {
      visited[n] = true;
      ordered.push_back(n);
      for (unsigned i = size; i != 0; i--) {
        if (adj_matrix[n][i - 1]) {
          unprocessed.push(i - 1);
        }
      }
    }
  }

  return ordered;
}

std::vector<int> graph::bft(const int& start) const {
  bool visited[size];
  for (unsigned i = 0; i < size; i++) {
    visited[i] = false;
  }

  std::queue<int> unprocessed;
  unprocessed.push(start);

  std::vector<int> ordered;

  while (!unprocessed.empty()) {
    int n = unprocessed.front();
    unprocessed.pop();
    if (!visited[n]) {
      visited[n] = true;
      ordered.push_back(n);
      for (unsigned i = 0; i < size; i++) {
        if (adj_matrix[n][i]) {
          unprocessed.push(i);
        }
      }
    }
  }

  return ordered;
}

graph graph::spanning_tree(const int& start) const {
  // bft spanning tree
  graph min_tree(size);
  bool visited[size];
  for (unsigned i = 0; i < size; i++) {
    visited[i] = false;
  }
  std::vector<bool> tree_visited = std::vector<bool>(size, false);

  std::queue<int> unprocessed;
  unprocessed.push(start);

  while (!unprocessed.empty()) {
    int n = unprocessed.front();
    unprocessed.pop();
    if (!visited[n]) {
      visited[n] = true;
      for (unsigned i = 0; i < size; i++) {
        if (adj_matrix[n][i] && tree_visited[i] == false) {
          min_tree.add_edge(n, i);
          tree_visited[i] = true;
          unprocessed.push(i);
        }
      }
    }
  }

  return min_tree;
}
