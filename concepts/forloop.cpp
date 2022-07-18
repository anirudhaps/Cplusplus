#include <iostream>

void print_arr1();
void print_arr2();
void print_arr3();
void print_arr4();

int main()
{
    print_arr1();
    print_arr2();
    print_arr3();
    std::cout << "Printing using pointers: " << std::endl;
    print_arr4();
}

void print_arr1()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < 6; i++) {
        std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
    }
}

void print_arr2()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    // Range-for statement: only available in c++11. So, compile with -std=c++11 flag
    // This will copy each element of arr in x one after the other.
    // so, we can read it as: for each element of arr, copy it to x and them print it.
    for (int x : arr) {
        std::cout << x << std::endl;
    }
}

void print_arr3()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    // In this case, the value of element of arr is not copied to x. Infact, it refered
    // by x. Because x is a reference variable of type int. "int&" declares it.
    for (int& x : arr) {
        std::cout << x << std::endl;
    }
}

void print_arr4()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    // When there is no object to point to, we give the pointer the value: nullptr.
    int *ptr = nullptr;
    int i = 0;

    for (ptr = &arr[0]; i < 6; ptr++, i++) {
        std::cout << *ptr << std::endl;
    }
}
