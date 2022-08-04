// find the average of all subarrays of K contiguous elements in it.

#include <iostream>
#include <vector>

std::vector<double> average(int k, const std::vector<int>& input) {
  std::vector<double> result(input.size() - k + 1);
  double sum = 0;
  int start_window = 0;
  for (int end_window = 0; end_window < input.size(); ++end_window) {
    sum += input[end_window];
    if (end_window >= k - 1) {
      result[start_window] = sum / k;
      sum -= input[start_window];
      ++start_window;
    }
  }
  return result;
}

int main() {
  auto result = average(5, {1, 3, 2, 6, -1, 4, 1, 8, 2});
  std::cout << "Average of all subarrays of K contiguous elements:\n";
  for (const auto& avg : result) {
    std::cout << avg << " ";
  }
  std::cout << std::endl;
  return 0;
}