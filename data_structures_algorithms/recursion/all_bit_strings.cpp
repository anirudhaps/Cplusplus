#include <iostream>
#include <vector>

// find all the bit strings of size n
std::vector<std::string> bitStrings(int n) {
  if (n == 0) {
    return {};
  }
  if (n == 1) {
    return {"0", "1"};
  }
  auto prev = bitStrings(n - 1);
  std::vector<std::string> result;
  result.reserve(2 * prev.size());
  for (auto &x : prev) {
    result.push_back('0' + x);
    result.push_back('1' + x);
  }
  return result;
}

void display(const std::vector<std::string> arr) {
  std::cout << "{";
  for (auto x : arr) {
    std::cout << x << " ";
  }
  std::cout << "}\n";
}

int main() {
  std::cout << "All bit strings of size 3: ";
  display(bitStrings(3));
  return 0;
}