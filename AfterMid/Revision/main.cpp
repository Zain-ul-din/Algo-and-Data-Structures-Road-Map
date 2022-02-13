
// Min & Max Heap

/*
 * HEAP :-
 * Heap is Complete Binary Tree
 * A tree have no gap btw the node it's called complete binary tree
 * Heap always filled from left to right

 Height of Complete tree : log(n)

 Formula's:
   Parent  : ( i - 1) / 2
   left Child : 2(i) + 1
   Right Child : 2(i) + 2

 */


#include<iostream>
#include <vector>
#include <utility>

class MinHeap{
public:
    MinHeap(){}

    MinHeap(std::vector<int> array){
        heap = array;
    }

    void Insert(const int data){
        heap.push_back(data);
        int size = heap.size() - 1 ;
        int parent = (size - 1) / 2;
        SiftUp(size  , parent );
    }

    void Remove(){
        if(heap.empty())
            return;
        std::swap(heap[0] , heap[heap.size() -1]);
        heap.pop_back();
        SiftDown(0 , 1 , 2 , heap.size() - 1);
    }

    void Debug(){
        for(int i : heap)
            std::cout << " " << i << " ";
    }

    bool IsEmpty(){return heap.empty();}

    int Peek(){
        if(IsEmpty())
            return -1;
        return heap[0];
    }
private:
    std::vector<int> heap;

    void SiftUp(int idx, int parentIdx ){
        if(parentIdx < 0)
            return;

        while (idx > 0 && heap[idx] < heap[parentIdx]){
            std::swap(heap[idx] , heap[parentIdx]);
            idx = parentIdx ;
            parentIdx = (idx - 1) / 2;
        }
    }

    void SiftDown(int idx , int leftIdx , int rightIdx , const int maxIdx){
       if(leftIdx > maxIdx && rightIdx > maxIdx)
           return;

       // Null Flags
       leftIdx = (leftIdx > maxIdx) ? -1 : leftIdx;
       rightIdx = (rightIdx > maxIdx) ? -1 : rightIdx;

       int minIdx;
       if(leftIdx != -1 && rightIdx != -1)
           minIdx = (heap[leftIdx] < heap[rightIdx]) ? leftIdx : rightIdx;
       else minIdx = (leftIdx == -1) ? rightIdx : leftIdx;

       if(heap[idx] > heap[minIdx])
           std::swap(heap[minIdx] , heap[idx] );
       else return;

       idx = minIdx;
       SiftDown(minIdx , (2*idx) + 1 , (2*idx) + 2 , maxIdx);
    }
};

// Quick Sort
void QuickSort(int startIdx , int lastIdx ,std::vector<int>& array) {
    if(startIdx > lastIdx)
        return;

    int pivot = startIdx;
    int leftIdx = startIdx +1;
    int rightIdx = lastIdx;

    while (leftIdx <= rightIdx){
        if(array[leftIdx] > array[pivot] && array[rightIdx] < array[pivot] )
            std::swap(array[rightIdx] , array[leftIdx]);

        if(array[leftIdx] <= array[pivot])
            leftIdx += 1;
        if(array[rightIdx] >= array[pivot])
            rightIdx -= 1;
    }

    std::swap(array[rightIdx] , array[pivot]);

    QuickSort(0 , rightIdx-1 , array);
    QuickSort(rightIdx+1 , lastIdx , array);
}

// Merge Sort
void MergeSort(std::vector<int>& arr){

}

// Driver Code
int main () {
   MinHeap heap;

    heap.Insert(3);
    heap.Insert(1);
    heap.Insert(9);
    heap.Insert(5);
    heap.Insert(7);
    heap.Insert(3);
    heap.Insert(1);
    heap.Insert(9);
    heap.Insert(5);
    heap.Insert(7);

    while (!heap.IsEmpty()){
        std::cout << " " << heap.Peek() << " ";
        heap.Remove();
    }
    std::cout << "\n";

    std::vector<int>  vec {3,1,9,5,7 , 5,7,9,0,-1};
    QuickSort(0 , vec.size()-1 , vec);
    for(int i = 0 ; i < vec.size() ; i++)
        std::cout << " " << vec[i] << " ";
    std::cout << " \n";
}