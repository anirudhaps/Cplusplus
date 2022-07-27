/**
 * @brief Given a string, find the length of the longest substring, which has
 * all distinct characters.
 */
#include <iostream>
#include <string>
#include <unordered_map>

int findNoRepeatSubstrMaxLength(const std::string &str) {
  if (str.length() == 0) {
    return 0;
  }
  std::unordered_map<char, int> count;
  int len = 0;
  int maxLen = 0;
  for (int start = 0, end = 0; end < str.length(); ++end) {
    if (count[str[end]] == 0) {
      ++count[str[end]];
      ++len;
      continue;
    }
    if (len > maxLen) {
      maxLen = len;
    }
    while (count[str[end]] > 0) {
      --count[str[start]];
      --len;
      ++start;
    }
    ++count[str[end]];
    ++len;
  }
  if (len > maxLen) {
    maxLen = len;
  }
  return maxLen;
}

int main() {
  std::cout << "aabccbb => " << findNoRepeatSubstrMaxLength("aabccbb") << "\n";
  std::cout << "abbbb => " << findNoRepeatSubstrMaxLength("abbbb") << "\n";
  std::cout << "abccde => " << findNoRepeatSubstrMaxLength("abccde") << "\n";
  std::cout << "a => " << findNoRepeatSubstrMaxLength("a") << "\n";
  std::cout << "ab => " << findNoRepeatSubstrMaxLength("ab") << "\n";
  std::cout << "abc => " << findNoRepeatSubstrMaxLength("abc") << "\n";
  std::cout << "abacde => " << findNoRepeatSubstrMaxLength("abacde") << "\n";
  std::cout << "aaaaa => " << findNoRepeatSubstrMaxLength("aaaaa") << "\n";
  return 0;
}