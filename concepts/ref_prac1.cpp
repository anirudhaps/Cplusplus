#include <iostream>

void Add(int, int, int &);
void Swap(int &, int &);
void Factorial(int, int &);

int main() {
    int res = 0;
    int a, b;
    int factorial;
    using namespace std;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    cout << "a = " << a << " b = " << b << endl;
    Add(a, b, res);
    cout << "Sum of these two numbers: " << res << endl;
    Swap(a, b);
    cout << "After swapping:" << endl;
    cout << "a = " << a << " b = " << b << endl;
    Factorial(a, factorial);
    cout << "Factorial of a: " << factorial << endl;
    return 0;
}

void Add(int a, int b, int &result) {
    result = a + b;
}

void Swap(int &a, int &b) {
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

void Factorial(int x, int &res) {
    int fact = 1;
    for(int i = 1; i <= x; ++i) {
        fact *= i;
    }
    res = fact;
}