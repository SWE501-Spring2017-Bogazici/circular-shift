//		Tugcan Olgun
//		2016719210
//		HW2

#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;


void cycle(int *arr, int sizeOfArray, int cycleNumber)
{
	int cycleAmount = cycleNumber % sizeOfArray;
	if(cycleNumber>=0) {
		cout << "It's a positive number. Cycling left." << endl;
		for(int i = 0; i < sizeOfArray; i++) {
			if (i + cycleAmount >= sizeOfArray) {
				cout << *(arr+((i + cycleAmount)%sizeOfArray)) << endl;
			} else {
				cout << *(arr+i + cycleAmount) << endl;
			}
		}
	} else {
		cout << "It's a negative number. Cycling right." << endl;
		for(int i = 0; i < sizeOfArray; i++) {
			if (i + cycleAmount < 0) {
				cout << *(arr+(sizeOfArray+(i+cycleAmount))) << endl;
			} else {
				cout << *(arr+i + cycleAmount) << endl;
			}
		}
	}
}

void cycleAndSave(int *arr, int sizeOfArray, int cycleNumber) {
	int cycleAmount = cycleNumber % sizeOfArray;
	int temp[abs(cycleAmount)];
	if(cycleAmount>=0) {
		cout << "It's a positive number. Cycling left." << endl;
		for(int i = 0; i < sizeOfArray; i++) {
			if(i < cycleAmount) {
				temp[i] = *(arr+i);
				*(arr+i) = *(arr+i+cycleAmount);
			} else {
				if(sizeOfArray - i <= cycleAmount) {
					*(arr+i) = temp[(i+cycleAmount)%sizeOfArray];
				} else {
					*(arr+i) = *(arr+i+cycleAmount);
				}
			}
		}
	} else {
		cout << "It's a negative number. Cycling right." << endl;
		for(int i = sizeOfArray-1; i >= 0; i--) {
			if (i + cycleAmount < 0) {
				*(arr+i) = temp[abs(i+cycleAmount)];
			} else {
				temp[sizeOfArray-i] = *(arr+i);
				*(arr+i) = *(arr+i+cycleAmount);
			}
			
		}
	}
	for (int i = 0; i < sizeOfArray; ++i)
	{
		cout << *(arr+i) << endl;
	}
}

int main()
{
	int cycleNumber;
	int runChoice;
	bool isCorrect = false;
	int arr [5] = {1, 2, 3, 4, 5};
	while(isCorrect==false) {
		cout << "The array is: 1, 2, 3, 4, 5" << endl;
		cout << "Enter 1 if you want to run it without changing actual values and just print out," << endl;
		cout << "Enter 2 if you want to change the array's values and print: " << endl;
		cin >> runChoice;
		if(runChoice == 1 || runChoice == 2) {
			isCorrect = true;
		}
	}
	int sizeOfArray = sizeof(arr)/sizeof(*arr);
	cout << "Please enter cycle amount (Can be positive or negative): ";
	cin >> cycleNumber;
	if(runChoice == 1) {
		cycle(arr, sizeOfArray, cycleNumber);
	} else {
		cycleAndSave(arr, sizeOfArray, cycleNumber);
	}
	cout << "Program ended" << endl;
}