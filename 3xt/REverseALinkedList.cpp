#include<iostream>
#include<vector>
#include<algorithm>
#include<valarray>
#include<functional>
// Node
class Node{
	public:
		int data;
		Node * next;
};

template<class ReturnType , class... Argu> 
class Event{
	public:
		Event(){
			funcList.clear();
		}
		
		void Invoke(Argu... params){
			if(funcList.empty())
			   return;
			   
			for(auto func:funcList)
			   func(params...);   
		}
		
		void operator += (std::function<ReturnType(Argu...)> func){
			funcList.push_back(func);
		}
		
	private:
		std::vector<std::function<ReturnType(Argu...)>> funcList;
};

// LinkedList
class LinkedList{
	public:
		
		// constructor
		LinkedList (){
			head = nullptr;
		}
		
		// Pushs Element on the top
		void Push ( const int data ){
			Node* newNode = new Node {data , nullptr };
			newNode->next = head;
			head = newNode;
			OnDataInsert.Invoke(data);
		}
		
		// Reverses a linked list
		void Reverse( Node* head){
			if(head == nullptr)
			   return;
			 Reverse(head->next);
			 std::cout << " " << head->data << " ";  
		}
		
		// prints linked list
		void Print (Node* head) {
			if(head == nullptr)
			   return;
			std::cout << " " << head->data  <<  " ";
			Print(head->next);   
		}
		
		Node* head;
		Event<void,int> OnDataInsert;
};

// Merge Sort
void MergeSort(int leftIdx , int rightIdx , const int SIZE , int arr[]){
	if(leftIdx >= rightIdx)
	  return;
	 
	int midIdx = (leftIdx + rightIdx) / 2;
	
	MergeSort(leftIdx , midIdx , SIZE , arr);
	MergeSort(midIdx +1 , rightIdx , SIZE , arr);  
	// Do Merge !Helper
}

// Driver Code
int main () {
	LinkedList list;
	list.OnDataInsert += [&](int data){	std::cout << " " << data << " "; };
	
	list.Push(3);
	list.Push(1);
	list.Push(9);
    list.Push(5);
	list.Print(list.head);
	std::cout << "\n";
	list.Reverse(list.head);
	
//	std::vector<int> list;
	
	
	
//	list.push_back(3);
//	list.push_back(1);
//	list.push_back(9);
//	list.push_back(5);
//	
//	std::for_each(list.begin() , list.end() , [&] (int data){
//	    	std::cout << " " << data << " ";
//	});
//	
//	std::valarray<int> valArray;
	
}