// Linked List Quiz

#include<iostream>

using namespace std;


class Node{
public:
    int data;
    Node* next;
};

class LinkedList{
public:
    LinkedList() {
        head = nullptr;
        count = 0;
    }

    // Insert At Front
    void Push(int data){
        if(head == nullptr){
            head = new Node {data , nullptr};
            tail = new Node {data,head};
            count++;
            return;
        }

        Node* newNode = new Node{data , nullptr};
        newNode->next = head;
        head =  newNode;
        count++;
    }

    // Delete At Front
    void Pop(){
        if(head == nullptr) return;
        
        Node* itr = head;
        while(itr->next->next != nullptr)
       	    itr = itr->next;
	    
	
	    itr->next = nullptr;
	}
    // Node Count
    int Count(void){
        return count;
    }

    friend ostream & operator << (ostream& out , LinkedList ll){
        if(ll.head == nullptr){
            out << "Empty" <<endl;
            return out;
        }
        Node* itr = ll.head;

        while(itr != nullptr){
        	cout << " "<<itr->data <<" ";
        	itr = itr->next;
		}
        return out;
    }

private:
    Node* head;
    Node* tail;
    int count;
};

// Driver Code
int main () {
    LinkedList ll;

    int choice;
    cin>>choice;

    do{
        cout << "Push - 1" <<endl;
        cout << "Pop  - 2" <<endl;
        cout << "Enter Choice __ ";
        cin >> choice;
        if(choice == 1){
            int data;
            cout << "Enter Data __ ";
            cin >> data;
            ll.Push(data);
            cout << ll <<endl;
        }else if(choice == 2){
            ll.Pop();
            cout << ll <<endl;
        }
        cout<<"Number of Node = "<<ll.Count() <<endl;
        cout << "\n";
    }while(choice != 0);
}