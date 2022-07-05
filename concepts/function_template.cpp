#include <iostream>

// template with single type parameter
template<typename T>
T larger(T a, T b) {
    return a > b ? a : b;
}

// template specialization
template<>
int* larger<int*>(int* a, int* b) {
    if (a != nullptr && b != nullptr) {
        return *a > *b ? a : b;
    }
    return nullptr;
}

// template with multiple type parameters
template<typename T1, typename T2>
decltype(auto) larger(T1 a, T2 b) {
    return a > b ? a : b;
}

int main() {
    // auto deduced by compiler that T is int while instantiating the template
    std::cout << "larger of 5, 9: " << larger(5, 9) << "\n";
    // explicitly mentioning the type as double, thus compiler will instantiate
    // template using double as type
    std::cout << "larger of 2.8, 1.7: " << larger<double>(2.8, 1.7) << "\n";
    // using string
    std::cout << "larger of ajay, rishi: " << larger<std::string>("ajay", "rishi") << "\n";
    // using two different types of values, we have to explicitly specify the
    // type to be set on T while instantiating otherwise compiler won't be able
    // to deduce the type of its own given we have arguments of two different types.
    // Due to <double>, the arg 4 will be converted to double by compiler.
    std::cout << "larger of 2.8, 4: " << larger<double>(2.8, 4) << "\n";
    // multiple types
    std::cout << "larger of 10, 9.1: " << larger<int, double>(10, 9.1) << "\n";
    return 0;
}