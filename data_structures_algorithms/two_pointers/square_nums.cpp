/**
 * @brief Given a sorted array, create a new array containing squares of all the
 * numbers of the input array in the sorted order.
 */
#include <iostream>
#include <vector>

std::vector<int> squares(const std::vector<int> &arr) {
  if (arr.size() == 0) {
    return {};
  }
  std::vector<int> result(arr.size());
  int forward{0};
  while (forward < arr.size() && arr[forward] < 0) {
    ++forward;
  }
  int backward = forward - 1;
  int rIndex = 0;
  while (backward >= 0 && forward < arr.size() && rIndex < result.size()) {
    int square1 = arr[backward] * arr[backward];
    int square2 = arr[forward] * arr[forward];
    if (square1 < square2) {
      result[rIndex] = square1;
      --backward;
    } else {
      result[rIndex] = square2;
      ++forward;
    }
    ++rIndex;
  }
  while (backward >= 0 && rIndex < result.size()) {
    result[rIndex] = arr[backward] * arr[backward];
    ++rIndex;
    --backward;
  }
  while (forward < arr.size() && rIndex < result.size()) {
    result[rIndex] = arr[forward] * arr[forward];
    ++rIndex;
    ++forward;
  }
  return result;
}

void display(const std::vector<int> &input) {
  std::cout << "{ ";
  for (const auto &num : input) {
    std::cout << num << " ";
  }
  std::cout << "}\n";
}

int main() {
  std::cout << "{-2, -1, 0, 2, 3} => ";
  display(squares({-2, -1, 0, 2, 3}));
  std::cout << "{-3, -1, 0, 1, 2} => ";
  display(squares({-3, -1, 0, 1, 2}));
  std::cout << "{-4, -3, -2, -1, 2} => ";
  display(squares({-4, -3, -2, -1, 2}));
  std::cout << "{-5, -4, -3, -2, -1} => ";
  display(squares({-5, -4, -3, -2, -1}));
  std::cout << "{0, 1, 2, 3} => ";
  display(squares({0, 1, 2, 3}));
  std::cout << "{} => ";
  display(squares({}));
  return 0;
}