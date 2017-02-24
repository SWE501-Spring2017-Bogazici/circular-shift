#include <iostream>

using namespace std;

// shift the elements by shift count
void circular_shift(int* A, int L, int S) {
    int *p;

    if (S > 0) {
        for (int i = 0; i < S; i++) {
            p = A;
            for (int j = 0; j < L - 1; j++) {
                swap(*p, *(p+1));
                p++;
            }
        }
    } else {
        S = -S;
        for (int i = 0; i < S; i++) {
            p = A + L - 1;
            for (int j = 0; j < L - 1; j++) {
                swap(*p, *(p-1));
                p--;
            }
        }
    }
}

// swap array elements
void swap(int &a, int&b) {
    int temp = a;
    a = b;
    b = temp;
}

// print the array by shift count given by the user
int main() {
    int A[5] = {2, 3, 4, 5, 6};
    int shiftCount;
    int size = sizeof(A) / sizeof(int);

    cout << "Before shifting A--> ";
    for (int i = 0; i < size; i++) {
        cout << A[i];
    }
    cout << "\n\n";
    cout << "If shift count is positive shift left, if negative shift right."<< endl;
    cout << "Enter the shift count: " << endl;
    cin >> shiftCount;

    circular_shift(A, size, shiftCount);

    cout << "After shifting  A--> ";
    for (int i = 0; i < size; i++) {
        cout << A[i];
    }


    cout << endl;
    return 0;
}
