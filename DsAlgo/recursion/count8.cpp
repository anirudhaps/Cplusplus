#include <iostream>

int count8(int num) {
    if(num == 0)
        return 0;
    int ones_dig = num % 10;
    int tens_dig = (num % 100) / 10;

    if(ones_dig == 8) {
        if(tens_dig == 8)
            return 2 + count8(num / 10);
        return 1 + count8(num / 10);
    }
    return count8(num / 10);
}

int main() {
    using namespace std;
    int n;
    cout << "Enter number: ";
    cin >> n;
    cout << "Count of 8s: " << count8(n) << endl;
    return 0;
}