#include "adjacency_matrix.h"

namespace AdjacencyMatrix {

Graph::Graph(int vertices, int edges, bool directed)
    : vertices_(vertices), edges_(edges), is_directed_(directed) {
  matrix_.reserve(vertices);
  for (int i = 0; i < vertices; ++i) {
    matrix_.emplace_back(vertices, 0);
  }
}

void Graph::populate() {
  int u, v; // identifier number for vertices
  std::cout << "Enter " << edges_ << " edges:\n";
  for (int i = 0; i < edges_; ++i) {
    std::cin >> u >> v;
    if (u >= vertices_ || v >= vertices_) {
      std::cout << "Invalid input!!\n";
      return;
    }
    matrix_[u][v] = 1;
    if (!is_directed_) {
      matrix_[v][u] = 1;
    }
  }
}

void Graph::display() const {
  for (const auto &arr : matrix_) {
    for (const auto &element : arr) {
      std::cout << element << " ";
    }
    std::cout << "\n";
  }
}

void Graph::bfs() const {
  std::vector<bool> visited(vertices_, false);

  for (int i = 0; i < vertices_; ++i) {
    if (!visited[i]) {
      bfsUtil(i, visited);
    }
  }
  std::cout << "\n";
}

void Graph::bfsUtil(int vertex, std::vector<bool> &visited) const {
  std::queue<int> bfs_queue;
  visited[vertex] = true;
  bfs_queue.push(vertex);

  int current;
  while (!bfs_queue.empty()) {
    current = bfs_queue.front();
    bfs_queue.pop();
    std::cout << current << " ";
    for (int i = 0; i < vertices_; ++i) {
      if (!visited[i] && matrix_[current][i] == 1) {
        visited[i] = true;
        bfs_queue.push(i);
      }
    }
  }
}

void Graph::dfs() const {
  std::vector<bool> visited(vertices_, false);

  for (int i = 0; i < vertices_; ++i) {
    if (!visited[i]) {
      dfsUtil(i, visited);
    }
  }
  std::cout << "\n";
}

void Graph::dfsUtil(int vertex, std::vector<bool> &visited) const {
  if (!visited[vertex]) {
    visited[vertex] = true;
    std::cout << vertex << " ";
  }

  for (int i = 0; i < vertices_; ++i) {
    if (!visited[i] && matrix_[vertex][i] == 1) {
      dfsUtil(i, visited);
    }
  }
}

} // namespace AdjacencyMatrix