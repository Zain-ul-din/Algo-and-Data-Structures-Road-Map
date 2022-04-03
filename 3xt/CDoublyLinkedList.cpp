#include<iostream>

class Node{
    public:
    int data;
    Node* prev , *next;
};

class CLinkedList{
    public:
        CLinkedList(){
            head = nullptr;
            tail = nullptr;
        }
        
        
        // Push Data to Top
        void Push(const int data){
                Node* node = new Node{data , nullptr , nullptr};
                
                // null case
                if(head == nullptr && tail == nullptr){
                  head = node;
                  tail = node;    
                  head->next = tail;
                  tail->prev = head;
                  return;
                }
                
                // if not null case
                node->next = head;
                node->prev = head->prev; // set tail
                
                head->prev = node;
                head = node;
                head->prev->next = head; // set head
        }
        
        void Push_Back(const int data){
        	Node* node = new Node{data , nullptr , nullptr};
			
			if(head == nullptr && tail == nullptr){
				head = node;
				tail = node;
				head->next = tail;
				tail->prev = head;
				return;
			}
			
			node->prev = tail;
			node->next = tail->next; // setting head
			
			tail->next = node;
			tail = node;
			tail->next->prev = tail; //set head again
		}
		
		
		
        void Display(){
            Node* itr = head;
            do{
                std::cout << " " << itr->data << " ";
                itr = itr->next;
            }while(itr != head);
        }
        
        void Delete(const int data){
        	Node* itr = head;
        	do{
        		if(itr->data == data)
        		   return RemoveHelper(itr);
        		else itr = itr->next;
			}while(itr != head);
		}
		
    private:
        Node* head , *tail;
        
        void RemoveHelper(Node* node){
        	if(node == tail && node == head){
        		delete node;
        		head = nullptr;
        		tail = nullptr;
        		return;
			}
			
			if(node == head){
				head = head->next;
				head->prev = tail;
				tail->prev->next = head;//reset tail
				return;
			}
			
			if(node == tail){
				tail  = tail->prev;
				tail->next = head;
				tail->next->prev = tail; // reset head
				return;
			}
			
			if(node->next != nullptr)
			   node->next->prev = node->prev;
			   
			if(node->prev != nullptr)
			   node->prev->next = node->next;   
		}
};


int main (){
    CLinkedList list;
    list.Push(3);
    list.Push(5);
    list.Push(9);
    list.Push(5);
    list.Push_Back(4);
    list.Push_Back(6);
    
    list.Delete(5);
    list.Delete(9);
    list.Delete(3);
    list.Delete(4);
    list.Delete(6);
   list.Display();
}