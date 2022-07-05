#include <iostream>

// Note: l-value and r-value references concepts are available
// starting from C++11

// function that returns by value, actually return an r-value
int add(int x, int y) {
    return x + y;
}

// function that returns by reference, returns an l-value.
// So, we can assign some value to such function call
int gval = 0;
int& transform(int x) {
    x *= 5;
    gval = x;
    return gval;
}

// functions can be overloaded on the basis of l-value / r-value references
void print(int& x) {
    std::cout << "print(int&)" << std::endl;
}

void print(const int& x) {
    std::cout << "print(const int&)" << std::endl;
}

void print(int&& x) {
    std::cout << "print(int&&)" << std::endl;
}

int main() {
    // x, y, z are lvalues. 
    // 10, 8, 5 are r-values.
    int x = 10;
    int y = 8;
    int z = 5;

    // r value reference can only be bound to an r-value.
    int&& sval = 30;
    std::cout << "sval: " << sval << std::endl;

    // int&& zref = z;
    // error: cannot bind rvalue ref to lvalue.

    // (x+y)*z returns an r-value
    int&& exp = (x + y) * z;
    // rvalue or an r-value reference can be assigned to an l-value
    int res = exp;
    std::cout << "(x + y) * z: " << res << std::endl;
    
    // ++x returns an l-value
    // any expression or function that returns l-value, we can assign
    // a temporary / r-value to it. 
    ++x = 20;

    //int sum = add(2, 9);
    int&& sum = add(2, 9);
    std::cout << "Sum(2, 9): " << sum << std::endl;

    int& five_times = transform(20);
    // transform(10) = 0;
    std::cout << "five_times of 20: " << five_times << std::endl;

    // assigning an r-value or an r-value reference to a const l-value
    // reference is allowed
    const int& cst_ref = 25;
    std::cout << "cst_ref: " << cst_ref << std::endl;
    const int& some_ref = sval;
    std::cout << "constant ref assigned from r-value ref: " << some_ref << std::endl;

    x = 12;
    // this will invoke print(int&) as it is called with an l-value 
    print(x);
    // this will invoke print(const int&) as it is called with an r-value
    // If there is another function print(int&&) that accepts an r-value
    // reference, then that will be invoked instead of print(const int&)
    // Because, an r-value binds to an r-value reference and hence a function
    // accepting r-value ref will take precedence.
    print(40);

    // The above overloading of functions on the basis of l-value / r-value
    // references is a way to determine if the function is called with a
    // temporary / r-value argument.

    return 0;
}