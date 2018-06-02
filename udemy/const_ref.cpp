#include <iostream>

void print(const int &ref) {
    using namespace std;
    //ref = 10; //error
    /*
    ref is read-only now. So, can't modify it.
    */
    cout << ref << endl;
}

int main() {
    using namespace std;
    /*
    We can create a reference only of an lvalue not of a literal.
    But cont reference can be created of a literal.
    */
    int x = 12;
    int &ref = x;
    //int &ref = 1; //error
    cout << x << " " << ref << endl;
    const int &cref = 1;
    cout << cref << endl;
    const int &c2ref = x;
    cout << c2ref << endl;
    //c2ref = 10; error
    /*
    c2ref is a reference of an lvalue type constant integer so can't modify it 
    */
    print(x);
    return 0;
}