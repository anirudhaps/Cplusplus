/**
 * @brief Given an array of sorted numbers, remove all duplicate number
 * instances from it in-place, such that each element appears only once. The
 * relative order of the elements should be kept the same and you should not use
 * any extra space so that that the solution have a space complexity of O(1).
 * Move all the unique elements at the beginning of the array and after moving
 * return the length of the subarray that has no duplicate in it.
 */
#include <iostream>
#include <vector>

int removeDuplicates(std::vector<int> &arr) {
  if (arr.size() == 0 || arr.size() == 1) {
    return arr.size();
  }
  int start = 0;
  int iterator = 1;
  while (start < arr.size()) {
    while (iterator < arr.size() && arr[iterator] == arr[start]) {
      ++iterator;
    }
    if (iterator == arr.size()) {
      break;
    }
    arr[start + 1] = arr[iterator];
    ++start;
  }
  return start + 1;
}

int main() {
  {
    std::vector<int> input{2, 3, 3, 3, 6, 9, 9};
    std::cout << "{2, 3, 3, 3, 6, 9, 9} => " << removeDuplicates(input) << "\n";
  }
  {
    std::vector<int> input{2, 2, 2, 11};
    std::cout << "{2, 2, 2, 11} => " << removeDuplicates(input) << "\n";
  }
  {
    std::vector<int> input{2, 3, 4};
    std::cout << "{2, 3, 4} => " << removeDuplicates(input) << "\n";
  }
  {
    std::vector<int> input{3, 3, 3};
    std::cout << "{3, 3, 3} => " << removeDuplicates(input) << "\n";
  }
  return 0;
}