#include <iostream>
#include <string>

int totalVowels(const std::string &str, int index) {
  if (str.length() == 0 || index >= str.length()) {
    return 0;
  }
  int count = 0;
  switch (str[index]) {
  case 'a':
  case 'e':
  case 'i':
  case 'o':
  case 'u':
  case 'A':
  case 'E':
  case 'I':
  case 'O':
  case 'U':
    count = 1;
    break;
  default:
    count = 0;
  }
  return count + totalVowels(str, index + 1);
}

int main() {
  std::cout << "Total vowels in \"hello\": " << totalVowels("hello", 0) << "\n";
  std::cout << "Total vowels in \"aeiou\": " << totalVowels("aeiou", 0) << "\n";
  std::cout << "Total vowels in \"Anirudha Pratap Singh\": "
            << totalVowels("Anirudha Pratap Singh", 0) << "\n";
  return 0;
}