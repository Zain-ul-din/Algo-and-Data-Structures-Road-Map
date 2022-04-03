#include<iostream>
#include <vector>

using namespace std;
class MinHeap {
public:
	
	bool IsEmpty(){
		return heap.empty();
	}
 vector<int> heap;
 MinHeap(vector<int> vector) { heap = buildHeap(&vector); }
 // O(n) time | O(1) space
 vector<int> buildHeap(vector<int> *vector) {
 int firstParentIdx = (vector->size() - 2) / 2;
 for (int currentIdx = firstParentIdx; currentIdx >= 0; currentIdx--) {
 siftDown(currentIdx, vector->size() - 1, vector);
 }
 return *vector;
 }
 // O(log(n)) time | O(1) space
 void siftDown(int currentIdx, int endIdx, vector<int> *heap) {
 int childOneIdx = currentIdx * 2 + 1;
 while (childOneIdx <= endIdx) {
 int childTwoIdx = currentIdx * 2 + 2 <= endIdx ? currentIdx * 2 + 2 : -1;
 int idxToSwap;
 if (childTwoIdx != -1 && heap->at(childTwoIdx) < heap->at(childOneIdx)) {
 idxToSwap = childTwoIdx;
 } else {
 idxToSwap = childOneIdx;
 }
 if (heap->at(idxToSwap) < heap->at(currentIdx)) {
 swap(currentIdx, idxToSwap, heap);
 currentIdx = idxToSwap;
 childOneIdx = currentIdx * 2 + 1;
 } else {
 idxToSwap = childOneIdx;
 }
 if (heap->at(idxToSwap) < heap->at(currentIdx)) {
 swap(currentIdx, idxToSwap, heap);
 currentIdx = idxToSwap;
 childOneIdx = currentIdx * 2 + 1;
 } else {
 return;
 }
 }
 }
 // O(log(n)) time | O(1) space
 void siftUp(int currentIdx, vector<int> *heap) {
 int parentIdx = (currentIdx - 1) / 2;
 while (currentIdx > 0 && heap->at(currentIdx) < heap->at(parentIdx)) {
 swap(currentIdx, parentIdx, heap);
 currentIdx = parentIdx;
parentIdx = (currentIdx - 1) / 2;
 }
 }
 int peek() { return heap[0]; }
 // Remove
 void remove() {
 swap(0, heap.size() - 1, &heap);
 heap.pop_back();
 siftDown(0, heap.size() - 1, &heap);
 }
 void insert(int value) {
 heap.push_back(value);
 siftUp(heap.size() - 1, &heap);
 }
 void swap(int i, int j, vector<int> *heap) {
 int temp = heap->at(j);
 heap->at(j) = heap->at(i);
 heap->at(i) = temp;
 }
};

int main(){
	vector<int> vec = {
//		 0  ,3  ,9  ,39  ,5  ,2  ,13  ,11,  7,  1,  49,  59
//		//3,1,9,5,7,11, 13,2,0,39,49,59
	};
	
	MinHeap heap(vec);
	
     heap.insert(3);
     heap.insert(1);
     heap.insert(9);
     heap.insert(5);
     heap.insert(7);
	 heap.insert(2);
     heap.insert(0);
     heap.insert(11);
    heap.insert(13);

    heap.insert(39);
    heap.insert(49);
    //heap.insert(59);
	
	while(!heap.IsEmpty()){
	    //cout << " " << heap.remove() << " ";
		cout << " " << heap.peek()   << " ";
		heap.remove();
	}
}

 // Heap Construction

//#include <iostream>
//#include <vector>
//
//
//// Node = i
//// left child = 2i + 1
//// right child = 2i + 2
//// Parent Node (i-1 /2)
//
//
//class MinHeap{
//public:
//     MinHeap(std::vector<int>& vector){
//          heap = vector;
//     }
//
//     void BuildHeap () {
//         if(IsEmpty())
//             return;
//
//         int parentIdx = LastIndex() -1 / 2;
//         std::cout << "Parent Idx : " << parentIdx;
//
//         for (int  i = parentIdx ; i >= 0 ; i--)
//             SiftDown(i , LastIndex() , heap);
//     }
//
//     void Insert (const int data) {
//         heap.push_back(data);
//         SiftUp(LastIndex() , heap);
//     }
//
//     void Delete(){
//         if(heap.empty())
//             return;
//
//         Swap(heap.at(0) , heap.at(LastIndex()));
//         heap.pop_back();
//         SiftDown( 0 , LastIndex() , heap);
//     }
//
//
//
//     int peek(){
//         if(!heap.empty())
//           return heap[0];
//         return -1;
//     }
//
//     bool IsEmpty() {
//         return heap.empty();
//     }
//private:
//    std::vector<int> heap;
//
//// Node = i
//// left child = 2i + 1
//// right child = 2i + 2
//// Parent Node (i-1) /2) floor
//
//    void SiftUp (int currentIndex , std::vector<int>& vector) {
//        int parentIdx = (currentIndex - 1) / 2; // floor
//
//        // we have to go bottom to top
//        while (currentIndex > 0 && heap.at(currentIndex) < heap.at(parentIdx)){
//            Swap(heap.at(currentIndex)  , heap.at(parentIdx));
//            currentIndex = parentIdx;
//            parentIdx = (currentIndex - 1) / 2; // floor
//        }
//    }
//
//    void SiftDown (int currentIndex , const int lastIndex , std::vector<int>& vector) {
//        SiftDownHelper(currentIndex , (currentIndex*2) +1 , (currentIndex*2) + 2 , lastIndex , vector);
//    }
//
//    int LastIndex() const { return heap.size() - 1;}
//
//    void Swap (int& val1 , int& val2){
//        int temp = val1;
//        val1 = val2;
//        val2 = temp;
//    }
//
//    void SiftDownHelper(int currentIdx , int leftChildIdx, int rightChildIdx , const int lastIdx , std::vector<int>& vector){
//        if(leftChildIdx > lastIdx && rightChildIdx > lastIdx)
//            return;
//
//        leftChildIdx = (leftChildIdx > lastIdx)   ? -1 : leftChildIdx;
//        rightChildIdx = (rightChildIdx > lastIdx) ? -1 : rightChildIdx;
//
//        // Here -1 is flag that represent NULL
//        int midIdx;
//
//        // checks if any of one is not null and find idx of min value
//        if(leftChildIdx != -1 && rightChildIdx != -1 )
//            midIdx = vector[leftChildIdx] < vector[rightChildIdx] ? leftChildIdx : rightChildIdx;
//        else midIdx = (leftChildIdx == -1) ? rightChildIdx : leftChildIdx;
//
//        // Swap if currentIdx value is not under min idx
//        if(vector[currentIdx] > vector[midIdx])
//          Swap(vector[midIdx] , vector[currentIdx]);
//
//        currentIdx = midIdx;
//
//        SiftDownHelper(currentIdx , (2*currentIdx) +1 , (2*currentIdx) +2 , lastIdx , heap);
//    }
//};
//
//// Driver Code
//int main () {
//     std::vector<int> vec {
//         3,1,9,5,7
//     };
//
//     MinHeap heap(vec);
//     heap.Insert(3);
//     heap.Insert(1);
//     heap.Insert(9);
//     heap.Insert(5);
//     heap.Insert(7);
//
//     while(!heap.IsEmpty()){
//         std::cout << heap.peek() << " ";
//         heap.Delete();
//     }
//}
//
