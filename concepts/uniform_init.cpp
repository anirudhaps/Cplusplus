#include <iostream>

int main() {
    int i = 1;
    int k(2);
    int j{3};
    //This way of initialization is called Uniform Initialization.
    int r{};
    /* When we don't fill the parentheses, the variable will be 
       initialized to its default value */
    float f{};
    bool b{};
    std::cout << "i = " << i << std::endl;
    std::cout << "j = " << j << std::endl;
    std::cout << "k = " << k << std::endl;
    std::cout << "r = " << r << std::endl;
    std::cout << "f = " << f << std::endl;
    std::cout << "b = " << b << std::endl;
    /*
    Another benefit of uniform initialization is that if we try to 
    initialize a variable of one type using value / variable of another
    type, the compiler will give warning about narowwing conversion.
    */
    int l{1};
    float fn{l};
    float nf{2.3};
    int t{nf};
    std::cout << fn << std::endl;
    std::cout << t << std::endl;
    return 0;
}