#include<iostream>

using namespace std;

// Circular Linked List
class Node{
  public:
     int data;
     Node *next;
};

class LinkedList{
  public:
  LinkedList(){
    head = nullptr;
    tail = nullptr;
  }
   
  void Push(int data){
    if(head == nullptr){
       head = new Node{data , nullptr};
       tail = head;
       return;
    }
    
     Node* newNode = new Node{data,head};
     head = newNode;
    
  }
  
  void Pop(void){
   if(head == nullptr) return;
   Node* itr = head;
   if(itr->next == nullptr){
    delete head;
    delete tail;
    head = tail = nullptr;
    return;
   }
   while(itr->next->next != nullptr)
       itr =  itr->next;
    
    Node* temp = itr->next;
    itr->next = nullptr;
    
    tail = itr;
    tail->next = head;
    
    delete temp;  
  }
  
  void Itr(void){
    if(head == nullptr) return;
    Node* itr = tail;
    while(itr->next != tail){
      cout << " "<<itr->data <<" ";
      itr = itr->next;
    }
    
  }
  private:
    Node* head , *tail;
};


int main () {
  LinkedList ll;
  ll.Push(3);
  ll.Push(1);
  ll.Push(9);
  ll.Push(5);
  ll.Push(7);
  ll.Pop();
  ll.Itr();
}