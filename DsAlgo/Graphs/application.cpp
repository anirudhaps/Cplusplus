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

void runTest(int vertices, int edges, bool is_directed,
             const std::vector<std::list<int>> &adj_list) {
  AdjacencyList::Graph g(vertices, edges, is_directed);
  g.setAdjList(adj_list);
  std::cout << "\nAdjacency List Representation of the graph:\n";
  g.display();
  if (g.hasCycle()) {
    std::cout << "Has cycle\n";
  } else {
    std::cout << "No cycle\n";
  }
}

int main() {
  /*int vertices, edges;
  bool is_directed = false;
  std::cout << "Enter number of vertices: ";
  std::cin >> vertices;
  std::cout << "Enter number of edges: ";
  std::cin >> edges;
  std::cout << "Is this a directed graph?: ";
  std::cin >> std::boolalpha >> is_directed;
  adjListOperations(vertices, edges, is_directed);*/
  // adjMatrixOperations(vertices, edges, is_directed);
  runTest(6, 7, true,
          {std::list<int>({1}), std::list<int>({5, 2}), std::list<int>({3, 5}),
           std::list<int>({2, 4}), std::list<int>(), std::list<int>()});
  runTest(2, 0, true, {});
  runTest(2, 1, true, {std::list<int>({1}), std::list<int>()});
  runTest(2, 1, true, {std::list<int>(), std::list<int>({0})});
  runTest(2, 2, true, {std::list<int>({1}), std::list<int>({0})});
  runTest(3, 2, true, {std::list<int>({1}), std::list<int>({2}), std::list<int>()});
  runTest(3, 3, true, {std::list<int>({1}), std::list<int>({2}), std::list<int>({0})});
  runTest(3, 3, true, {std::list<int>({1, 2}), std::list<int>({2}), std::list<int>()});
  return 0;
}