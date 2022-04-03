#include<iostream>
#include<vector>
#include<utility>

class MaxHeap{
	public:
	   MaxHeap(){
          heap.clear();	   	
	   }
	   
	   void Insert(const int data){
	   	 this->heap.push_back(data);
	   	 SiftUp(this->heap.size()-1 , this->heap);
	   }
	   
	   void Remove(){
	   	   if(IsEmpty())
	   	     return;
	   	  std::swap(heap[0] , heap[heap.size() - 1]);
	   	  this->heap.pop_back();
	   	  SiftDown(0 , 1 , 2 , heap.size() -1 ,  heap);
	   }
	   
	   int Peek(){
	   	 return (heap.empty()) ? -1 : heap[0];
	   }
	   
	   bool IsEmpty(){return this->heap.empty();}
	   
	   
	private:
		std::vector <int > heap;
	
	void SiftUp(int currentIdx , std::vector <int> &heap){
		int parentIdx = (currentIdx - 1) / 2; 
		while(currentIdx > 0 && heap[currentIdx] >= heap[parentIdx]){
			std::swap(heap[currentIdx]  , heap[parentIdx]);
			currentIdx = parentIdx;
			parentIdx = (currentIdx - 1) / 2;  
		}
	}
	
	void SiftDown(int currentIdx ,int leftIdx , int rightIdx , int maxIdx , std::vector<int> & heap){
		if(leftIdx > maxIdx && rightIdx > maxIdx) 
		   return;
		
		leftIdx  = (leftIdx > maxIdx) ? -1 : leftIdx;
		rightIdx = (rightIdx > maxIdx) ? -1 : rightIdx;
		
		// here '-1' represent null node
		int maxNumIdx;
		if(leftIdx != - 1 && rightIdx != -1)
		  maxNumIdx = ( heap[leftIdx] > heap[rightIdx]) ? leftIdx : rightIdx;
		else maxNumIdx = (leftIdx == -1) ? rightIdx : leftIdx;
		
		if(heap[maxNumIdx] > heap[currentIdx])
		  std::swap(heap[maxNumIdx] , heap[currentIdx]);
		else return;
		   
		currentIdx = maxNumIdx;
		SiftDown(currentIdx , (2*currentIdx) + 1 , (2*currentIdx) + 1 , maxIdx , heap );   
	}	
};

// Driver Code
int main (){
	MaxHeap heap;
	heap.Insert(3);
	heap.Insert(1);
	heap.Insert(9);
	heap.Insert(5);
	heap.Insert(7);
	
	while(!heap.IsEmpty()){
		std::cout << heap.Peek() << " ";
		heap.Remove();
	}

	heap.Insert(3);
	heap.Insert(1);
	heap.Insert(9);
	heap.Insert(5);
	heap.Insert(7);
	
	while(!heap.IsEmpty()){
		std::cout << heap.Peek() << " ";
		heap.Remove();
	}
}