#include <iostream>

void Print(const int *ptr) {
    using namespace std;
    if (ptr == nullptr)
        return;
    cout << *ptr << endl;
}

int main() {
    using namespace std;
    const int CHUNK_SIZE = 512;
    const int C1 = 314;
    //const int *ptr = nullptr;
    //int *ptr = nullptr; //error

    //ptr = &CHUNK_SIZE;
    int x = 12;
    Print(&x);
    //*ptr = 95; //error
    const int *const ptr = &CHUNK_SIZE;
    /*
    Above, ptr is a contant pointer. That is, once we store an address in it,
    we cannot modify it. Since we have stored address of CHUNK_SIZE to it, we 
    cannot modify it to point to C1. So, ptr = &C1 is an error as ptr is read-
    only.
    */
    cout << *ptr << endl;
    //ptr = &C1; //error
    cout << *ptr << endl;
    return 0;
}
