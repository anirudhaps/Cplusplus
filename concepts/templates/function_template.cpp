/**
 * Templates are used for generic programming that allows us to write classes
 * and functions without explicitly thinking about the data types.
 * Templates generalize software components that can operate on any kind of
 * data. Templates are used by compiler to generate the code at compile time.
 * So, there is no runtime cost involved.
 */
#include <iostream>

// Template with single type parameter
// Here, T is the template type parameter. It is the placeholder for actual
// type. It can accept any type.
template <typename T> T larger(T a, T b) { return a > b ? a : b; }

// Explicit template specialization: for specializing the template for a
// particular type. This is sometimes needed if the algo implemented in the
// template definition may not suit a particular data type or may not provide
// correct semantics for some data types or we want to implement a different /
// optimal algo for a specific type. For eg. in the above template, if T = int*,
// the instantiated function will actually compare addresses of int variables
// rather than their values. Thus, for this special use-case we need to define a
// specialized template definition.
template <> int *larger<int *>(int *a, int *b) {
  if (a != nullptr && b != nullptr) {
    return *a > *b ? a : b;
  }
  return nullptr;
}
// Explicitly specialized functions must be defined in a .cpp file and not in .h
// file because these are already instantiated and if defined in a header file,
// this will voilate the one definition rule (ODR).
// The primary template definition should occur before explicit specialization
// (if defined in the same .cpp file)

// Template with multiple type parameters
template <typename T1, typename T2> decltype(auto) larger(T1 a, T2 b) {
  return a > b ? a : b;
}

int main() {
  // The generation of a function from a template is known as template
  // instantiation. The compiler examines the arguments of the invoked function
  // and deduces the types of them. Thereafter, it instantiates the template.

  // To instantiate a template, the compiler should be able to see the full
  // definition of the template. That is why, the templates are defined in the
  // header file. They don't follow the convention of declaration and definition
  // in separate files. They have to defined in the header file.

  // The compiler will instantiate the larger function template (or any function
  // template) only if it is used/invoked at least once. And the compiler will
  // instantiate template (generates functions) for only those types with which
  // it is invoked.

  // auto deduced by compiler that T is int while instantiating the template
  std::cout << "larger of 5, 9: " << larger(5, 9) << "\n";
  // explicitly mentioning the type as double, thus compiler will instantiate
  // template using double as type
  std::cout << "larger of 2.8, 1.7: " << larger<double>(2.8, 1.7) << "\n";
  // using string
  std::cout << "larger of ajay, rishi: " << larger<std::string>("ajay", "rishi")
            << "\n";
  // using two different types of values, we have to explicitly specify the
  // type to be set on T while instantiating otherwise compiler won't be able
  // to deduce the type of its own given we have arguments of two different
  // types. Due to <double>, the arg 4 will be converted to double by compiler.
  std::cout << "larger of 2.8, 4: " << larger<double>(2.8, 4) << "\n";
  // multiple types
  std::cout << "larger of 10, 9.1: " << larger<int, double>(10, 9.1) << "\n";
  return 0;
}

/**
 * There are four cases when the compiler implicitly instantiates a template:
 * - a function template is invoked
 * - taking address of a function template
 * - using explicit instantiation
 * - creating explicit specialization
 */