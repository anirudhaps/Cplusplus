#include "adjacency_list.h"

namespace AdjacencyList {

Graph::Graph(int vertices, int edges, bool directed)
    : vertices_(vertices), edges_(edges), is_directed_(directed) {
  adj_list_.reserve(vertices);
  for (int i = 0; i < vertices; ++i) {
    adj_list_.push_back(std::list<int>());
  }
}

void Graph::populate() {
  int u, v;
  std::cout << "Enter " << edges_ << " edges:\n";
  for (int i = 0; i < edges_; ++i) {
    std::cin >> u >> v;
    if (u >= vertices_ || v >= vertices_) {
      std::cout << "Invalid input!\n";
      return;
    }
    adj_list_[u].push_back(v);
    if (!is_directed_) {
      adj_list_[v].push_back(u);
    }
  }
}

void Graph::display() const {
  int index = 0;
  for (const auto &list : adj_list_) {
    std::cout << index << ": ";
    for (const auto &element : list) {
      std::cout << element << " ";
    }
    ++index;
    std::cout << "\n";
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

  for (const auto &adj : adj_list_[vertex]) {
    if (!visited[adj]) {
      dfsUtil(adj, visited);
    }
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
    for (const auto &adj : adj_list_[current]) {
      if (!visited[adj]) {
        visited[adj] = true;
        bfs_queue.push(adj);
      }
    }
  }
}

} // namespace AdjacencyList
