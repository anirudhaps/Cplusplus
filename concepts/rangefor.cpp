#include <iostream>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    using namespace std;
    //There are two ways to print the array elements:
    //1. For loop.
    //2. Range-based for loop.

    for (int i = 0; i < 5 ; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    //for (const auto &x : arr) {
    /*
    If we keep above thing, x = 12 will be compile time error.
    Because, x will be reference to a const value. So, trying
    to modify it will be a compile time error.
    */
    for (auto &x : arr) {
        cout << x << " ";
        x = 12;
        /*
        Since x is a reference, modifying value of x will modify values
        in the array. All values will become 12.
        */
    }
    cout << endl;
    for (auto x : arr) {
        cout << x << " ";
    }
    cout << endl;

    for (auto x : {23, 34, 45, 56}) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}

/*
Some notes about for loop and range-based for loop:
===================================================
1. Range based for loops are less error proned compared to for loops.
This is because in range-based for loops, there is no variable for iteration,
no loop condition. So, there is less chance of getting anything wrong.

2. For loops give more finer control over the looping compared to Range-based 
for loops. With for loop, we can decide how we want to loop over the list.
But range-based for loops always loop-over the complete list one element after
the other.

3. Use range-based for loop when we just want to loop over the complete list
element by element. Use for loop when you want more finer control over looping.
*/