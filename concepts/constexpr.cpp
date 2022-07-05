#include <iostream>

int get() {
    return 10;
}

// A constexpr function is one whose return value is computable at compile time
constexpr int getOther() {
    return 20;
}

int main() {
    constexpr int value = 7;
    std::cout << "Constexpr val: " << value << "\n";
    // value = 10; // error: assignment of read-only variable 'value'
    // Note: constexpr variable is a const that is computed at the compile-time
    // by the compiler and whose value is used at runtime

    const int const_ret = get(); // OK
    // constexpr int constexpr_ret = get(); // error: call to non-‘constexpr’ function ‘int get()’
    // The above two statements show the difference between const and constexpr
    // get() is a function that returns 10 at runtime. Thus, its value can only be computed at
    // runtime and remains unknown at compile time
    // a const variable can be initialized at runtime but a constexpr variable requires the
    // initial value to be known at compile time. Thus, it requires the initializing expr to be
    // either a literal type or a constexpr variable or a constexpr function

    // constexpr int a = const_ret; // error because the value of const_ret is not known at
    // compile time

    // getOther() is a constexpr function. So, its value is known at the compile-time
    // Thus, it can be used to initialize both a const as well as a constexpr variables
    const int cother = getOther();
    constexpr int cexother = getOther();

    constexpr int a = 10;
    constexpr int b = a + 2;
    int x = 5;
    // constexpr int y = x + 1; // error: x is not a constant expression

    const int z = 8;
    constexpr int d = z + 2;
    // Note: a const or a constexpr var can be used to initialize another constexpr var.
    // A literal, constexpr or an expression whose value is known only at the runtime
    // can be used to initialize a const var. Thus, const var can be initialized with anything
    return 0;
}