#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;
    int xor1 = a ^ b;
    int sum = xor1 | (~xor1 << 1); 
    std::cout << sum << std::endl;
    return 0;
}