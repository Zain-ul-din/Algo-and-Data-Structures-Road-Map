
#include<iostream>
#include<vector>
#include<utility>

class MinHeap{
public:
    MinHeap(std::vector<int>& arr){
         heap = arr;
         Heapify((GetLength()-1)/2 , heap);
     }

     void Heapify(int parentIdx , std::vector<int> &heap){
          for(int i = parentIdx ; i >= 0 ; i -=1 )
              SiftUp(parentIdx,heap);
     }

     void Debug(){
        for(int i = 0 ; i < heap.size() ; i+= 1)
            std::cout << " " << heap[i] << " ";
    }

    int GetLength(){return heap.size()-1;}
private:
    std::vector<int> heap;

    void SiftUp(int idx , std::vector<int>& heap ){
        int parentIdx = (idx - 1) / 2;
        while (idx > 0 && heap[idx] < heap[parentIdx]){
            std::swap(heap[idx] , heap[parentIdx]);
            idx = parentIdx;
            parentIdx = (idx - 1) / 2;
        }
    }

    void SiftDown (int currentIndex , const int lastIndex , std::vector<int>& vector) {
        SiftDownHelper(currentIndex , (currentIndex*2) +1 , (currentIndex*2) + 2 , lastIndex , vector);
    }


    void Swap (int& val1 , int& val2){
        int temp = val1;
        val1 = val2;
        val2 = temp;
    }

    void SiftDownHelper(int currentIdx , int leftChildIdx, int rightChildIdx , const int lastIdx , std::vector<int>& vector){
        if(leftChildIdx > lastIdx && rightChildIdx > lastIdx)
            return;


        leftChildIdx = (leftChildIdx > lastIdx)   ? -1 : leftChildIdx;
        rightChildIdx = (rightChildIdx > lastIdx) ? -1 : rightChildIdx;


        // Here -1 is flag that represent NULL
        int minIdx;

        // checks if any of one is not null and find idx of min value
        if(leftChildIdx != -1 && rightChildIdx != -1 )
            minIdx = vector[leftChildIdx] < vector[rightChildIdx] ? leftChildIdx : rightChildIdx;
        else minIdx = (leftChildIdx == -1) ? rightChildIdx : leftChildIdx;

        // Swap if currentIdx value is not under min idx
        if(vector[currentIdx] > vector[minIdx])
            Swap(vector[minIdx] , vector[currentIdx]);
        else return;
        currentIdx = minIdx;

        SiftDownHelper(currentIdx , (2*currentIdx) +1 , (2*currentIdx) +2 , lastIdx , heap);
    }
};

int main () {
    std::vector<int> array = {3,2,4,1,7};
    MinHeap heap(array);
    heap.Debug();
}
