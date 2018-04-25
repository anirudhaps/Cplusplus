#include <iostream>

void func();

int main()
{
    func();
}

void func()
{
    double d = 2.2;
    int i = 7;
    d = d + i;
    std::cout << "d + i = d = " << d << std::endl;
    i = d * i;
    std::cout << "i = d * i = " << i << std::endl;
}
