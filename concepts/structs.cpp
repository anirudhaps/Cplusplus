#include <iostream>

struct Vector {
    int sz;
    double *elem;
};

void vector_init(Vector&, int);
double vector_read_sum(int);

int main()
{
    double s = vector_read_sum(5);
    std::cout << "Sum of these numbers: " << s << std::endl;
    return 0;
}

void vector_init(Vector& v, int size)
{
    v.sz = size;
    v.elem = new double[size];
}

double vector_read_sum(int size)
{
    Vector v;
    vector_init(v, size);

    for (int i = 0; i < size; ++i) {
        std::cin >> v.elem[i];
    }

    double sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += v.elem[i];
    }
    return sum;
}
