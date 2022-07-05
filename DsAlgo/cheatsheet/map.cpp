#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<char, char> my_map;
    if (my_map['j'] == '\0')
        std::cout << "yes" << std::endl;
    return 0;
}