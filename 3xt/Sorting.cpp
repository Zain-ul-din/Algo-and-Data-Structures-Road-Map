// Sorting Algo

#include<iostream>
#include<utility>

void QuickSort(int startIdx , int lastIdx , int arr[]){
	if(startIdx >= lastIdx)
	    return;
	
	int povit = startIdx;
	int leftIdx = startIdx + 1;
	int rightIdx = lastIdx;
	
	while(leftIdx <= rightIdx){
		if(arr[leftIdx] > arr[povit] && arr[rightIdx] < arr[povit])
		   std::swap(arr[leftIdx] , arr[rightIdx]);
		if(arr[leftIdx] <= arr[povit])
           leftIdx += 1;
		if(arr[rightIdx] >= arr[povit])
		   rightIdx -= 1;   		   
	}
	
	std::swap(arr[rightIdx] , arr[povit]);
	
	QuickSort(rightIdx+1 , lastIdx , arr);
	QuickSort(startIdx , rightIdx-1 , arr);
}

const int SIZE = 10;

void DoMerge(int startIdx , int midIdx , int lastIdx , int arr[]){
	int i = startIdx;
	int j = midIdx + 1;
	int k = startIdx;
	int tempArray[SIZE];
	
	while(i <= midIdx && j <= lastIdx){
		if(arr[i] < arr[j]){
			tempArray[k] = arr[i];
			i += 1;
		}
		else{
			tempArray[k] = arr[j];
			j += 1;
		}
		k += 1;
	}
	
	// Copy Remaing's
	while(i <= midIdx){
		tempArray[k] = arr[i];
		i += 1;
		k += 1;
	}
	
	while(j <= lastIdx){
		tempArray[k] = arr[j];
		j += 1;
		k += 1;
	}
	
	// Copy into real Array
	for(int i = startIdx ; i <= lastIdx ;i ++)
	    arr[i] = tempArray[i];
}

void MergeSortHelper(int startIdx , int lastIdx , int arr[]){
	if(startIdx >= lastIdx)
	   return;
	
	int midIdx = (startIdx + lastIdx ) / 2;
	MergeSortHelper(startIdx , midIdx , arr);
	MergeSortHelper(midIdx + 1 , lastIdx , arr);
    DoMerge(startIdx , midIdx , lastIdx , arr);
}

void MergeSort(int startIdx , int lastIdx , int arr[]){
	if(startIdx >= lastIdx)
	   return;
	return MergeSortHelper(startIdx , lastIdx , arr);   
}

int main(){
	int arr[SIZE] = {3,1,9,5,7 ,-1,9,2,1};
//	QuickSort(0 , SIZE - 1 , arr);
    MergeSort(0 , SIZE - 1 , arr); //  Merge Sort
	for(int i =0 ; i < SIZE ; ++i)
	   std::cout <<  " " << arr[i] << " ";
}