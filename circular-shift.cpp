//============================================================================
// Name        : circular-shift.cpp
// Author      : Can Candan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void circular_shift(int* A, int L, int S) {
	int shift=((S % L) + L) % L;

	int left[shift];
	int right[L-shift];

	// copy the left and right cuts to temporary locations
	memcpy(left, &A[L-shift], sizeof(int) * shift);
	memcpy(right, &A[0], sizeof(int) * (L-shift));

	// put it back
	memcpy(&A[0], &left[0], sizeof(int) * shift);
	memcpy(&A[shift], &right[0], sizeof(int) * (L-shift));

}

void printarray (int arg[], int length) {
  for (int n=0; n<length; ++n)
    cout << arg[n] << ' ';
}

int main() {

	int S[]={3,7,11,23,55,123,99,132};
	int length= sizeof(S)/sizeof(S[0]);

	cout << "Array:" << endl;
	printarray(S, length); cout << endl;

	cout << "Shift 5" << endl;
	circular_shift(S,length,5);
	printarray(S, length); cout << endl;

	cout << "Now shift -4"<< endl;
	circular_shift(S,length,-4);
	printarray(S, length); cout << endl;

	return 0;
}
