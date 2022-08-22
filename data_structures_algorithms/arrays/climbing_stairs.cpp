#include <iostream>

// number of ways to cliemb stairs with an assumption that one can start from
// 0th or 1st stair and can climb one or two stairs at a time
int waysToClimbStairs(int n) {
  if (n <= 1) {
    return 1;
  }
  int arr[n + 1];
  arr[0] = arr[1] = 1;
  for (int i = 2; i <= n; ++i) {
    arr[i] = arr[i - 1] + arr[i - 2];
  }
  return arr[n];
}

int main() {
  std::cout << "Ways to climb 1 steps: " << waysToClimbStairs(1) << "\n";
  std::cout << "Ways to climb 2 steps: " << waysToClimbStairs(2) << "\n";
  std::cout << "Ways to climb 3 steps: " << waysToClimbStairs(3) << "\n";
  std::cout << "Ways to climb 4 steps: " << waysToClimbStairs(4) << "\n";
  std::cout << "Ways to climb 5 steps: " << waysToClimbStairs(5) << "\n";
  std::cout << "Ways to climb 6 steps: " << waysToClimbStairs(6) << "\n";
  std::cout << "Ways to climb 7 steps: " << waysToClimbStairs(7) << "\n";
  std::cout << "Ways to climb 8 steps: " << waysToClimbStairs(8) << "\n";
  return 0;
}