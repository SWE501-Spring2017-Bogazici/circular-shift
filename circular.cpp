#include <iostream>
#include <stdlib.h>

using namespace std;

void shift(int *, int, int); // Main shift operation
void shiftRight(int *, int, int); // Sub shift functions
void shiftLeft(int *, int, int);

void printArr(int *, int); // Print array

int main() {
    int shiftLength = 2;

    int arr[6] = {1, 2, 3, 4, 5, 6};
    int length = sizeof(arr) / sizeof(*arr);

    printArr(arr, length); // Print original array
    shift(arr, length, shiftLength);
    printArr(arr, length); // Print shifted array

    return 0;
}

void shift(int *arr, int arrLength, int shiftLength) {

    // If shift length is zero, do nothing
    if (shiftLength == 0) {
        return;
    }

    bool left = shiftLength > 0;

    shiftLength = abs(shiftLength);

    left ? shiftLeft(arr, arrLength, shiftLength) : shiftRight(arr, arrLength, shiftLength);
}

void shiftRight(int *arr, int arrLength, int shiftLength) {

    // Array to store pushed out elements from the shift operation
    int shiftStore[shiftLength];

    // Shift right -> Go right to left
    for (int i = arrLength - 1; i >= 0; i--) {
        if (i + 1 + shiftLength > arrLength) {
            // Store pushed out elements
            shiftStore[arrLength - i - 1] = *(arr + i);
        } else {
            *(arr + i + shiftLength) = *(arr + i);
        }
    }

    // Put pushed out elements in their places
    for (int j = 0; j < shiftLength; ++j) {
        *(arr - j + shiftLength - 1) = *(shiftStore + j);
    }
}

void shiftLeft(int *arr, int arrLength, int shiftLength) {
    // Array to store pushed out elements from the shift operation
    int shiftStore[shiftLength];

    // Shift left -> Go left to right
    for (int i = 0; i < arrLength; i++) {
        if (i - shiftLength < 0) {
            // Store pushed out elements
            shiftStore[i] = *(arr + i);
        } else {
            *(arr + i - shiftLength) = *(arr + i);
        }
    }

    // Put pushed out elements in their places
    for (int j = 0; j < shiftLength; ++j) {
        *(arr + arrLength + j - shiftLength) = *(shiftStore + j);
    }
}


void printArr(int *arr, int arrLength) {
    for (int i = 0; i < arrLength; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}
