#include <iostream>

class Vector {
private:
    double *elem;
    int sz;
public:
    //The following is a constructor and list starting from : is a member
    //initializer list.
    Vector(int s) :elem{new double[s]}, sz{s} {
    
    }
    int size() {
        return sz;
    }
    //The following is a subscript function to access the elements
    double& operator[](int i) {
        return elem[i];
    }
};

double read_and_sum(int size) {
    Vector v(size);

    for (int i = 0; i < v.size(); ++i) {
        std::cin >> v[i];
    }

    double sum = 0;
    for (int i = 0; i < v.size(); ++i) {
        sum += v[i];
    }
    return sum;
}

int main() {
    double s = read_and_sum(5);
    std::cout << "Sum of 5 nums: " << s << std::endl;
    return 0;
}
