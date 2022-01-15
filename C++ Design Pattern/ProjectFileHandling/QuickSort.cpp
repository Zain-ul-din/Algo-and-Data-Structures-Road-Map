// Quick Sort

#include <iostream>
#include <string>

using namespace std;


template<typename T = int> void QuickSortHelper(T[],int&,int&);

template<typename T> void Swap(T& val1 , T& val2){ T temp = val1; val1 = val2; val2 = temp;}

template<typename T=int > void QuickSort(T arr[],const int& size){
    if(size < 1) return;
    int start = 0;
    int last = size -1;
    return QuickSortHelper(arr ,start , last);
}


template<typename T>
void QuickSortHelper(T arr[],int& start,int& last){
    if(last < 1) return;
    // sort array in accenting order
    const int pivot = start;
    start ++;
    while (start <= last){
        // moves all element under pivot to left of the pivot
        if(arr[start] > arr[pivot] && arr[last] < arr[pivot]) // swap cond
            swap(arr[start] , arr[last]);
        if(arr[start]  <= arr[pivot])
            start++;
        if(arr[last] > arr[pivot])
            last--;
        cout<<"*\t";
    }
    Swap(arr[last] , arr[pivot]);
    QuickSortHelper(arr,start , last);
}
// Driver Code
int main() {
    int arr[] = {3,1,9,5,7};
    const int size = sizeof(arr) / sizeof (arr[0]);
    QuickSort(arr , size);
    for(int* i = arr; i != arr+5; i++){
        cout<<"  "<<*i<<" ";
    }
    cout<<"\n";
}
