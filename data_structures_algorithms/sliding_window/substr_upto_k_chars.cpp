/**
 * @brief Given a string, find the length of the longest substring in it with
 * no more than K distinct characters.
 */
#include <iostream>
#include <unordered_map>

int maxSubStrLength(std::string input, int k) {
  if (input.length() == 0 || k == 0) {
    return 0;
  }
  std::unordered_map<char, int> count;
  int start, end;
  int max_len = 0;
  for (start = 0, end = 0; end < input.length(); ++end) {
    if (count.size() < k || count.find(input[end]) != count.end()) {
      ++count[input[end]];
      continue;
    }
    if ((end - start) > max_len) {
      max_len = end - start;
    }

    while (count.size() == k) {
      --count[input[start]];
      if (count[input[start]] == 0) {
        count.erase(input[start]);
      }
      ++start;
    }
    ++count[input[end]];
  }

  if ((end - start) > max_len) {
    max_len = end - start;
  }
  return max_len;
}

int main() {
  std::cout << "araaci, k=2 => " << maxSubStrLength("araaci", 2) << "\n";
  std::cout << "araaci, k=1 => " << maxSubStrLength("araaci", 1) << "\n";
  std::cout << "cbbebi, k=3 => " << maxSubStrLength("cbbebi", 3) << "\n";
  std::cout << "cbbebi, k=10 => " << maxSubStrLength("cbbebi", 10) << "\n";
  std::cout << "aaa, k=2 => " << maxSubStrLength("aaa", 2) << "\n";
  return 0;
}