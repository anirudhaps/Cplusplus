#include "trie.h"
#include <vector>

/**
 * @brief returns the longest complete string from the input array
 */
std::string longestCompleteString(const std::vector<std::string> &input) {
  Trie tr;
  for (auto &str : input) {
    tr.insert(str);
  }
  std::string longest = "";
  for (auto &str : input) {
    if (!tr.isCompleteString(str)) {
      continue;
    }
    if (str.length() > longest.length()) {
      longest = str;
    } else if (str.length() == longest.length()) {
      if (str.compare(longest) < 0) {
        longest = str;
      }
    }
  }
  return longest.length() == 0 ? "None" : longest;
}

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

  std::cout << "Longest complete string: "
            << longestCompleteString({"n", "ninja", "ni", "ninj", "nin",
                                      "ninga", "ning", "abcde", "a", "ab",
                                      "abc", "abcd"})
            << std::endl;
  std::cout << "Longest complete string: "
            << longestCompleteString({"abc", "an"}) << std::endl;
  return 0;
}