#include <iostream>
#include <string>

struct Node {
  Node *links[26];
  int ends_with{0};
  int prefix_count{0};

  bool containsKey(char ch) const;
  void put(char ch, Node *node);
  Node *getReferenceNode(char ch) const;
  void markEndOfWord();
  void decWordCount();
  int getWordCount() const;
  void incPrefixCount();
  void decPrefixCount();
  int getPrefixCount() const;
};

class Trie {
public:
  Trie() { root = new Node(); }

  void insert(const std::string &word);
  void erase(const std::string &word);
  int countWordsEqualTo(const std::string &word) const;
  int countWordsStartsWith(const std::string &prefix) const;

private:
  Node *root;
};