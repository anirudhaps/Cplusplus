#include <iostream>

/*
auto keyword in c++11:
======================
1. Before c++11, auto keyword was used to indicate the storage class
of the variable. But c++11 changed its meaning.

2. auto keyword is used to allow the compiler to automatically infer the type
of the variable from the initializer. Thus, the initializer is important with
a variable declared with auto keyword.

It will be a compiletime error if we omit the initializer with auto declaration.

3. This is how we declare it:
auto <identifier> = <initializer>

Here, initializer could be an expression that returns some value. i.e. literal,
mathematical expression or a function call. Compiler will infer the type of the
variable using the initializer.

4. If the initializer expression has values / variables of different type, the
type of the declared variable will be the largest type in the expression.
For e.g.: auto s = 2 + 2.34f;
type of s will be float.
*/

int get_sum(int a, int b) {
    return a + b;
}

int main() {
    auto i = 10;
    auto j = 12;
    auto sum = i + 4.3f;
    auto s = get_sum(2, 9);
    const int x = 10;
    auto var = x;
    //Note: type of var will be int and not const int.
    const auto nvar = x;
    //Note: nvar will be of type const int with value 10.
    auto &ref = x;
    //Note: ref will be a const int reference of x.
    auto ptr = &x;
    //Note: ptr will be pointer to the const integer x.

    auto list = {1,2,3,4};
    /*
    Here list is an initializer list with integer values.
    Its type will be std::initializer_list<int>.
    list is initializer list only if we keep the comma separated
    values in {} on the RHS of the = sign.
    auto list{1,2,3,4} is compile time error.
    In this case {} must contain only one element.
    */
    //auto lst{1,2,3}; //error
    auto ls{1}; //OK
    using namespace std;

    cout << "i = " << i << endl;
    cout << "j = " << j << endl;
    cout << "sum: " << sum << endl;
    cout << "s: " << s << endl;
    return 0;
}