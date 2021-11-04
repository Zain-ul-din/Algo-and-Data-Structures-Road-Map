// Searching Algo
/*
 * Linear Search
 * Binary Search
*/
#include<iostream>
#include<algorithm>
using namespace std;

// Linear Search
template<typename T>
int LinearSearch(T arr[],int size,T element){
	for(int i=0;i<size;++i)
	   if(arr[i] == element)
	     return i;
	return -1;
}

// Binary Search
template<typename T>
int BinarySearch(T arr[],int size,T element){
    sort(arr,arr+size);
	for(int i=0;i<size;++i)
	   cout<<" "<<arr[i]<<" ";
	cout<<endl;
	
	cout<<size<<endl;// testing
	T expectedMatch;
	int leftPtr = 0 ,rightPtr = size-1;
	int midPtr = 0;
	while(rightPtr >= leftPtr){
		midPtr = (leftPtr + rightPtr) /2;
		expectedMatch = arr[midPtr];
		if(expectedMatch == element)
		    return midPtr;
		if(element < expectedMatch) // Number at left
		    rightPtr = midPtr-1; // Move right to left
		else if(element > expectedMatch )  // Number at right
		    leftPtr = midPtr+1; // Move left to right
	}
	return -1;
}

// Quick Select
template<typename T>
void QuickSelect(T arr[],int size,T element){
	
}
// Driver Code
int main(){
	int arr[7] = {2,3,44,6,7,89,0};
	
	cout<<"Loading .. "<<endl;
	cout<<BinarySearch(arr,7,89)<<endl;
}