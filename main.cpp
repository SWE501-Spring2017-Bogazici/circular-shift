#include <iostream>
#include <stdlib.h>

using namespace std;

void shift(int array[] , int L, int shift){
	
	int tempArray[L];
	
	if(shift >= 0){
		
		for(int i = 0 ; i < L ; i++ ){
		
		int m = (i + shift) % L;
		
		tempArray[i] = array[m];
		
		}
		
		cout << "Array left shifted " << shift << " times." << endl;
		
	}else{
		
		shift = abs(shift);
		
		for(int i = 0 ; i < L ; i++ ){
		
		int m = (i - shift) % L;
		
		if(m<0){
			m = m+L;
		}
		
		tempArray[i] = array[m];
		
		}
		cout << "Array right shifted " << shift << " times." << endl;
		
	}
	
	for(int i = 0 ; i < L ; i++ ){
		
		array[i] = tempArray[i];
		
	}
	
}

void printArray(int array[], int L){
	
	for(int i = 0 ; i < L ; i++ ){
		
		cout << array[i] << " ";
		
	}
	cout << endl;
}

int main(int argc, char** argv) {
	
	int A[10] = {1,2,3,4,5,6,7,8,9,0};
	
	int L = 10;
	
	printArray(A,L);
	
	shift(A,L,-3);
	
	printArray(A,L);
	
	return 0;
}

