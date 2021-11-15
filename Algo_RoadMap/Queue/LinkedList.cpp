#include<iostream>
using namespace std;

template<typename T>
class Node{
  public:
  	T data;
  	Node* next;
};

template<typename T>
class LinkedList{
	public:
		// Constructor
		LinkedList(){
			head = new Node<T>();
			head = NULL;
		}
		
		// Push Front
		void Push_Front(T data){
			Node<T>* newNode = new Node<T>();
			newNode->next = NULL;
			newNode->data = data;
			
			if(head == NULL){
				head = newNode;
				return;
			}
			
			newNode->next = head;
			head = newNode;
		}
		
		// Push Back
		void Push_Back(T data){
			Node<T>* newNode = new Node<T>();
			newNode->next = NULL;
			newNode->data = data;
			
			if(head == NULL){
				head = newNode;
				return;
			}
			
			if(head->next  ==  NULL){
				head->next = newNode;
				return;
			}
			
			Node<T>* lastNode = head;
			
			while(lastNode->next != NULL)
			   lastNode = lastNode->next;
			   
			lastNode->next = newNode;
			return;
		}
		
        // Delete
		bool DeleteWhere(T data){
			if(head == NULL) return false;
			
			Node<T>* itr =head;
			
			if(head->next == NULL && head->data == data){
				head = NULL;
				return true;
			}
			
			while(itr != NULL){
				if(itr->next->data == data){
					itr = itr->next->next;
					return true;
				}
				itr = itr->next;
			}
			return false;
		}
		
		// ForEach
		template<class Func>
		void ForEach(Func CallBack){
			Node<T>* itr = head;
			
			while(itr != NULL){
				CallBack(itr->data);
				itr = itr->next;
			}
			return;
		}
		
		
	private:
		Node<T>* head;
};

// Driver Code
int main(){
	LinkedList<int> ls;
	ls.Push_Back(3);
    ls.Push_Back(1);
	ls.Push_Front(1);
    ls.Push_Back(9);
    ls.Push_Back(5);
    ls.Push_Back(7);
    
    ls.ForEach([](int data){
    	cout<< " "<<data<< " ";
	});
	cout<<endl;
	
	ls.Push_Front(3);
	ls.Push_Front(9);
	ls.Push_Front(5);
	ls.Push_Front(7);
	
	ls.ForEach([](int data){
    	cout<< " "<<data<< " ";
	});
	cout<<endl;
	
	ls.DeleteWhere(9);
	
	ls.ForEach([](int data){
    	cout<< " "<<data<< " ";
	});
	cout<<endl;
}