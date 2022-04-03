// Circular Linked List
#include<iostream>
using namespace std;

class Node{
  public:
    int data;
    Node *prev , *next;
    
    // Constructor
    Node(int newData){
     data = newData;
     prev = NULL;
     next = NULL;
    }  
};

// C LinkedList

class CLinkedList{
  public:
  
  // Constructor
  CLinkedList(){
   head = NULL;
   tail = NULL;
  }
  
  // Insert at front
  void Push(int data){
    Node* newNode = new Node(data);
    
    // if linked list have no data in it
    if( head == NULL && tail == NULL){
      head = newNode;
      tail = newNode;
      
      head->prev = tail; //  Sets head prev to tail
      tail->next = head; // sets tail next to head
      return;
    }
    
    // if linked list have data. ! even one node or more then
    
    // Sets new Node
    newNode->next = head;
    newNode->prev =  tail;
    
    // Sets head prev
    head->prev = newNode;
    head = newNode; // move head to newNode
    tail->next = head; // Set tail again
  }
  
  // Traversal
  void Display(){
    Node* temp = head;
    
    do{
      cout << temp->data; //  3 3
      temp = temp->next;
    }while(temp != head);
  }
  
  // Deletes given data
  void Delete(int data){
    Node* temp = head;
    
    do{
      if(temp->data == data){ // if given data matchs our data
        if(head == temp && tail == temp){ // if head and tail points to same node
          head = NULL;
          tail = NULL;
          delete temp;
          return;
        }
        
        // if temp node is head
        if(temp == head){
          head = head->next;
          head->prev = tail;
          tail->next = head; // set tail to points head again
          delete temp;
          return;
        }
      
        // tail case if node is tail   
        if(temp == tail){
          tail = tail->prev;
          tail->next = head;
          head->prev = tail; 
          delete temp;
          return;
        }
       
       
       // if element in center
       
       if(temp->prev != NULL)
         temp->prev->next = temp->next;
      
       if(temp->next != NULL)
         temp->next->prev = temp->prev;
       delete temp;
       return;
      }
      temp = temp->next; // tail->next (head)
    }while(temp != head); 
  }
  
  Node *head , *tail;
};

int main (){
  CLinkedList list;
  list.Push(3);
  list.Push(1);
  list.Push(5);
  list.Delete(3);
  list.Display();
  
  int  i  = 10;
  while(i < 20 , i++){
  	 std::cout << " " << i << " ";
  }
  
  return 0;
}