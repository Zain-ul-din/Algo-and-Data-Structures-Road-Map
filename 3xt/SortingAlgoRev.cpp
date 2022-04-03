#include <iostream>

using  namespace std;

// Quick sort
void QuickSort(int startIdx , int lastIdx , int arr[]){
    if(startIdx >= lastIdx)
       return;
     
	 int pivotIdx = startIdx;      
     int leftIdx = startIdx + 1;
     int rightIdx = lastIdx;
     
     while(rightIdx >= leftIdx){
     	if(arr[leftIdx] > arr[pivotIdx] && arr[rightIdx] < arr[pivotIdx])
           swap(arr[rightIdx] , arr[leftIdx]);
        if(arr[leftIdx] <= arr[pivotIdx])
		   leftIdx += 1;
		
		if(arr[rightIdx] >= arr[pivotIdx])
		  rightIdx -= 1;      
	 }
	 swap(arr[rightIdx] , arr[pivotIdx]);
     
     // Quick Sort Helper
     
	 QuickSort(startIdx , rightIdx - 1 ,arr); 
	 QuickSort(rightIdx + 1 , lastIdx , arr);	 
	 
}
// 1st algo end here ...
const int MAXSIZE = 5;

// Merge Sort Helper
void DoMerge(int leftIdx ,int rightIdx, int midIdx , int arr[]){
	int i = leftIdx;
	int j = midIdx + 1;
	int k = leftIdx;
	int tempArray[MAXSIZE];
	
	while(i <= midIdx && j  <= rightIdx){
		if(arr[i] <= arr[j]){
			tempArray[k] = arr[i];
			i += 1;
		}
		else{
			tempArray[k] = arr[j];
			j += 1;
		}
		k +=1;
	}
	
	// Add Remaing Elements
	
	while(i <= midIdx){
		tempArray[k] = arr[i];
		k += 1;
		i += 1;
	}
	
	while(j <= rightIdx){
		tempArray[k] = arr[j];
		k += 1;
		j += 1;
	}
	
	for(int i = leftIdx ; i <= rightIdx ; i++)
        arr[i] = tempArray[i];
}

// Merge Sort
void MergeSort(int startIdx , int lastIdx , int arr[]){
	if(startIdx >= lastIdx)
	  return;
	  
	int mid = (startIdx + lastIdx) / 2;
	//cout << "Merge Sort\n";
	MergeSort(startIdx , mid , arr);
	MergeSort(mid + 1 , lastIdx , arr);
	
	DoMerge(startIdx , lastIdx , mid, arr);  
}


bool BinarySearch(int startIdx , int lastIdx , int arr[] , int element){
	int mid;
	while(lastIdx >= startIdx){
		mid = (startIdx + lastIdx) / 2;
		
		if(arr[mid] == element)
		   return true;
		
		if(element < arr[mid])
		   lastIdx = mid - 1;
		   
		if(element > arr[mid])
		   startIdx = mid + 1;      
	}
	return false;
}

int Max (int val1 , int val2){
	if(val1 > val2)
	   return val1;
	return val2;   
}

int KadensAlgo(int startIdx , int lastIdx , int arr[]){
	int max = arr[0];
	int maxSoFar = arr[0];
	
	for(int i = 0 ; i <= lastIdx ; i ++){
		max = (max, max + arr[i]);
		maxSoFar = (maxSoFar , max);
	}
	return maxSoFar;
}

// Driver Code
int main () {
	int arr[MAXSIZE] = {3,1,9,5,7};
	MergeSort(0 , MAXSIZE-1 ,arr);
//	QuickSort(0 , 4 , arr);
	for(int i = 0 ; i< MAXSIZE; ++i)
	  cout << " " << arr[i] << " ";
	  
	 if(BinarySearch(0 , 4  , arr , 5)){
	 	cout << " Element Found ! " ;
	 }else cout << " Element not Found ! " ;
	 
	 int array [5] = { -3, -3, -3 , 9 , 1};
	 
}



