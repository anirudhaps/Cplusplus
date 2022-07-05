#ifndef ADJACENCY_LIST_H
#define ADJACENCY_LIST_H

#include <iostream>
#include <list>
#include <queue>
#include <vector>

namespace AdjacencyList {

// An graph implemented using adjacency list
class Graph {
public:
  // making directed = true makes the graph as directed
  Graph(int vertices, int edges, bool directed = false);
  void populate();
  void display() const;
  void dfs() const;
  void bfs() const;

private:
  void dfsUtil(int vertex, std::vector<bool> &visited) const;
  void bfsUtil(int vertex, std::vector<bool> &visited) const;

  std::vector<std::list<int>> adj_list_;
  int vertices_{0};
  int edges_{0};
  bool is_directed_{false};
};

} // namespace AdjacencyList

#endif