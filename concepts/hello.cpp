#include <iostream>
/*
iostream is a header file that consists of clauses and objects used to 
perform I/O. In C++, header files do not have .h extension.
*/

int main() {
    using namespace std;
    /*
    To print something on screen, we need an object called cout. This we get
    from the header file iostream. But cout is not directly excessible because
    it is part of the namespace std.
    A namespace is used to wrap types so that they are not accessible from 
    outside. So, to access an object that is part of a namespace, we have to
    open that namespace. To do that, we use the clause "using namespace".
    */
    cout << "Hello " << "C++" << endl;
    /*
    << is called insertion operator.
    << one after another is called cascading of operators.
    endl is used to insert \n to the output. It also flushes the output buffer
    so that the output is immediately printed on screen.
    */
    return 0;
}