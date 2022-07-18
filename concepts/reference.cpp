#include <iostream>

/*
Study of References:

1. A reference is an alternative name for a variable, also called an alias.

2. It is created using & operator during declaration.
For eg: int &ref = x;
Here, ref becomes the reference (alias) of x. x is called referent in this
case. x is also called the initializer of ref.

3. When we declare a reference, it always needs an initializer. If we declare
a reference without an initializer (the referent), it is an error.
(Important difference from pointer: in case of pointers, initializer is optional)

4. The referent must always be a variable (except in a few special cases).
(Important difference from pointer: in case of pointers, initializer need not be
a variable)

5. When we declare / define a reference like:
int &ref = x;
ref gets bound to the referent x. Now it cannot be made to refer to any other
referent.
(Important difference from pointer: a pointer can point to other variables as
well)

6. After this, if we assign some value to the reference, it will get assigned
to the referent as well. So, we can use references to modify the value of
referents.

7. No memory is allocated to a reference when we define a reference. After
defining, both the reference and the referent will have same memory address.
(Important difference from pointer: a pointer will be a separate variable so
it will have its own storage in memory. Thus, the address of x and the address
of pointer ptr (such that ptr = &x) will be different)

8. Important difference from pointer: A pointer can be nullptr but a reference
cannot be nullptr.
Also, dereference operator(*) is not required to get the value of a reference.
While in case of pointers, dereferenc operator is needed to fetch the value
stored at the location pointed to by the pointer.
*/

int main() {
    int x = 10;
    int &ref = x;
    //int &ref; // error
    ref = 20;
    std::cout << "x: " << x << " add of x: " << &x << std::endl;
    std::cout << "ref: " << ref << " add of ref: " << &ref << std::endl;
    return 0;
}