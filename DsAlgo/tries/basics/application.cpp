#include "trie.h"

int main() {
  Trie tr;
  tr.insert("hello");
  tr.insert("hela");
  if (tr.search("hello")) {
    std::cout << "Trie contains word hello\n";
  }
  if (tr.search("hela")) {
    std::cout << "Trie contains word hela\n";
  }
  if (tr.startsWith("hel")) {
    std::cout << "Trie contains word(s) that start with prefix hel\n";
  }
  if (!tr.startsWith("hex")) {
    std::cout << "Trie does not contain word(s) that start with prefix hex\n";
  }
  return 0;
}