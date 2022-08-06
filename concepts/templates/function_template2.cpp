#include <iostream>

template <typename T> T Max(T a, T b) {
  std::cout << __func__ << " is invoked with type: " << typeid(T).name()
            << "\n";
  return a > b ? a : b;
}

// Explicit instantiation of Max function for char type. This will ask compiler
// to instantiate for char type.
template char Max(char a, char b);

int main() {
  // Max(2, 6.2);
  // The above is compile time error because we are trying to pass arguments of
  // two different types and this makes compiler unable to deduce the types of
  // the template type parameter. The received error from gcc:
  // error: no matching function for call to 'Max(int, double)'
  //  note:   template argument deduction/substitution failed:
  //  note:   deduced conflicting types for parameter 'T' ('int' and 'double')

  // There are two ways to avoid this error and tell compiler explicitly about
  // what type we want to be deduced:

  // 1: Explicitly type cast one of the argument to make both arguments of the
  // same type. This will help compiler to deduce the type as double and will
  // instantiate the template using it.
  Max(static_cast<double>(2), 6.2);

  // 2: This is called explicit type instantiation. This tells the compiler what
  // type to use for template type deduction.
  Max<double>(2, 6.2);

  Max(2.3f, 4.5f);
  Max(4.9, 3.5);

  // When we take address of a template function, it is instantiated by
  // compiler:
  int (*ptr)(int, int) = Max;
  ptr(2, 3);
  return 0;
}