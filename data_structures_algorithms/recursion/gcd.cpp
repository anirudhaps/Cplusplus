#include <iostream>

int gcd(int num1, int num2) {
  if (num1 == num2) {
    return num1;
  }
  if (num1 < num2) {
    return gcd(num1, num2 - num1);
  }
  return gcd(num1 - num2, num2);
}

int main() {
  std::cout << "GCD of 36, 54: " << gcd(36, 54) << "\n";
  return 0;
}