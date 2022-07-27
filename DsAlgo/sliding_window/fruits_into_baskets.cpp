/**
 * @brief You are visiting a farm to collect fruits. The farm has a single row of
 * fruit trees. You will be given two baskets, and your goal is to pick as many
 * fruits as possible to be placed in the given baskets. You will be given an
 * array of characters where each character represents a fruit tree. The farm
 * has following restrictions:
 * - Each basket can have only one type of fruit. There is no limit to how many
 * fruit a basket can hold.
 * - You can start with any tree, but you can’t skip a tree once you have
 * started.
 * - You will pick exactly one fruit from every tree until you cannot, i.e.,
 * you will stop when you have to pick from a third fruit type.
 * Write a function to return the maximum number of fruits in both baskets.
 */

#include <iostream>
#include <vector>
#include <unordered_map>

int maxNumberOfFruits(const std::vector<char>& fruit_trees) {
  if (fruit_trees.size() == 0 || fruit_trees.size() == 1) {
    return fruit_trees.size();
  }
  std::unordered_map<char, int> types;
  int count{};
  int maxCount{};
  for (int start{}, end{}; end < fruit_trees.size(); ++end) {
    if (types.find(fruit_trees[end]) != types.end() || types.size() < 2) {
      ++count;
      ++types[fruit_trees[end]];
      continue;
    }
    if (count > maxCount) {
      maxCount = count;
    }
    while (types.size() == 2) {
      --types[fruit_trees[start]];
      --count;
      if (types[fruit_trees[start]] == 0) {
        types.erase(fruit_trees[start]);
      }
      ++start;
    }
    ++types[fruit_trees[end]];
    ++count;
  }

  if (count > maxCount) {
    maxCount = count;
  }
  return maxCount;
}
// A, B, C, A, C => 3
// A => 1
// A, B => 2
// A, A => 2
// A, A, B => 3
// A, A, B, B => 4
// A, A, B, B, C, C, C, D => 5

int main() {
  std::cout << "A => " << maxNumberOfFruits({'A'}) << "\n";
  std::cout << "A, A => " << maxNumberOfFruits({'A', 'A'}) << "\n";
  std::cout << "A, B => " << maxNumberOfFruits({'A', 'B'}) << "\n";
  std::cout << "A, A, B => " << maxNumberOfFruits({'A', 'A', 'B'}) << "\n";
  std::cout << "A, A, B, B => " << maxNumberOfFruits({'A', 'A', 'B', 'B'}) << "\n";
  std::cout << "A, A, B, B, C, C, C => " << maxNumberOfFruits({'A', 'A', 'B', 'B', 'C', 'C', 'C'}) << "\n";
  std::cout << "A, A, B, B, C, C, C, D => " << maxNumberOfFruits({'A', 'A', 'B', 'B', 'C', 'C', 'C', 'D'}) << "\n";
  std::cout << "A, B, C, A, C => " << maxNumberOfFruits({'A', 'B', 'C', 'A', 'C'}) << "\n";
  std::cout << "A, A, C, A, C => " << maxNumberOfFruits({'A', 'A', 'C', 'A', 'C'}) << "\n";
  return 0;
}