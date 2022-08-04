#include <iostream>
#include <string>

bool isPalindrome(const std::string& str, int front, int back) {
  if (str.length() == 0 || front >= back) {
    return true;
  }
  if (tolower(str[front]) != tolower(str[back])) {
    return false;
  }
  return isPalindrome(str, front + 1, back - 1);
}

int main() {
  std::cout << "Madam is palindrome?: " << std::boolalpha << isPalindrome("Madam", 0, 4) << "\n";
  std::cout << "Care is palindrome?: " << std::boolalpha << isPalindrome("Care", 0, 3) << "\n";
  std::cout << "Anna anna is palindrome?: " << std::boolalpha << isPalindrome("Anna anna", 0, 3) << "\n";
  std::cout << "no is palindrome?: " << std::boolalpha << isPalindrome("no", 0, 1) << "\n";
  std::cout << "dad is palindrome?: " << std::boolalpha << isPalindrome("dad", 0, 2) << "\n";
  return 0;
}