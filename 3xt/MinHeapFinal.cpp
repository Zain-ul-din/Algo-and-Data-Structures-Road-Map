#include<iostream>
#include<vector>

// Min Heap
class MinHeap{
public:
    MinHeap(){
    	heap.clear();
	}
   
private:
	std::vector<int> heap;
	
	void SiftUp(int Idx  , int heap){
		int parent = (idx - 1) / 2;
		
	}
};