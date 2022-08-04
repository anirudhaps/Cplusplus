// find the length of the smallest contiguous subarray whose sum is greater than
// or equal to S. Return 0 if no such subarray exists.

#include <iostream>
#include <vector>

int findMinSubArray(int s, const std::vector<int> &input) {
  int sum;
  for (int window_size = 1; window_size <= input.size(); ++window_size) {
    sum = 0;
    for (int start_window = 0, end_window = 0; end_window < input.size();
         ++end_window) {
      sum += input[end_window];
      if (end_window >= window_size - 1) {
        if (sum >= s) {
          return window_size;
        }
        sum -= input[start_window];
        ++start_window;
      }
    }
  }
  return 0;
}

int main() {
  std::cout << "1, 2, 4, 5: s=0: min sub-array size: "
            << findMinSubArray(0, {1, 2, 4, 5}) << "\n";
  std::cout << "1, 2, 4, 5: s=3: min sub-array size: "
            << findMinSubArray(3, {1, 2, 4, 5}) << "\n";
  std::cout << "1, 2, 4, 5: s=4: min sub-array size: "
            << findMinSubArray(4, {1, 2, 4, 5}) << "\n";
  std::cout << "1, 2, 4, 5: s=8: min sub-array size: "
            << findMinSubArray(8, {1, 2, 4, 5}) << "\n";
  std::cout << "1, 2, 4, 5: s=13: min sub-array size: "
            << findMinSubArray(13, {1, 2, 4, 5}) << "\n";
  return 0;
}