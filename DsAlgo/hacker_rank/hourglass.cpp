#include <iostream>

int get_largest_hourglass_sum(int arr[][6], const int rsize, const int csize);

int main() {
    const int ARR_SIZE = 6;
    int arr[ARR_SIZE][ARR_SIZE];
    const int MIN_ELEM_VAL = -9;
    const int MAX_ELEM_VAL = 9;
    using namespace std;
    for(int i = 0; i < ARR_SIZE; i++) {
        for(int j = 0; j < ARR_SIZE; j++) {
            cin >> arr[i][j];
            if(arr[i][j] < MIN_ELEM_VAL || arr[i][j] > MAX_ELEM_VAL)
                exit(1);
        }
    }
    int hour_glass_max = get_largest_hourglass_sum(arr, ARR_SIZE, ARR_SIZE);
    cout << hour_glass_max << endl;

    return 0;
}

int get_largest_hourglass_sum(int arr[][6], const int rsize, const int csize) {
    int hgsum = 0;
    int max_hgsum = 0;
    for(int i = 0; i <= (rsize - 3); ++i) {
        for(int j = 0; j <= (csize - 3); ++j) {
            hgsum = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+1] +
                    arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
            if(hgsum > max_hgsum)
                max_hgsum = hgsum;
        }
    }
    return max_hgsum;
}