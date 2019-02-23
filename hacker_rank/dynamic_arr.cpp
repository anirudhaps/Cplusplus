#include <iostream>
#include <stdlib.h>

struct dynamic_seq {
    int *arr;
    int size;
    int occupied_id;
};

void init_array(struct dynamic_seq darr[], int n);
void run_query(struct dynamic_seq darr[], int n, int qtype, int x, int y, int &lastAnswer);

int main() {
    using namespace std;
    int n, q, qtype, x, y;
    int lastAnswer = 0;

    cin >> n >> q;
    if((n < 1 || n > 100000) || (q < 1 || q > 100000))
        exit(1);

    struct dynamic_seq darr[n];
    init_array(darr, n);

    for(int i = 0; i < q; ++i) {
        cin >> qtype >> x >> y;
        run_query(darr, n, qtype, x, y, lastAnswer);
    }
    return 0;
}

void init_array(struct dynamic_seq darr[], int n) {
    if(darr == nullptr)
        return;
    for(int i = 0; i < n; ++i) {
        darr[i].arr = nullptr;
        darr[i].size = 0;
        darr[i].occupied_id = -1;
    }
}

void run_query(struct dynamic_seq darr[], int n, int qtype, int x, int y, int &lastAnswer) {
    int index = 0;

    index = (x ^ lastAnswer) % n;

    if(qtype == 1) {
        if(darr[index].arr == nullptr) {
            //sequence is not allocated for this index.
            darr[index].arr = new int[10];
            darr[index].size = 10;
            darr[index].occupied_id = -1;
        } else {
            //sequence is already allocated
            if(darr[index].occupied_id + 1 == darr[index].size) {
                //array is full, reallocate!
                int *narr = new int[darr[index].size * 2];
                for(int i = 0; i < darr[index].size; ++i) {
                    narr[i] = darr[index].arr[i];
                }
                delete darr[index].arr;
                darr[index].arr = narr;
            } else {
                //array is not full, append y
                darr[index].arr[darr[index].occupied_id + 1] = y;
            }
        }
    } else if(qtype == 2) {
        //darr[index].occupied_id + 1 is the actual size of the sequence having data stored in it.
        //Rest sequence is empty.
        lastAnswer = y % (darr[index].occupied_id + 1);
        std::cout << lastAnswer << std::endl;
    }
}