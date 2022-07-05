#include <iostream>
#include <vector>

int partition(std::vector<int>& arr, int left, int right) {
    int pivot = arr[right];
    int index1 = left - 1;
    int index2 = left;
    int temp;

    while (index2 < right) {
        if (arr[index2] <= pivot) {
            ++index1;
            // swap arr[index1], arr[index2]
            temp = arr[index1];
            arr[index1] = arr[index2];
            arr[index2] = temp;
        }
        ++index2;
    }

    // swap arr[index1 + 1]. arr[right]
    temp = arr[index1 + 1];
    arr[index1 + 1] = arr[right];
    arr[right] = temp;

    return index1 + 1;
}

void quicksort(std::vector<int>& arr, int left, int right) {
    int q = 0;
    if (left < right) {
        q = partition(arr, left, right);
        quicksort(arr, left, q-1);
        quicksort(arr, q+1, right);
    }
}

int main() {
    //std::vector<int> arr {2, 8, 7, 1, 3, 5, 6, 4};
    //std::vector<int> arr {5, 4, 3, 2, 1};
    std::vector<int> arr {4, 4, 4, 4};
    //std::vector<int> arr {13, 19, 9, 5, 12, 8, 7, 4, 21, 2, 6, 11};
    //int q = partition(arr, 0, arr.size()-1);
    quicksort(arr, 0, arr.size()-1);

    std::cout << "After sorting:\n";
    for(int i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}