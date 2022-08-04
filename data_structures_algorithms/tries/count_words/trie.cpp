#include "trie.h"

bool Node::containsKey(char ch) const { return links[ch - 'a'] != nullptr; }

void Node::put(char ch, Node *node) { links[ch - 'a'] = node; }

Node *Node::getReferenceNode(char ch) const { return links[ch - 'a']; }

void Node::markEndOfWord() { ++ends_with; }

void Node::decWordCount() { --ends_with; }

int Node::getWordCount() const { return ends_with; }

void Node::incPrefixCount() { ++prefix_count; }

void Node::decPrefixCount() { --prefix_count; }

int Node::getPrefixCount() const { return prefix_count; }

void Trie::insert(const std::string &word) {
  Node *itr = root;
  for (int i = 0; i < word.length(); ++i) {
    if (!itr->containsKey(word[i])) {
      itr->put(word[i], new Node());
    }
    itr = itr->getReferenceNode(word[i]);
    itr->incPrefixCount();
  }
  itr->markEndOfWord();
}

int Trie::countWordsEqualTo(const std::string &word) const {
  Node *itr = root;
  for (int i = 0; i < word.length(); ++i) {
    if (!itr->containsKey(word[i])) {
      return 0;
    }
    itr = itr->getReferenceNode(word[i]);
  }
  return itr->getWordCount();
}

int Trie::countWordsStartsWith(const std::string &prefix) const {
  Node *itr = root;
  for (int i = 0; i < prefix.length(); ++i) {
    if (!itr->containsKey(prefix[i])) {
      return 0;
    }
    itr = itr->getReferenceNode(prefix[i]);
  }
  return itr->getPrefixCount();
}

void Trie::erase(const std::string &word) {
  Node *itr = root;
  for (int i = 0; i < word.length(); ++i) {
    if (!itr->containsKey(word[i])) {
      return;
    }
    itr = itr->getReferenceNode(word[i]);
    itr->decPrefixCount();
  }
  itr->decWordCount();
}