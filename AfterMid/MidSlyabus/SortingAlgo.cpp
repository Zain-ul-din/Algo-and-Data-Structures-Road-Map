
#include <iostream>
#include <utility>

int ARR[] = { 3, 1, 9, 5, 7 , 9, 8, 11, 23, 4, 5, 0, 89, 100, 83, 90, 10, 70, -1, 90, -10};
const size_t SIZE = 20;


void QuickSort(int startIdx , int endIdx){

    if( startIdx >= endIdx)
        return;

    int pivotIdx = startIdx;
    int leftIdx = startIdx +1;
    int rightIdx = endIdx;

    while(rightIdx >= leftIdx){
        if(ARR[leftIdx] > ARR[pivotIdx] && ARR[rightIdx] < ARR[pivotIdx])
            std::swap(ARR[leftIdx] , ARR[rightIdx]);

        if(ARR[leftIdx] <= ARR[pivotIdx])
            leftIdx  += 1;

        if(ARR[rightIdx] >= ARR[pivotIdx])
            rightIdx -= 1;
    }


    std::swap(ARR[pivotIdx] , ARR[rightIdx]);

    QuickSort( rightIdx + 1, endIdx);
    QuickSort(startIdx, rightIdx - 1);
}


class Car{
public:

};

// Driver Code
int main (){
    QuickSort(0 , SIZE-1);
    for(int i (0) ; i < SIZE ; i++)
        std::cout << " " << ARR[i] << " ";



}
