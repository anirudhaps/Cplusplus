#include "trie.h"

// check if the character ch has a reference node maintained in the set of links
bool Node::containsKey(char ch) const { return links[ch - 'a'] != nullptr; }

// get reference trie-node corresponding to the character ch maintained in the
// set of links
Node *Node::getReferenceNode(char ch) const { return links[ch - 'a']; }

// put the reference trie-node for the character ch in the current node's links
void Node::put(char ch, Node *node) { links[ch - 'a'] = node; }

// mark the end of the word
void Node::markEndOfWord() { end = true; }

// is word ended
bool Node::wordEnded() const { return end; }

// insert the word in the trie: time complexity = O(length of word)
void Trie::insert(const std::string &word) {
  Node *itr = root;
  for (int i = 0; i < word.length(); ++i) {
    if (!itr->containsKey(word[i])) {
      itr->put(word[i], new Node());
    }
    itr = itr->getReferenceNode(word[i]);
  }
  itr->markEndOfWord();
}

// does trie contain this word: time complexity = O(length of word)
bool Trie::search(const std::string &word) const {
  Node *itr = root;
  for (int i = 0; i < word.length(); ++i) {
    if (!itr->containsKey(word[i])) {
      return false;
    }
    itr = itr->getReferenceNode(word[i]);
  }
  return itr->wordEnded();
}

// does trie contain a word that starts with this prefix: time complexity =
// O(length of prefix)
bool Trie::startsWith(const std::string &prefix) const {
  Node *itr = root;
  for (int i = 0; i < prefix.length(); ++i) {
    if (!itr->containsKey(prefix[i])) {
      return false;
    }
    itr = itr->getReferenceNode(prefix[i]);
  }
  return true;
}

bool Trie::isCompleteString(const std::string &str) const {
  Node *itr = root;
  for (int i = 0; i < str.length(); ++i) {
    if (!itr->containsKey(str[i])) {
      return false;
    }
    itr = itr->getReferenceNode(str[i]);
    if (!itr->wordEnded()) {
      return false;
    }
  }
  return true;
}
