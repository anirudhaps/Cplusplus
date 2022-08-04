#include <iostream>
#include <vector>

long getMaxSum(int k, const std::vector<int> &input) {
  long max = 0;
  long sum = 0;
  int start_window = 0;
  for (int end_window = 0; end_window < input.size(); ++end_window) {
    sum += input[end_window];
    if (end_window >= k - 1) {
      std::cout << sum << " ";
      if (end_window == k - 1) {
        max = sum;
      } else {
        if (sum > max) {
          max = sum;
        }
      }
      sum -= input[start_window];
      ++start_window;
    }
  }
  std::cout << "\n";
  return max;
}

int main() {
  auto max = getMaxSum(4, {1, 3, 2, 6, -1, 4, 1, 8, 2});
  std::cout << "Max sum: " << max << std::endl;
  return 0;
}