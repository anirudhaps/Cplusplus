#include <iostream>

int main() {
    char name[256];
    using namespace std;

    cout << "Enter your name: ";
    //cin >> name;
    cin.getline(name, 50);

    cout << "name: " << name << endl;
}