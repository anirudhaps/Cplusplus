#include <iostream>

void print(int num) {
    if (num <= 0) {
        return;
    }
    print(num-1);
    std::cout << num << "\n";
}

void printReverse(int num) {
    if (num <= 0) {
        return;
    }
    std::cout << num << "\n";
    printReverse(num-1);
}

int main() {
    int num;
    std::cout << "Count of nums: ";
    std::cin >> num;
    std::cout << "Forward:\n";
    print(num);
    std::cout << "Reverse:\n";
    printReverse(num);
    return 0;
}