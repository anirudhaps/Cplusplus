#include <iostream>

template <typename T> T Add(T x, T y) { return x + y; }

template <typename T> T ArraySum(const T *pArr, size_t arrSize) {
  T sum = pArr[0];
  for (int i = 1; i < arrSize; ++i) {
    sum += pArr[i];
  }
  return sum;
}

template <typename T> T Max(const T *pArr, size_t arrSize) {
  T max = pArr[0];
  for (int i = 1; i < arrSize; ++i) {
    if (pArr[i] > max) {
      max = pArr[i];
    }
  }
  return max;
}

template <typename T> std::pair<T, T> MinMax(const T *pArr, size_t arrSize) {
  T max = pArr[0];
  T min = pArr[0];
  for (int i = 1; i < arrSize; ++i) {
    if (pArr[i] > max) {
      max = pArr[i];
    }
    if (pArr[i] < min) {
      min = pArr[i];
    }
  }
  return std::make_pair(min, max);
}

int main() {
  int sum = Add(2, 3);
  std::cout << "Sum of 2, 3: " << sum << "\n";
  float fsum = Add(4.3f, 5.9f);
  std::cout << "Sum of 4.3, 5.9: " << fsum << "\n";

  double arr[] = {1.2, 2.3, 3.4, 4.5};
  double asum = ArraySum(arr, 4);
  std::cout << "Sum of array: {1.2, 2.3, 3.4, 4.5}: " << asum << "\n";

  std::string sarr[] = {"jack", "jane", "bane", "jon"};
  std::string max = Max(sarr, 4);
  std::cout << "Max among {'jack', 'jane', 'bane', 'jon'}: " << max << "\n";

  char carr[] = {'g', 'y', '0', '9', 't'};
  auto min_max = MinMax(carr, 5);
  std::cout << "Min and max among {'g', 'y', '0', '9', 't'} respectively: "
            << min_max.first << ", " << min_max.second << "\n";
  return 0;
}