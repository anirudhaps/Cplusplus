#include <iostream>

/*
Notes about default arguments:
==============================
1. Default argument values can be assigned to some or all of the arguments in
the function.

2. These have to be assigned from right hand side to left hand side in the
list of function arguments.

3. It becomes optional to pass values to these arguments. If no explicit value
is passed for these arguments then compiler automatically assigns default value.
If explicit value(s) is passed, then it gets preference over default value(s). 
*/

void createWindow(const char *name, int x = 10, int y = 20, int width = 200, int height = 150) {
    using namespace std;
    cout << "name: " << name << endl;
    cout << "x: " << x << " y: " << y << endl;
    cout << "Width: " << width << " Heigth: " << height << endl;
}

int main() {
    createWindow("Notepad", 30, 90, 150);
    return 0;
}