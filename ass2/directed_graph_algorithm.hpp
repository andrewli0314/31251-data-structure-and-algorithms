// /*
//  * Notice that the list of included headers has
//  * expanded a little. As before, you are not allowed
//  * to add to this.
//  */
// #include <algorithm>
// #include <array>
// #include <cstddef>
// #include <deque>
// #include <exception>
// #include <forward_list>
// #include <iostream>
// #include <limits>
// #include <list>
// #include <map>
// #include <optional>
// #include <queue>
// #include <set>
// #include <stack>
// #include <stdexcept>
// #include <string>
// #include <unordered_map>
// #include <unordered_set>
// #include <utility>
// #include <vector>

// #include "directed_graph.hpp"

// // has_leaf() transverse through the graph and returns if there is a leaf in
// // that graph
// template <typename vertex>
// bool has_leaf(directed_graph<vertex>& graph) {
//   // iterate throught the vertexof the graph
//   for (auto itr = graph.begin(); itr != graph.end(); itr++) {
//     // if the vertex in  this position has no out edge it is a leaf
//     if (graph.out_degree(*itr) == 0) {
//       return true;
//     }
//   }
//   return false;
// }

// /*
//  * Computes whether the input is a Directed Acyclic Graph (DAG).
//  * A digraph is a DAG if there is no vertex that has a cycle.
//  * A cycle is a non-empty set of [out-]edges that starts at one
//  * vertex, and returns to it.
//  */
// template <typename vertex>
// bool is_dag(const directed_graph<vertex>& d) {
//   directed_graph<vertex> graph = d;
//   // If the graph has no vertices, or a single vertex
//   // then the graph is acyclic
//   if (d.num_vertices() <= 1) return true;

//   for (auto itr = graph.begin(); itr != graph.end(); itr++) {
//     // if(graph.num_vertices() <= 1) return true;
//     if (graph.out_degree(*itr) == 0) {
//       graph.remove_vertex(*itr);
//     }
//   }
//   return has_leaf(graph);
// }

// // A helper function that pushes current vertex's neighbour recursively
// template <typename vertex>
// void push_neighbour(vertex v, std::map<vertex, bool>& visited,
//                     std::stack<vertex>& stack, directed_graph<vertex>& graph)
//                     {
//   visited[v] = true;
//   // iterate through neighour of passed vertex
//   for (auto itr = graph.nbegin(v); itr != graph.nend(v); ++itr) {
//     if (!visited[*itr]) {
//       push_neighbour(*itr, visited, stack, graph);
//     }
//   }
//   // push current vertex to satck which stores the final result
//   stack.push(v);
// }

// /*
//  * Computes a topological ordering of the vertices.
//  * For every vertex u in the order, and any of its
//  * neighbours v, v appears later in the order than u.
//  */
// template <typename vertex>
// std::list<vertex> topological_sort(const directed_graph<vertex>& d) {
//   // contains list of sorted vertex
//   std::list<vertex> sorted_list;
//   std::stack<vertex> stack;
//   directed_graph<vertex> graph = d;

//   // Initially, marking all the vertices as not visited (false)
//   std::map<vertex, bool> visited;
//   for (auto itr = graph.begin(); itr != graph.end(); ++itr) {
//     visited[*itr] = false;
//   }

//   // Iterate through each vertex and if its not visited before push its
//   // neighbour to stack
//   for (auto itr = graph.begin(); itr != graph.end(); itr++) {
//     if (!visited[*itr]) {
//       push_neighbour(*itr, visited, stack, graph);
//     }
//   }

//   // adding all stack's vertex to the list to be returned
//   while (!stack.empty()) {
//     sorted_list.push_back(stack.top());
//     stack.pop();
//   }

//   return sorted_list;
// }

// /*
//  * Given a DAG, computes whether there is a Hamiltonian path.
//  * a Hamiltonian path is a path that visits every vertex
//  * exactly once.
//  */
// template <typename vertex>
// bool is_hamiltonian_dag(const directed_graph<vertex>& d) {
//   std::map<vertex, std::vector<bool>> track;

//   return false;
// }

// /*
//  * Computes the weakly connected components of the graph.
//  * A [weak] component is the smallest subset of the vertices
//  * such that the in and out neighbourhood of each vertex in
//  * the set is also contained in the set.
//  */
// template <typename vertex>
// void components_util(vertex v, std::map<vertex, bool> visited,
//                      const directed_graph<vertex>& d,
//                      std::vector<std::vector<vertex>>& vector_of_components)
//                      {
//   visited[v] = true;
//   std::vector<vertex> another;
//   another.push_back(v);
//   vector_of_components.push_back(another);

//   for (auto itr = d.nbegin(v); itr != d.nend(v); ++itr) {
//     if (d.adjacent() && !visited[*itr]) {
//       components_util(*itr, visited, d, vector_of_components);
//     }
//   }
// }

// template <typename vertex>
// std::vector<std::vector<vertex>> components(const directed_graph<vertex>& d)
// {
//   std::vector<std::vector<vertex>> vector_of_components;

//   std::map<vertex, bool> visited;
//   for (auto itr = d.begin(); itr != d.end(); ++itr) {
//     visited[*itr] = false;
//   }

//   for (auto itr = d.begin(); itr != d.end(); ++itr) {
//     if (!visited[*itr]) {
//       components_util(*itr, visited, d, vector_of_components);
//     }
//   }
//   return vector_of_components;
// }

// /*
//  * Computes the strongly connected components of the graph.
//  * A strongly connected component is a subset of the vertices
//  * such that for every pair u, v of vertices in the subset,
//  * v is reachable from u and u is reachable from v.
//  */
// template <typename vertex>
// std::vector<std::vector<vertex>> strongly_connected_components(
//     const directed_graph<vertex>& d) {
//   return std::vector<std::vector<vertex>>();
// }

// /*
//  * Computes the shortest distance from u to every other vertex
//  * in the graph d. The shortest distance is the smallest number
//  * of edges in any path from u to the other vertex.
//  * If there is no path from u to a vertex, set the distance to
//  * be the number of vertices in d plus 1.
//  */
// template <typename vertex>
// std::unordered_map<vertex, std::size_t> shortest_distances(
//     const directed_graph<vertex>& d, const vertex& u) {
//   std::unordered_map<vertex, std::size_t> distance_map;
//   for (auto itr = d.begin(); itr != d.end(); ++itr) {
//     distance_map[*itr] = -1;
//   }

//   // use bft
//   std::map<vertex, bool> track_visited;
//   for (auto itr = d.begin(); itr != d.end(); ++itr) {
//     track_visited[*itr] = false;
//   }

//   std::queue<vertex> unprocessed_queue;
//   vertex start = u;
//   distance_map[u] = 0;
//   track_visited[u] = true;
//   unprocessed_queue.push(start);

//   while (!unprocessed_queue.empty()) {
//     vertex u = unprocessed_queue.front();
//     unprocessed_queue.pop();

//     if (!track_visited[u]) {
//       track_visited[u] = true;
//       for (auto itr = d.begin(); itr != d.end(); ++itr) {
//         if (d.adjacent(u, *itr) && track_visited[*itr] == false) {
//           track_visited[*itr] = true;
//           unprocessed_queue.push(*itr);
//           distance_map[*itr] = distance_map[u] + 1;
//         }
//       }
//     }
//   }
//   return distance_map;
// }
