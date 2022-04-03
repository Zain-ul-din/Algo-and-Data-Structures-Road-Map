#include <iostream>

using namespace std;

template<class T>
class Node{
public:
	T data;
	Node* prev , *next;
	
	Node(T d){
		data = d;
		prev = NULL;
		next = NULL;
	}
};

template<class T>
class DoublyLinkedList  {
   public:
   
   DoublyLinkedList(){
   	head = NULL;
   	tail = NULL;
   }
   
   void Insert(T data){
   	
   	  Node<T>* newNode = new Node<T>(data);
   	 // Null Case
   	 if(head == NULL && tail == NULL){
	   head = newNode;
	   tail = newNode;	
	   return;   	
	 }
	 
	 Node<T>* temp =head;
	 
	 while(temp->next != NULL)
	 	temp = temp->next;
	 	
	 temp->next = newNode;
	 newNode->prev = temp;
   }
   
   Node<T>* FindNode(T data){
   	    if(head == NULL && tail == NULL){
   	       return NULL;	
		}
		
		Node<T>* itr = head;
		
		while(itr != NULL){
		   if(itr->data == data)
		      return itr;
		    itr = itr->next;  
		}
		
		return NULL;
   }
   
   
   void Delete(Node<T>* node) {
       if(node == head)
       	  head = head->next;
	   
	   if(node == tail)
	   	 tail = tail->prev;
	   
	   
	   if(node->next != NULL)
	      node->next->prev = node->prev;
	    
		if(node->prev != NULL)
		   node->prev->next = node->next;
		   
		delete node;
   }
   
   void Display(){
   	 
   	 if(head == NULL && tail == NULL){
   	    cout << "\n Empty !\n";	
   	    return;
	 }
	 
	 Node<T> *itr = head;
	 
	 while(itr != NULL){
	 	cout << itr->data << endl;
	 	itr = itr->next;
	 }
   }
   private:
   Node<T>* head;
   Node<T>* tail;	
};

int main () {
	DoublyLinkedList<int> list;
	list.Insert(3);
	list.Insert(1);
	list.Insert(9);
	list.Insert(5);
	list.Insert(7);
	
	list.Delete(list.FindNode(1));
	list.Delete(list.FindNode(3));
	list.Delete(list.FindNode(9));
	list.Delete(list.FindNode(5));
	list.Delete(list.FindNode(7));
	
	list.Display();
}