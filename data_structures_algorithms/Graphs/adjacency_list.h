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
  void setAdjList(const std::vector<std::list<int>> &adj_list) {
    adj_list_ = adj_list;
  }
  bool addEdge(int vertex1, int vertex2);
  void populate();
  void display() const;
  void dfs() const;
  void bfs() const;
  bool hasCycle() const;

private:
  void dfsUtil(int vertex, std::vector<bool> &visited) const;
  void bfsUtil(int vertex, std::vector<bool> &visited) const;
  bool hasCycleUtil(int vertex) const;

  std::vector<std::list<int>> adj_list_;
  int vertices_{0};
  int edges_{0};
  bool is_directed_{false};
};

} // namespace AdjacencyList

#endif