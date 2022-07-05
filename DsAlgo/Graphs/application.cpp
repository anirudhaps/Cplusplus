#include "adjacency_list.h"
#include "adjacency_matrix.h"

void adjListOperations(int vertices, int edges, bool is_directed) {
  AdjacencyList::Graph g(vertices, edges, is_directed);
  g.populate();
  std::cout << "\nAdjacency List Representation of the graph:\n";
  g.display();
  std::cout << "DFS:\n";
  g.dfs();
  std::cout << "BFS:\n";
  g.bfs();
}

void adjMatrixOperations(int vertices, int edges, bool is_directed) {
  AdjacencyMatrix::Graph g(vertices, edges, is_directed);
  g.populate();
  std::cout << "\nAdjacency Matrix Representation of the graph:\n";
  g.display();
  std::cout << "DFS:\n";
  g.dfs();
  std::cout << "BFS:\n";
  g.bfs();
}

int main() {
  int vertices, edges;
  bool is_directed = false;
  std::cout << "Enter number of vertices: ";
  std::cin >> vertices;
  std::cout << "Enter number of edges: ";
  std::cin >> edges;
  std::cout << "Is this a directed graph?: ";
  std::cin >> is_directed;
  adjListOperations(vertices, edges, is_directed);
  adjMatrixOperations(vertices, edges, is_directed);
  return 0;
}