#include <iostream>

/*
Constants in C++:
=================
1. const is a keyword and a qualifier that makes a variable constant.
const <type> <variable> {initializer}
Eg. const int x{25};

2. A constant always needs an initializer.

3. A constant's value cannot be modified. If an attemt is made to modify it,
compile time error will be thrown.

4. Constants are commonly used with references.

5. Constants replace C macros (that are used to represent constant values in C).
Constants have some advantages over C macros. C macros are type-unsafe and they
do not have scopes, while this is not the case with constants in C++. 
*/

int main() {
    float radius;
    float area;
    using namespace std;

    cout << "Enter the radius: ";
    cin >> radius;
    const float PI{3.14};
    //const float PI;  //error
    area = PI * radius * radius;
    //PI = 4.45; //error

    cout << "Area of circle: " << area << endl;
    return 0;
}