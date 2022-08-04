#include <iostream>
#include <stdlib.h>

void read_array(int arr[], const int size, const int max_elem_size);
void print_reverse(int arr[], const int size);

int main() {
    const int MAX_ARR_SIZE = 1000;
    const int MAX_ELEM_SIZE = 10000;
    int arr[MAX_ARR_SIZE];
    int inp_size = 0;
    std::cin >> inp_size;
    if (inp_size > MAX_ARR_SIZE)
        exit(1);
    read_array(arr, inp_size, MAX_ELEM_SIZE);
    print_reverse(arr, inp_size);
    return 0;
}

void read_array(int arr[], const int size, const int max_elem_size) {
    for(int i = 0; i < size; ++i) {
        std::cin >> arr[i];
        if (arr[i] > max_elem_size)
            exit(1);
    }
}

void print_reverse(int arr[], const int size) {
    for(int i = size - 1; i >= 0; --i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}