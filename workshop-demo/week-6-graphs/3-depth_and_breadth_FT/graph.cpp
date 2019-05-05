#include "graph.h"

// Some free code!
// The two interesting methods are down the bottom.

graph::graph(const size_t& size) {
  this->size = size;
  adj_matrix = new bool*[this->size];

  for (int i = 0; i < this->size; i++) {
    adj_matrix[i] = new bool[this->size];
    for (int j = 0; j < this->size; j++) {
      adj_matrix[i][j] = false;
    }
  }
}

graph::~graph() {
  for (int i = 0; i < this->size; i++) {
    delete adj_matrix[i];
  }
  delete[] adj_matrix;
}

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

bool graph::is_adjacent(const int& u, const int& v) const {
  if ((u >= 0) && (u < size) && (v >= 0) && (v < size)) {
    return adj_matrix[u][v];
  }
  return false;
}

std::vector<int> graph::dft(const int& start) const {
  std::stack<int> unprocessed_stack;
  std::vector<int> dtf_vector;

  unprocessed_stack.push(start);
  std::vector<bool> track_visited = std::vector<bool>(size, false);

  while (!unprocessed_stack.empty()) {
    // pop a vertex from the stack
    int u = unprocessed_stack.top();
    unprocessed_stack.pop();

    // if the vertex u is not visited and add its unvisited adjacent vertex
    // to that unprocessed stack
    if (!track_visited[u]) {
      track_visited[u] = true;
      dtf_vector.push_back(u);
      for (int i = size; i >= 0; i--) {
        if (track_visited[i] == false && is_adjacent(u, i)) {
          unprocessed_stack.push(i);
        }
      }
    }
  }

  return dtf_vector;
}

std::vector<int> graph::bft(const int& start) const {
  std::queue<int> unprocessed_queue;
  unprocessed_queue.push(start);
  std::vector<int> bft_vector;
  std::vector<bool> track_visited = std::vector<bool>(size, false);

  while (!unprocessed_queue.empty()) {
    // pop a vertex from the stack
    int u = unprocessed_queue.front();
    unprocessed_queue.pop();

    if (!track_visited[u]) {
      track_visited[u] = true;
      bft_vector.push_back(u);
      for (int i = 0; i < size; i++) {
        if (is_adjacent(u, i) && track_visited[i] == false) {
          unprocessed_queue.push(i);
        }
      }
    }
  }

  return bft_vector;
}