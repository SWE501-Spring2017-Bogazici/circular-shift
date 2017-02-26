//============================================================================
// Name        : CircularShiftOfAnArray.cpp
// Author      : Busra Ondul
// Version     :
// Copyright   : 26.02.2017
// Description :  Circular Shift Of An Array
//============================================================================

#include <iostream>

using namespace std;

// shift the elements by shift count
void ArrayCircularShift(int* A, int Length, int Shift) {
	int *x;

	if (Shift > 0) //rotates left
			{
		for (int i = 0; i < Shift; i++) {
			x = A;
			for (int j = 0; j < Length - 1; j++) {
				swap(*x, *(x + 1));
				x++;
			}
		}
	} else { //rotates right
		Shift = -Shift;
		for (int i = 0; i < Shift; i++) {
			x = A + Length - 1;
			for (int j = 0; j < Length - 1; j++) {
				swap(*x, *(x - 1));
				x--;
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
	int *A, Length, shift;

	cout << "enter length of the array: " << endl;
	cin >> Length;

	A = new int[Length];

	for (int i = 0; i < Length; i++) {
		cout << "enter elements in the array: " << endl;
		cin >> A[i];
	}

	//original array
	cout << "original array before rotation is: " << endl;
	cout << "A= " << flush;
	for (int i = 0; i < Length; i++)
		cout << A[i] << ", " << flush;

	cout << endl
			<< "enter a positive number to shift left or enter a negative number to shift right"
			<< endl;
	cin >> shift;

	ArrayCircularShift(A, Length, shift);

	for (int i = 0; i < Length; i++) {
		cout << A[i] << " " << flush;
	}

	return (0);
}
