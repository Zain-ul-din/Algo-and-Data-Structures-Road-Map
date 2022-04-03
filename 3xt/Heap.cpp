 // Heap Construction

#include <iostream>
#include <vector>


// Node = i
// left child = 2i + 1
// right child = 2i + 2
// Parent Node (i-1 /2)


class MinHeap{
public:
     MinHeap(std::vector<int>& vector){
          heap = BuildHeap(vector);
     }

     std::vector<int> BuildHeap(std::vector<int> &vector) {
         int parentIdx = (vector.size() -2) / 2;
         for( int  i = parentIdx ; i >= 0 ; i -- ){
             SiftDown(i , vector.size() -1 , vector);

             std::cout << vector[i] << " ";
         }



         return vector;
     }

     void Insert (const int data) {
         heap.push_back(data);
         SiftUp(LastIndex() , heap);
     }

     void Delete(){
         if(heap.empty())
             return;

         Swap(heap.at(0) , heap.at(LastIndex()));
         heap.pop_back();
         SiftDown( 0 , LastIndex() , heap);
     }



     int peek(){
         if(!heap.empty())
           return heap[0];
         return -1;
     }

     bool IsEmpty() {
         return heap.empty();
     }
private:
    std::vector<int> heap;

// Node = i
// left child = 2i + 1
// right child = 2i + 2
// Parent Node (i-1) /2) floor

    void SiftUp (int currentIndex , std::vector<int>& vector) {
        int parentIdx = (currentIndex - 1) / 2; // floor

        // we have to go bottom to top
        while (currentIndex > 0 && heap.at(currentIndex) < heap.at(parentIdx)){
            Swap(heap.at(currentIndex)  , heap.at(parentIdx));
            currentIndex = parentIdx;
            parentIdx = (currentIndex - 1) / 2; // floor
        }
    }

    void SiftDown (int currentIndex , const int lastIndex , std::vector<int>& vector) {
        SiftDownHelper(currentIndex , (currentIndex*2) +1 , (currentIndex*2) + 2 , lastIndex , vector);
    }

    int LastIndex() const { return heap.size() - 1;}

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
        int midIdx;

        if(leftChildIdx != -1 && rightChildIdx != -1 )
            midIdx = vector[leftChildIdx] < vector[rightChildIdx] ? leftChildIdx : rightChildIdx;
        else midIdx = (leftChildIdx == -1) ? rightChildIdx : leftChildIdx;

        if(vector[currentIdx] > vector[midIdx])
          Swap(vector[midIdx] , vector[currentIdx]);

        currentIdx = midIdx;

        SiftDownHelper(currentIdx , (2*currentIdx) +1 , (2*currentIdx) +2 , lastIdx , heap);
    }
};

// Driver Code
int main () {
     std::vector<int> vec {
         3,1,9,5,7
     };

     MinHeap heap(vec);
     std::cout << heap.peek();

}

