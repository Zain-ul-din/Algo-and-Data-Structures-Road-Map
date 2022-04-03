//
// Doubly Linked List Construction
//

#include<iostream>

using namespace std;

///
/// DoublyLinkedList --Helper
///
class Node{
public:
    int data;
    Node* prev , *next;
};

///
/// Doubly Linked List Container
///
class DoublyLinkedList{
public:
    DoublyLinkedList(){
        head = nullptr;
        tail = nullptr;
    }

    // Inserts Node on top | Time Complexity O(1) constant
    void Push(const int data){
        Node* newNode = new Node{data , nullptr , nullptr};
        if(IsEmpty()){
          head = newNode;
          tail = newNode;
            return;
        }

        newNode->next = head;
        head->prev=  newNode;

        head = newNode;
    }

    // Inserts Element at the end | Time complexity O(1) Constant
    void Push_Back(const int data){
        Node* newNode= new Node{data , nullptr , nullptr};
        if(IsEmpty()){
            head = newNode;
            tail = newNode;
            return;
        }

        newNode->prev = tail;
        tail->next = newNode;

        tail = newNode;
    }

    // Inserts Data After Given Node | Time complexity , O(1) constant ! not dependencies included
    void Push_After(Node* node , const int data){
        if(node == nullptr)
            return;
        if(node->next == nullptr) // we're dealing with tail node
            return Push_Back(data);

        Node* newNode = new Node{data , nullptr , nullptr};

        newNode->next = node->next;
        newNode->prev = node;

        node->next->prev = newNode;
        node->next = newNode;

    }

    // Insert Data After Given Data | Time complexity , O(1) constant !  not dependencies included
    void Push_Before(Node* node , const int data){
       if(node == nullptr)
           return;

       if(node->prev == nullptr) // we're dealing  with head node
           return Push(data);

       Node* newNode = new Node{data , nullptr , nullptr};

       newNode->next = node;
       newNode->prev = node->prev;

        node->prev->next = newNode;
        node->prev = newNode;
    }

    // Finds Node with given data | Time complexity , Worst case : O(n) , Best Case : O(1) constant
    Node* FindNode(const int data) {
        if(IsEmpty())
            return nullptr;
        Node* itr = head;
        while(itr != nullptr)
            if(itr->data == data)
                return itr;
            else itr = itr->next;
        return nullptr;
    }

    // Delete Given Node | O(n) !  not dependencies included
    void DeleteNode(Node* node){
        if(node == nullptr || IsEmpty())
            return;

        if(node == head)
            head = head->next;
        if(node == tail)
            tail = tail->prev;

        if(node->next != nullptr)
            node->next->prev = node->prev;
        if(node->prev != nullptr)
            node->prev->next = node->next;

        delete node;
    }

    bool IsEmpty(){
        return head == nullptr && tail == nullptr;
    }

    // returns linked list contains given data or not | Time complexity , Worst case : O(n) , Best Case : O(1) constant
    bool IsContainNode(const int data){
        return FindNode(data) != nullptr;
    }

    // Display | Time Complexity O(n)
    void Display(){
        if(IsEmpty()){
            std::cout << "Empty !\n";
        }

        Node* itr =head;
        while (itr != nullptr){
            std::cout << " " << itr->data << " ";
            itr = itr->next;
        }
        std::cout << "\n";
    }
private:
    Node* head , *tail;
};


class CircularLinkedList{
public:
    // Circular LinkedList
    CircularLinkedList(){
        head = nullptr;
        tail = nullptr;
    }


    void Push(const int data){
        Node* newNode = new Node{data , nullptr , nullptr};
        if(IsEmpty()){
            head = newNode;
            tail = newNode;

            head->prev = tail;
            tail->next = head;
            return;
        }

        newNode->prev = head->prev;
        newNode->next = head;
        head->prev = newNode;
        head = newNode;

        tail->next = head;
    }

    void Push_Back(const int data){
        Node* newNode = new Node{data , nullptr , nullptr};
        if(IsEmpty()){
            head = newNode;
            tail = newNode;
            head->prev = tail;
            tail->next = head;
            return;
        }

        newNode->next = tail->next;
        newNode->prev = tail;
        tail->next = newNode;

        tail = newNode;

        head->prev = tail;
    }

    void Push_Before( Node* node, const int data){
        if(node == nullptr)
            return;

        if(node->prev = tail)
            return Push(data);

        std::cout << "Control Reach !";

        Node* newNode = new Node{data , nullptr , nullptr};

        newNode->next = node;
        newNode->prev = node->prev;

        node->prev->next = newNode;
        node->prev = newNode;
    }

    void Push_After(Node* node , const int data){
        if(node == nullptr)
            return;
        if(node->next == head)
            return Push_Back(data);


        Node* newNode = new Node{data , nullptr , nullptr};

        newNode->prev = node;
        newNode->next = node->next;

        node->next->prev = newNode;
        node->next = newNode;

    }

    Node* FindNode(const int data){
        if(IsEmpty())
            return nullptr;

        Node* itr = tail;

        do if(itr->data  == data)
                return itr;
           else itr = itr->prev;
        while (itr != tail);
        return nullptr;
    }

    void Delete(Node* node){
        if(node == nullptr)
            return;

        if(node == head)
            head = head->next;

        if(node == tail)
            tail = tail->prev;

       if(head->next == tail->next){
           head = nullptr;
           tail = nullptr;
       }

        if(node->next != nullptr)
            node->next->prev = node->prev;

        if(node->prev != nullptr)
            node->prev->next = node->next;

        delete node;
    }

    void Display(){
        if(IsEmpty())
            return;

        Node* itr = head;

        Debug();

        do{
           std::cout << " " << itr->data << " ";
           itr = itr->next;
        } while (itr != head);

        std::cout << "\n";
    }

    bool IsEmpty(){
        return head == nullptr && tail == nullptr;
    }

    void Debug(){
        if(head->prev == tail)
            std::cout << " head->prev Have tail !\n";
        else std::cout << "head->prev Have no tail\n";

        if(tail->next == head)
            std::cout << "tail->next  Have head !\n";
        else std::cout << "tail->next  Have no tail\n";
    }
private:
    Node *head , *tail;
};



int main () {
    DoublyLinkedList list;
    list.Push(3);
    list.Push_Back(9);
    list.Push_Before(list.FindNode(9) , 1);
    list.Push_After(list.FindNode(9) , 5);
    list.Push_Back(7);

    list.Display();

    list.DeleteNode(list.FindNode(5));
    list.DeleteNode(list.FindNode(3));
    list.DeleteNode(list.FindNode(1));
    list.DeleteNode(list.FindNode(9));
    list.DeleteNode(list.FindNode(7));

    list.Display();

    list.Push_Back(7);
    list.Push(3);
    list.Push_Back(9);
    list.Push_Before(list.FindNode(9) , 1);
    list.Push_After(list.FindNode(9) , 5);


    list.Display();

    std::cout << "\n Circular Linked List Demo \n";

    CircularLinkedList clist;

    clist.Push(3);
    clist.Push_Back(2);
    clist.Push_Back(9);
    clist.Push_After(clist.FindNode(3) , 1);
    clist.Push_Before(clist.FindNode(3) , 9);
    clist.Push_Back(5);
    clist.Push_Back(7);


    clist.Delete(clist.FindNode(3));
    clist.Delete(clist.FindNode(9));
    clist.Delete(clist.FindNode(1));
    clist.Delete(clist.FindNode(5));
    clist.Delete(clist.FindNode(7));
    clist.Delete(clist.FindNode(9));
    clist.Delete(clist.FindNode(2));

    clist.Display();
    clist.Push(3);
    clist.Push_Back(2);
    clist.Push_Back(9);
    clist.Push_After(clist.FindNode(3) , 1);
    clist.Push_Before(clist.FindNode(3) , 9);
    clist.Push_Back(5);
    clist.Push_Back(7);
    clist.Display();
}

