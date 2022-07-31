/**
 * @brief Given an array of sorted numbers and a target sum, find a pair in the
 * array whose sum is equal to the given target.
 */
#include <iostream>
#include <vector>

std::pair<int, int> pairWithTargetSum(int target,
                                      const std::vector<int> &input) {
  // here, start and end are two vars referring to the start and end indices
  // respectively
  int start = 0, end = input.size() - 1;
  int sum = 0;
  while (start < end) {
    sum = input[start] + input[end];
    if (sum < target) {
      ++start;
    } else if (sum > target) {
      --end;
    } else {
      return std::make_pair(start, end);
    }
  }
  // -1, -1 is the pair of invalid indices to indicate that the pair could not
  // be found
  return std::make_pair(-1, -1);
}

int main() {
  {
    auto result1 = pairWithTargetSum(6, {1, 2, 3, 4, 5});
    std::cout << "Indices for pairWithTargetSum(6, {1, 2, 3, 4, 5}) => ("
              << result1.first << "," << result1.second << ")\n";
  }
  {
    auto result1 = pairWithTargetSum(8, {1, 2, 3, 4, 5});
    std::cout << "Indices for pairWithTargetSum(8, {1, 2, 3, 4, 5}) => ("
              << result1.first << "," << result1.second << ")\n";
  }
  {
    auto result1 = pairWithTargetSum(3, {1, 2, 3, 4, 5});
    std::cout << "Indices for pairWithTargetSum(3, {1, 2, 3, 4, 5}) => ("
              << result1.first << "," << result1.second << ")\n";
  }
  {
    auto result1 = pairWithTargetSum(10, {1, 2, 3, 4, 5});
    std::cout << "Indices for pairWithTargetSum(10, {1, 2, 3, 4, 5}) => ("
              << result1.first << "," << result1.second << ")\n";
  }
}