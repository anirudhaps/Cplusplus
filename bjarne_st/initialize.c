#include <iostream>

// k{3.9} kind of initialization is defined by c++11 standard.
// So, to compile this program, we have to add -std=c++11 gcc flag for
// compilation: g++ initialize.c -o einit -std=c++11
int main()
{
    //If we don't return anything, a success exit status is returned to the
    //system from main.
    double d = 2.3;
    double kd = {2.4};
    double rd{3.4};

    int i = {7};
    int r{9};
    int j = 2.8;
    // This will truncate 2.8 to 2 and assigns it to j.

    //int k = {3.9};
    //int k{3.9};
    // This is an error. If we use {} initialization notation, then c++
    // compiler will complain if narrowing of data takes place.
    // The following error is observed.
    // error: narrowing conversion of ‘3.8999999999999999e+0’ from ‘double’ to ‘int’ inside { } [-Wnarrowing]

    //std::cout << "k= " << k << std::endl;
    std::cout << "i= " << i << " r= " << r << std::endl;
    std::cout << "j= " << j << std::endl;
    std::cout << "d= " << d << "  kd= " << kd << " rd= " << rd << std::endl;
}
