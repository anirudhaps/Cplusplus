// Given an integer rowIndex, return the rowIndexth (0-indexed) row of the
// Pascal's triangle.
#include <iostream>
#include <vector>

std::vector<long> getPascalTriangleRow(int rowIndex) {
  if (rowIndex == 0) {
    return {1};
  }
  if (rowIndex == 1) {
    return {1, 1};
  }
  long store = 0;
  long sum = 0;
  std::vector<long> result(rowIndex + 1, 0);
  result[0] = 1;
  result[1] = 1;
  for (int i = 2; i <= rowIndex; ++i) {
    sum = 0;
    store = 0;
    for (int j = 1; j < i; ++j) {
      sum = (store == 0) ? result[j] + result[j - 1] : result[j] + store;
      store = result[j];
      result[j] = sum;
    }
    result[i] = 1;
  }
  return result;
}

std::vector<long> getPascalTriangleRow2(int rowIndex) {
  std::vector<long> result(rowIndex + 1, 0);
  result[0] = 1;
  for (int i = 1; i <= rowIndex; ++i) {
    for (int j = i; j >= 1; --j) {
      result[j] += result[j - 1];
    }
  }
  return result;
}

void display(const std::vector<long> &arr) {
  for (const auto &num : arr) {
    std::cout << num << " ";
  }
  std::cout << std::endl;
}

int main() {
  display(getPascalTriangleRow2(0));
  display(getPascalTriangleRow2(1));
  display(getPascalTriangleRow2(2));
  display(getPascalTriangleRow2(3));
  display(getPascalTriangleRow2(4));
  display(getPascalTriangleRow2(5));
  display(getPascalTriangleRow2(6));
  display(getPascalTriangleRow2(7));
  display(getPascalTriangleRow2(8));
  display(getPascalTriangleRow2(32));
  return 0;
}