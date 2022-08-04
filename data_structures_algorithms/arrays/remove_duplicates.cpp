#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>


// use unordered_map to remove duplicates
int removeDuplicates1(std::vector<int> &nums) {
  if (nums.size() == 1) {
    // no duplicates
    return 1;
  }
  std::unordered_map<int, bool> has_num;
  for (int i = 0, empty_index = 0; i < nums.size() && empty_index < nums.size();
       ++i) {
    if (!has_num[nums[i]]) {
      has_num[nums[i]] = true;
      nums[empty_index] = nums[i];
      ++empty_index;
    }
  }
  return has_num.size();
}

// use sets
int removeDuplicates2(std::vector<int> &nums) {
  if (nums.size() == 1) {
    // no duplicates
    return 1;
  }
  std::set<int> uniques;
  for (const int& num : nums) {
    uniques.insert(num);
  }
  int index = 0;
  for (const int& num : uniques) {
    if (index < nums.size()) {
      nums[index] = num;
      ++index;
    }
  }
  return uniques.size();
} 

// remove inplace without using any extra space
// @return: number of non duplicate elements
int removeDuplicates3(std::vector<int> &nums) {
  if (nums.size() == 1) {
    // no duplicates
    return 1;
  }
  int empty_slot = 1;
  int current;
  int index = 0;
  while (index < nums.size()) {
    current = nums[index];
    ++index;
    while (index < nums.size() && nums[index] == current) {
      ++index;
    }
    if (index >= nums.size()) {
      break;
    }
    nums[empty_slot] = nums[index];
    ++empty_slot;
  }
  return empty_slot;
}

void display(const std::vector<int>& arr, int count) {
  if (count > arr.size()) {
    return;
  }

  for (int i = 0; i < count; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "\n";
}

int main() {
  std::vector<int> input = {0};
  int res_size = 0;
  std::cout << "\nBefore:\n";
  display(input, input.size());
  res_size = removeDuplicates3(input);
  std::cout << "After:\n";
  display(input, res_size);

  input = {0, 1};
  std::cout << "\nBefore:\n";
  display(input, input.size());
  res_size = removeDuplicates3(input);
  std::cout << "After:\n";
  display(input, res_size);

  input = {0, 0, 1};
  std::cout << "\nBefore:\n";
  display(input, input.size());
  res_size = removeDuplicates3(input);
  std::cout << "After:\n";
  display(input, res_size);

  input = {1, 2, 2, 3, 3, 3, 4, 5, 5, 6};
  std::cout << "\nBefore:\n";
  display(input, input.size());
  res_size = removeDuplicates3(input);
  std::cout << "After:\n";
  display(input, res_size);

  input = {1, 1, 1};
  std::cout << "\nBefore:\n";
  display(input, input.size());
  res_size = removeDuplicates3(input);
  std::cout << "After:\n";
  display(input, res_size);
  return 0;
}