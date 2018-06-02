//Function overloading example
#include <iostream>

/*
Some points about function overloading:
=======================================
1. Defining two or more functions with same name but having different types
of arguments or different number of arguments is known as function overloading.
These functions are called overloaded functions.

2. In overloaded functions, return type is ignored. That is, while determining
whether the functions are overloaded or not, return type is not considered.
Only name of functions and function arguments are considered.

3. When a caller calls an overloaded function, the compiler determines which 
function to be called by seeing the types/number of arguments. Thus, it is a
static polymorphism.

4. Basicaly, overloaded functions provide different implementations of same
behaviour using same name.

5. The main facility overloading of functions give is convenience to the caller.
The caller does not have to remember different names for same behaviour.
*/

/*
Name Mangling
=============
1. The compiler uses a concept known as name mangling to generate unique name
for each function. This allows linker to link to the correct overloaded
function.

2. Name mangling function depends on the type and number of function arguments,
although it varies from compiler to compiler.

3. Since the name mangling alogithm is unknown, the functions written in C++
are not callable from C or any other language. (unless we use some qualifier).

4. If we apply extern "C" qualifier to one of the overloaded function, then
name mangling will be disabled for that function and that function can be used
from C or other languages.

5. extern "C" qualifier is applied only on one of the overloaded function and 
not to all of them. This qualifier can be applied only to global members.
*/

extern "C" void Print(int x) {
    using namespace std;
    cout << x << endl;
}

void Print(float x) {
    using namespace std;
    cout << x << endl;
}

int sum(int x, int y) {
    return x + y;
}

float sum(float x, float y) {
    return x + y;
}

/*
By using only const qualifier with pointer or reference, we can define
overloaded functions as shown below.
*/
void print_ptr(int *p) {
    using namespace std;
    cout << *p << endl;
}

void print_ptr(const int *p) {
    using namespace std;
    cout << *p << endl;
}

int main() {
    int resulti = sum(2, 3);
    float resf = sum(2.3f, 4.5f);
    int *xp = &resulti;
    const int *cxp = &resulti;
    Print(resulti);
    Print(resf);
    print_ptr(xp);
    print_ptr(cxp);
    return 0;
}
