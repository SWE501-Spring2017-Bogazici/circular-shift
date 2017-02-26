
#include <iostream>
#include <cstring>
using namespace std;

// funstion protoype
void circularShift(int *A, int l, int s);

int main() {

	int l; // length of the array
	int A[l]; // array
	int s; // number of shifts

	// obtain array length
	cout << "Enter length of the array: " << endl;
	cin >> l;

	// obtain the array elements
	cout << "Enter the elements of array: ";
	for (int i = 0; i < l; i++)
		cin >> A[i];

	// output the array elements before shift
	cout << "Array before the shift" << endl;
	cout << "A = ";
	for (int i = 0; i < l; i++)
		cout << A[i] << ' ';

	cout << endl;
	// number of shitfs
	cout << "\n" << "Enter the amount of number to be shifted: " << endl;
	cout << "\n" << "Positive for shifting left" << endl << "Negarive for shifting right" << endl;
	cin >> s;


	// call the function circular shift
	circularShift(A, l, s);

    cout << "Array after the shift" << endl;
	cout << "A= ";
	// output the array elements after shift
	for (int i = 0; i < l; i++)
		cout << A[i] << ' ';

}

// circular shift function
void circularShift(int *A, int l, int s)
{

	if (s < 0) {
		
		// right shift
		int k = -s % l;
		s = l - k; // number of right shifts is equal to l minus number of left shifts
	}

	int m = s % l;

	// no shift
	if (m == 0)
		return;

	if (l == 1)
		return;

	// create temporary array
	int temp[l];

	// two pointers at the end of the sub arrays
	int * p = A;
	//cout << "p = " << *p << endl;
	int * q = A + m;
	//cout << "q= " << *q << endl;

	for (int i = 0; q < A + l; q++, i++){
		temp[i] = *q;
		//cout << i << temp[i] << endl;
	}

	for (int j = l-m; j < l; p++, j++){
		temp[j] = *p;
		//cout << j << temp[j] << endl;
	}

	// copy the elements of temp into A
	for (int i = 0; i < l; i++) {
		A[i] = temp[i];
	}

}

