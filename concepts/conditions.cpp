#include <iostream>

bool accept();

int main()
{
    bool res;

    std::cout << "Some stuff..." << std::endl;
    res = accept();
    while (res) {
        std::cout << "Running loop" << std::endl;
        res = accept();
    }
    return 0;
}

bool accept()
{
    char inp;

    std::cout << "Do you want to proceed? (y/n): ";
    std::cin >> inp;

    switch (inp) {
    case 'y':
        return true;
    case 'n':
        return false;
    default:
        std::cout << "I take it as no\n";
        return false;
    }
}
