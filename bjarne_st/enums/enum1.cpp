#include <iostream>

enum class Color {red, green, yellow};
enum class Traffic_light {green, blue, red};

//Some key points:
//Color is an enumeration, so is Traffic_light.
//red, green, yellow, blue are enumerators.

//Color's red is not equal to Traffic_light's red.
//Color's red is written as: Color::red and Traffic_light's red is
//written as Traffic_light::red. Similarly are other enumerators:
//Color::green, Traffic_light::green etc.

//enum class says that the enumeration is strictly typed.
//And, the enumerators are scoped.

int main() {
    Color c = Color::red;
    Traffic_light tl = Traffic_light::green;
    Traffic_light next = ++tl; //blue
    //We cannot print enums the following way.
    //std::cout << "Color's red: " << c << std::endl;
    //std::cout << "Traffic_light's green: " << tl << std::endl;
    return 0;
}

Traffic_light& operator++(Traffic_light& t) {
    switch (t) {
    case Traffic_light::green: return Traffic_light::blue;
    case Traffic_light::blue: return Traffic_light::red;
    case Traffic_light::red: return Traffic_light::green;
    }
}
