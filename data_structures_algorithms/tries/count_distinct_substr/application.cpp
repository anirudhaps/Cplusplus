#include "trie.h"

int main() {
  {
    Trie tr;
    std::cout << "Number of distinct substrs of 'abab' including empty string: "
              << tr.insertDistinctSubstrings("abab") + 1 << "\n";
  }
  {
    Trie tr;
    std::cout
        << "Number of distinct substrs of 'ninja' including empty string: "
        << tr.insertDistinctSubstrings("ninja") + 1 << "\n";
  }
  {
    Trie tr;
    std::cout << "Number of distinct substrs of 'abc' including empty string: "
              << tr.insertDistinctSubstrings("abc") + 1 << "\n";
  }
  {
    Trie tr;
    std::cout << "Number of distinct substrs of 'abra' including empty string: "
              << tr.insertDistinctSubstrings("abra") + 1 << "\n";
  }
  return 0;
}