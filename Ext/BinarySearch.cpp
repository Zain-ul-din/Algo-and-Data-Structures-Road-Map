// Binary Search Algo

#include<bits/stdc++.h>
using namespace std;

int main(){
	// Must be a sorted array
	int arr[] = {7 , 6 , 4 , 3  ,-1};
	const int arrSize = (sizeof(arr)/sizeof(arr[0]))- 1;
	
	const int numberToFind = 3;// Number we're looking for
	
	// using Pointer's
	int leftIndex = 0;
	int rightIndex = arrSize;
	
	int midIndex;
	
	int results = -1;
	
	int potentialMatch;
	// Algo Implementation
	while(rightIndex >= leftIndex){
		midIndex = leftIndex + rightIndex / 2;
		potentialMatch = arr[midIndex];
		
		if(potentialMatch == numberToFind){ //  Number Has been Found
			results = potentialMatch;
			break;
		}
		else if(numberToFind < potentialMatch){ // if Number is under we have to move rightIndex to middle -1
			rightIndex = midIndex - 1;
		}
		else{// if Number is not Under middle then we have to move left to middle + 1
			leftIndex = midIndex + 1;
		}
	} //  +1 & -1 bcz we have no potentialMatch at middle
	cout<<"Result is  : "<<results<<endl;
}

//nthfibonacci_solution 
// vector.push_back(arr[i - 1] + arr[i -2]);