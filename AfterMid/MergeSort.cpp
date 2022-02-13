//// Merge Sort Algo
////
//// Solution _ 1
//
//#include <iostream>
//#include <vector>
//#include <utility>
//
//std::vector<int> MergeSort(std::vector<int>&);
//void MergeSortHelper(std::vector<int>& ,int  , int , std::vector<int>& );
//void DoMerge(std::vector<int>& , int  , int  , int  , std::vector<int>& );
//
//// MergeSort
//std::vector<int> MergeSort(std::vector<int>& array){
//    if(array.size() <= 1) return array;
//    std::vector<int> auxiliaryArray = array;
//    MergeSortHelper(array , 0 , array.size()-1 , auxiliaryArray);
//    return array;
//}
//
//// Helper
//void MergeSortHelper(std::vector<int>& array, int  startIdx, int lastIdx , std::vector<int>& auxiliaryArray){
//    if(startIdx >= lastIdx) return;
//    int midIdx = (startIdx + lastIdx) / 2;
//    MergeSortHelper(auxiliaryArray , startIdx , midIdx , array);
//    MergeSortHelper(auxiliaryArray , midIdx + 1 , lastIdx , array);
//
//    for(int i = startIdx ; i <= lastIdx ; i++)
//        std::cout << " " << array[i] << " ";
//    std::cout << "\n";
//
//    DoMerge(array , startIdx , midIdx , lastIdx , auxiliaryArray);
//}
//
//
//void DoMerge(std::vector<int>& array , int startIdx , int midIdx , int lastIdx , std::vector<int>& auxiliaryArray){
//    int  k = startIdx , i = startIdx , j = midIdx;
//
//    while (i <= midIdx && j <= lastIdx){
//        if(auxiliaryArray[i] <= auxiliaryArray[j]){
//            array[k] = auxiliaryArray[i];
//            i += 1;
//        }
//        else{
//            array[k] = auxiliaryArray[j];
//            j += 1;
//        }
//        k += 1;
//    }
//    // Remaining Elements
//    while (i <= midIdx){
//        array[i] = auxiliaryArray[i];
//        i += 1;
//        k += 1;
//    }
//
//    while (j <= lastIdx){
//        array[k] = auxiliaryArray[i];
//        j += 1;
//        k += 1;
//    }
//}
//
//// Driver Code
//int main (){
//   std::vector<int> array = {3,1,9,5,7};
//   array = MergeSort(array);
//   for(int i =0 ; i < array.size() ; i ++)
//       std::cout << " " << array[i] << " ";
//}
//

#include<iostream>
#include<utility>

const int SIZE = 10;

void MergeSort(int startIdx , int lastIdx , int arr[]);
void DoMerge(int startIdx , int midIdx , int lastIdx , int arr[]);
void MergeSortHelper(int startIdx , int lastIdx , int arr[]);

void MergeSort(int startIdx , int lastIdx , int arr[]){
    if(startIdx >= lastIdx) return;
    return MergeSortHelper( startIdx , lastIdx , arr);
}

void MergeSortHelper(int startIdx , int lastIdx , int arr[]){
    if(startIdx >= lastIdx)
        return;

    int midIdx = (startIdx + lastIdx ) / 2;
    MergeSort( startIdx , midIdx , arr );
    MergeSort(midIdx +1 , lastIdx , arr );

    DoMerge(startIdx , midIdx , lastIdx , arr);
}

void DoMerge(int startIdx , int midIdx , int lastIdx , int arr[]){
    int i = startIdx;
    int j = midIdx + 1;
    int k = startIdx;
    int tempArray[SIZE];

    while (i <= midIdx && j <= lastIdx){
        if (arr[i]<=arr[j]){
            tempArray[k]=arr[i];
            i += 1;
            k += 1;
        }
        else{
            tempArray[k]=arr[j];
            j += 1;
            k += 1;
        }
    }

    while(i<=midIdx){
        tempArray[k]=arr[i];
        i += 1;
        k += 1;
    }

    while(j<=lastIdx) {
        tempArray[k]=arr[j];
        j += 1;
        k += 1;
    }

    for (int i=startIdx;i<=lastIdx; i += 1)
        arr[i]=tempArray[i];
}

// Driver Code
int main () {
    int arr[] = {3,1,9,7,5 , 8 , 9 , 3,2,1};

    MergeSort(0 , SIZE - 1 , arr);
    std::cout << "\n";
    for(int  i = 0 ; i < SIZE ; i ++)
        std::cout << " " << arr[i] << " ";
}