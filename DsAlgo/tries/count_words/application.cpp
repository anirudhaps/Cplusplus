#include "trie.h"

int main() {
  Trie tr;
  tr.insert("apple");
  tr.insert("apple");
  tr.insert("apps");
  std::cout << "No. of words equal to apple: " << tr.countWordsEqualTo("apple") << "\n";
  std::cout << "No. of words equal to apps: " << tr.countWordsEqualTo("apps") << "\n";
  std::cout << "No. of words equal to ares: " << tr.countWordsEqualTo("ares") << "\n";
  std::cout << "No. of words that start with app: " << tr.countWordsStartsWith("app") << "\n";
  std::cout << "No. of words that start with abc: " << tr.countWordsStartsWith("abc") << "\n";
  std::cout << "No. of words that start with appl: " << tr.countWordsStartsWith("appl") << "\n";
  return 0;
}