// 6 Sorting Algorithms
/*
 * Bubble Sort (Done)
 * Selection Sort (Done)
 * Insertion Sort 
 * Merge Sort  
 * Quick Sort 
 * heap sort
*/
#include<iostream>
using namespace std;

template<typename T>
void Swap(T &val1,T &val2){
	if(val1 == val2)
	   return;
	val1 = val1 ^ val2;
	val2 = val1 ^ val2;
	val1 = val1 ^ val2;
}
template<typename T>
void PrintArr(T arr[],int size){
	for(int i=0;i<size;++i)
		cout<<" "<<arr[i]<<" ";
	cout<<endl;
}
/* Sorting Algo's */

// Bubble Sort
template<typename T>
void BubbleSort(T arr[],int size,bool useAscendingOrder = true){
	bool isSorted = false;
	
	while(!isSorted){
		isSorted = true;
		for(int i=0;i<size;++i)
		   if(arr[i] > arr[i+1] && i+1 != size){
		   	  Swap(arr[i],arr[i+1]);
		   	  isSorted = false;
		   } 
	}
	/*
	solution 2
	  for(int i=0;i<size;++i)
	    for(int j=0;j<size;++i)
	       itr  one by one over loop
	*/
}

// Insertion Sort
template<typename T>
void InsertionSort(T arr[],int size,bool useAscendingOrder = true){
	int j =0;
	if(useAscendingOrder)
	 for(int i=0;i<size;++i){
		j = i;
		
		while(j>0 && arr[j] > arr[j-1]){
			Swap(arr[j-1],arr[j]);
			j--;
		}
	 }
	else 
	 for(int i=0;i<size;++i){
		j = i;
		
		while(j>0 && arr[j] < arr[j-1]){
			Swap(arr[j-1],arr[j]);
			j--;
		}
	 }
}
// Selection Sort HelperMethods
template<typename T>
int Max(T arr[],int start,int size,T element){
	if(start = size-1)
	    return start;
	int index = start;
	for(int i=start;i<size;++i){
		if(arr[i] > element){
		   index = i;
		}
	}
	return index;
}
// Selection Sort O(n^2)
template<typename T>
void SelectionSort(T arr[],int size,bool useAscendingOrder = true){
	if(useAscendingOrder){
	//	arr[size] = arr[size-1];
		for(int i=0;i<size;i++){
			  Swap(arr[i],arr[Max(arr,i,size,arr[i])]);
			PrintArr(arr,size);
		} 
	}else{
		
	}
}

// Quick sort
template<typename T>
void QuickSort(T arr[],int size){
	// Making Pivot
	int pivotIndex = 0; // Always Zero
	int lastIndex = size-1;
	
	int leftPtr = pivotIndex +1;
	int rightPtr = lastIndex;
	
	
	while(rightPtr > leftPtr){
		if(arr[leftPtr] < arr[pivotIndex] && arr[rightPtr] < arr[pivotIndex])
		   leftPtr++;
		else if(arr[leftPtr] > arr[pivotIndex] && arr[rightPtr] > arr[pivotIndex])
          Swap(arr[leftPtr],arr[rightPtr]);
        else if(arr[rightPtr] > arr[pivotIndex])
           rightPtr--;
	}
	
	// Next Day ... :-)
}
// 8,7,6,5,4,3,9
// Driver Code
int main(){
	int arr[7] = {8,7,6,5,4,10,9}; // 7 Element
	
	
	
	/*    Algo implementation  */
	// BubbleSort(arr,7); // Working ..
	//   InsertionSort(arr,7); // Wokring ..
    //	SelectionSort(arr,7);
	QuickSort(arr,7);
	// print Array
	for(int i=0;i<7;++i)
	  cout<<" "<<arr[i]<<" ";
	cout<<endl;
}