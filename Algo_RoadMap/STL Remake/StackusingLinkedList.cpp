#include<iostream>
#include<stack>
using namespace std;


// FILO
template<typename T>
class LinkedList{
	public:
		LinkedList(T &garbageData){
			head = new Node();
			head = NULL;
		}
		
		void Push(T data){
			Node* newNode = new Node(data,NULL);
			if(head == NULL){
				head = newNode;
				return;
			}
			newNode->next = head;
			head = newNode;
			return;
		}
		
		void Pop(void){
			if(head == NULL) return;
			head = head->next;
		}
		
		T Peek(void){if(head == NULL) return ; return head->data;}
	private:
	// Link
	class Node{
	  public:
	  	Node(T data,Node* next){
	  	 this->data = data;
	  	 this->next = next;
		}
	    // var
	    T data;
	    Node* next;	
	};
		
	 Node* head;
	// Link
	
};

int main(){
	
}