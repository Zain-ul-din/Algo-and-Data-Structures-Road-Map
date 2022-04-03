#include<iostream>

class Node{
 public:
  int data;
  Node * next , * prev;
  
  void operator delete (void* size){
	free(size);
  }
};

// Driver Code

int main () {

   Node * node = new Node{ 3 , nullptr , nullptr };
   Node * ptr = node;

   delete node;
   
   // here node gets deleted from memory and ptr pointing to invalid memory address
   if(ptr->data)
      std::cout << "ptr is null \n";
   else std::cout << "ptr is not null !\n";
   return 0;
 }

 // OUTPUT : ptr is not null !