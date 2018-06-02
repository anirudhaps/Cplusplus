#include <iostream>
//#define square(x) x * x

/*
Notes about inline functions:
=============================
1. If we mark a function with keyword inline, then it becomes an inline
function.

2. Such functions are defined in a header file.

3. Marking inline is a request to the compiler to replace the call with
the function body. The compiler might ignore that request.

4. If we don't mark the function as inline, then the function will incur
calling overhead (return address has to be stored, a new stack frame has
to be allocated in program stack and control need to jump there to execute
the function). Inline function has no such overheads.

5. Inline request might be ignored by compiler if one of the following
condition is there:
    o. large functions
    o. functions having too many conditional statements
    o. recursive functions
    o. functions invoked through pointers etc.
But different compilers have different rules.

6. Excessive inlining may increase binary size. Thus, only small functions
must be made inline.

7. In C++, avoid using macros, use inline functions instead.

8. Macros have certain drawbacks which can be summarized as follows:
    o. Macros are error prone due to text substitution nature. (inline functions
    have function semantics, so they are safe to call. Compiler replaces the call
    with the body)
    o. Macros does not have an address (inline functions have address)
    o. Macros are difficult to use with multiple lines of code (inline functions
    are not)
    o. Macros cannot be used for member functions of a class (class member functions
    can be inline)
*/

inline int square(int x) {
    return x * x;
}

int main() {
    using namespace std;
    int sq = square(10);
    cout << "Square of 10 is " << sq << endl;
    return 0;
}