#include <iostream>

/**
 * Here, size is the non-type template parameter/argument. It is an expression
 * that is computed at compile-time within the template argument list. It must
 * be a constant expression such as integrals, references, addresses, nullptr,
 * enums etc.
 * Non-type template arguments are more frequently used in classes and can be
 * seen as used in the std::begin and std::end functions (used to get iterators
 * to sequential containers in STL).
 */
template <typename T, int size> T ArraySum(const T *pArr) {
  // inside this function template, size is a constant and we can't change it
  // ++size; // error: increment of read-only location 'size'
  T sum{};
  for (int i = 0; i < size; ++i) {
    sum += pArr[i];
  }
  return sum;
}

int main() {
  int arr[] = {1, 2, 3, 4};
  // We have to specify a constant as size here (within <> brackets). Trying to
  // specify a variable as non-type arg will be a compile time error.
  // int s = 4;
  // int sum = ArraySum<int, s>(arr);
  // error: the value of 's' is not usable in a constant expression
  int sum = ArraySum<int, 4>(arr);
  std::cout << "Sum of nums: " << sum << std::endl;
  return 0;
}