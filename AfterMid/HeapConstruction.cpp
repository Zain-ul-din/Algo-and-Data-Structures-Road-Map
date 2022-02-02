 // Both Min & Max  Heap Construction

#include <iostream>
#include <vector>


// Node = i
// left child = 2i + 1
// right child = 2i + 2
// Parent Node (i-1 /2)


class MinHeap{
public:
     MinHeap(std::vector<int>& vector){
          heap = vector;
     }

     void BuildHeap () {
         if(IsEmpty())
             return;

         int parentIdx = LastIndex() -1 / 2;
         std::cout << "Parent Idx : " << parentIdx;

         for (int  i = parentIdx ; i >= 0 ; i--)
             SiftDown(i , LastIndex() , heap);
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
         // Debug();
     }

     void Debug(){
         for(auto i : heap)
             std::cout << i << " ";
         std::cout << "\n";
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


// Max Heap Construction
class MaxHeep{
public:
    MaxHeep(){
        heap.clear();
    }

    void Insert(int data){
        heap.push_back(data);
        SiftUp(heap.size()-1 , heap);
    }

    void Remove(){
        if(IsEmpty())
            return;

        Swap(heap[0] , heap[heap.size() - 1]);
        heap.pop_back();
        SiftDown(0 , heap.size() - 1 , heap);
    }

    bool IsEmpty(){
        return heap.empty();
    }

    int Peek(){
        return (IsEmpty()) ? -1 : heap[0];
    }
private:
    std::vector<int> heap;

    void SiftUp(int currentIdx ,std::vector<int> &heap){
        int parentIdx = (currentIdx - 1) / 2; // floor
        while (currentIdx > 0 && heap[currentIdx] > heap[parentIdx]){
            Swap(heap[currentIdx] , heap[parentIdx]);
            currentIdx = parentIdx;
            parentIdx = (currentIdx - 1) / 2; // floor
        }
    }

    void SiftDown(int currentIdx , int maxIdx , std::vector<int>& heap){
        SiftDownHelper(currentIdx , (2*currentIdx) + 1 , (2*currentIdx)+2 , heap.size()-1 , heap);
    }

    void SiftDownHelper(int currentIdx , int leftChildIdx , int rightChildIdx , int maxIdx , std::vector<int>& heap) {
        if(leftChildIdx > maxIdx && rightChildIdx > maxIdx)
            return;

        leftChildIdx = leftChildIdx   > maxIdx   ?   -1 : leftChildIdx;
        rightChildIdx = rightChildIdx > maxIdx   ?   -1 : rightChildIdx;

        // -1 is flag represents null node

        // finds idx of max node
        int _maxIdx;
        if(leftChildIdx != -1 && rightChildIdx != -1)
            _maxIdx = heap[leftChildIdx] > heap[rightChildIdx] ? leftChildIdx : rightChildIdx;
        else _maxIdx = leftChildIdx == -1 ? rightChildIdx : leftChildIdx;

        if(heap[currentIdx] < heap[_maxIdx])
            Swap(heap[currentIdx] , heap[_maxIdx]);
        else return;

        currentIdx = _maxIdx;

        SiftDownHelper(currentIdx , (2*currentIdx) + 1 , (2*currentIdx) + 2 , maxIdx ,heap);
    }

    void Swap(int& val1 , int& val2){
        val1 = val1 ^ val2;
        val2 = val1 ^ val2;
        val1 = val1 ^ val2;
    }
};

// Driver Code
int main () {
     std::vector<int> vec {
//             3,1,9,5,7,11, 13,2,0,39,49,59
     };

     MinHeap heap(vec);
//     heap.Insert(3);
//     heap.Insert(1);
//     heap.Insert(9);
//     heap.Insert(5);
//     heap.Insert(7);

     heap.Insert(3);
     heap.Insert(1);
     heap.Insert(9);
     heap.Insert(5);
     heap.Insert(7);
     heap.Insert(11);
     heap.Insert(13);
     heap.Insert(2);
     heap.Insert(0);
     heap.Insert(39);
     heap.Insert(49);
     heap.Insert(59);

     std::cout << "Min Heap :-) OutPut :- \n";
     while(!heap.IsEmpty()){
         std::cout << " "<< heap.peek() << " ";
         heap.Delete();
     }
     std::cout << "\n";

     MaxHeep mheap;
     mheap.Insert(3);
     mheap.Insert(1);
     mheap.Insert(9);
     mheap.Insert(5);
     mheap.Insert(7);
     mheap.Insert(11);
     mheap.Insert(13);
     mheap.Insert(2);
     mheap.Insert(0);
     mheap.Insert(39);
     mheap.Insert(49);
     mheap.Insert(59);

     std::cout << "Max Heap :-) OutPut :- \n";

     while (!mheap.IsEmpty()){
         std::cout << " " << mheap.Peek() << " ";
         mheap.Remove();
     }

     std::cout << "\n";
}

 // 0  1  9  39  3  5  13  11  7  2  49  59
//3,1,9,5,7,11, 13,2,0,39,49,59

//  0  3  9  39  5  2  13  11  7  1  49  59

