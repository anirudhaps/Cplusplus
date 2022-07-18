#include <iostream>

void Print(int no, const char *str) {
    using namespace std;
    for(int i = 0; i < no; ++i) {
        cout << str;
    }
    cout << endl;
}

int main() {
    Print(5, "@");
    /*
    Function pointer holds the address of the function. It is used to invoke a
    function even when the function name is not known.
    */

    /*
    Return type and argument types of the function pointer must be same as
    that of the function to be pointed on.
    */
    //void (*pfn)(int, const char *) = &Print;
    //or
    void (*pfn)(int, const char *) = Print;
    /*
    Syntax:
    <ret_type> (*fnptr)(args) = &function;
    or
    <ret_type> (*fnptr)(args) = function;
    */
    (*pfn)(5, "#");
    //or
    pfn(5, "&");
    return 0;
}