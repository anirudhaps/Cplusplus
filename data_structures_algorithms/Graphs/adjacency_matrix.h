#ifndef ADJACENCY_MATRIX_H
#define ADJACENCY_MATRIX_H

#include <iostream>
#include <queue>
#include <vector>

namespace AdjacencyMatrix {

class Graph {
public:
  Graph(int vertices, int edges, bool directed = false);
  void populate();
  void display() const;
  void bfs() const;
  void dfs() const;

private:
  void bfsUtil(int vertex, std::vector<bool> &visited) const;
  void dfsUtil(int vertex, std::vector<bool> &visited) const;

  std::vector<std::vector<int>> matrix_;
  int vertices_{0};
  int edges_{0};
  bool is_directed_{false};
};

} // namespace AdjacencyMatrix

#endif