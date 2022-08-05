#include <iostream>
#include <string>

struct Node {
  Node *links[26];
  Node() {
    for (int i = 0; i < 26; ++i) {
      links[i] = nullptr;
    }
  }

  bool containsKey(char ch) const;
  void put(char ch, Node *node);
  Node *getReferenceNode(char ch) const;
};

class Trie {
public:
  Trie() { root = new Node(); }

  // returns number of distinct substrs inserted in the trie
  int insertDistinctSubstrings(const std::string &str);

private:
  Node *root;
};