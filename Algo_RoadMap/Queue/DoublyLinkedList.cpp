#include<iostream>
using namespace std;

template<typename T>
class Node{
	public:
		T data;
		Node* next,prev;
};

template<typename T>
class DLinkedList{
	public:
		DLinkedList(void){
			head = new Node<T>();
			head = NULL;
		}
		
		// Push Front
		void PushFront(T data){
			Node<T>* newNode = new Node<T>();
			newNode->next = NULL;
			newNode->prev = NULL;
			newNode->data = data;
			
			if(head == NULL){
				head = newNode;
				return;
			}
			
			
            // stack has been OverFlow	
		}
	private:
		Node<T>* head;
		
};