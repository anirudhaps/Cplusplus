#include <iostream>
#include <string>

struct Node {
  // here, the number of links are 26, each corresponds to a lowercase letter
  // (a,b,c...,z)
  Node *links[26];
  // this boolean tells whether the current node marks the end of a word
  bool end{false};

  bool containsKey(char ch) const;
  Node *getReferenceNode(char ch) const;
  void put(char ch, Node *node);
  void markEndOfWord();
  bool wordEnded() const;
};

class Trie {
public:
  Trie() { root = new Node(); }

  void insert(const std::string &word);
  bool search(const std::string &word) const;
  bool startsWith(const std::string &prefix) const;

private:
  Node *root;
};