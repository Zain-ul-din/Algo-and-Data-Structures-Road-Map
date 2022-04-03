#include<iostream>
#include<utility>

void QuickSort(int startIdx , int endIdx , int arr[]) {
	if(startIdx >= endIdx)
	  return;
	
	int pivot = startIdx;
	int leftIdx = startIdx + 1;
	int rightIdx = endIdx;
	
	while(rightIdx >= leftIdx) {
		if(arr[leftIdx] > arr[pivot] && arr[rightIdx] < arr[pivot])
		  std::swap(arr[leftIdx] , arr[rightIdx]);
		
		if(arr[leftIdx] <= arr[pivot])
		   leftIdx += 1;
		
		if(arr[rightIdx] >= arr[pivot])
		  rightIdx -= 1;     
	}  
	
	std::swap(arr[rightIdx] , arr[pivot]);
	
	QuickSort(rightIdx + 1 , endIdx , arr);
	QuickSort(startIdx , rightIdx - 1 , arr);
}

void DoMerge(int leftIdx , int midIdx , int rightIdx , const int size , int arr[]){
	if(leftIdx >= rightIdx)
	  return;
	  
	int i = leftIdx;
	int j = midIdx + 1;
	int k = i;
    int axulliaryArray [size];
	
	while(i <= midIdx && j <= rightIdx){
		if(arr[i] < arr[j]){
		    axulliaryArray[k] = arr[i];
			i += 1;
		}
		else{
			axulliaryArray[k] = arr[j];
			j += 1;
		}
		k += 1;
	} 	
	
	while(i <= midIdx ){
		axulliaryArray[k] = arr[i];
		i += 1;
		k += 1;
	}
	
	while(j <= rightIdx) {
		axulliaryArray[k] = arr[j];
		j += 1;
		k += 1;
	}
	
	for(int itr = leftIdx ; itr <= rightIdx ; itr +=1 )
	   arr[itr] = axulliaryArray[itr];
}

void MergeSort(int startIdx , int lastIdx , const int size ,  int arr[]){
	if(startIdx >= lastIdx)
	  return;
	
	int midIdx = (startIdx + lastIdx ) / 2;
	
	MergeSort(startIdx , midIdx , size , arr);
	MergeSort(midIdx + 1 , lastIdx , size , arr);  
	DoMerge(startIdx , midIdx , lastIdx , size , arr);
}

int main () {
	int arr[8] = {12,23,3,43,51,35,19,45};
//	QuickSort(0 , 7 , arr);
    MergeSort(0 , 7 , 8 , arr);
	for(int i =  0 ; i < 8; i +=1 )
	   std::cout << " " << arr[i] << " ";
	   
}