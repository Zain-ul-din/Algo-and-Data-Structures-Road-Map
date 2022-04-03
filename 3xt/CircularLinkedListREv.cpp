#include<iostream>


class Node{
	public:
	int data;
	Node * prev , *next;
};


class LinkedList {
	public:
		LinkedList (){
			head = nullptr;
			tail = nullptr;
		}
		
		void Push (int newData){
			Node* newNode = new Node{newData , nullptr , nullptr};
			if(head == nullptr && tail == nullptr){
				head = newNode;
				tail = newNode;
				head->prev = tail;
				tail->next = head;
				return;
			}
			
			newNode->next = head;
			head->prev = head->prev;
			
			head->prev = newNode;
			head = newNode;
			head->prev->next = head;
		}
		
		void Push_Back(int data){
			Node* newNode = new Node{data , nullptr , nullptr};
			if(head == nullptr && tail == nullptr){
				head = newNode;
				tail = newNode;
				head->prev = tail;
				tail->next = head;
				return;
			}
			
			newNode->prev = tail;
			newNode->next = tail->next;
			
			tail->next = newNode;
			tail = newNode;
			tail->next->prev = newNode;
		}
		
	private:
	  Node head , tail;	
};