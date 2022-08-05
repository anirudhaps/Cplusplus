#include "trie.h"

bool Node::containsKey(char ch) const { return links[ch - 'a'] != nullptr; }

void Node::put(char ch, Node *node) { links[ch - 'a'] = node; }

Node *Node::getReferenceNode(char ch) const { return links[ch - 'a']; }

int Trie::insertDistinctSubstrings(const std::string &str) {
  if (str.length() == 0) {
    return 0;
  }
  Node *itr = nullptr;
  int count = 0;
  for (int i = 0; i < str.length(); ++i) {
    itr = root;
    for (int j = i; j < str.length(); ++j) {
      if (!itr->containsKey(str[j])) {
        itr->put(str[j], new Node());
        ++count;
      }
      itr = itr->getReferenceNode(str[j]);
    }
  }
  return count;
}
