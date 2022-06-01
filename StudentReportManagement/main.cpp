
#include<iostream>

template<class T>
class Node {
public:
    Node (T& value) {
                this->value = value;
                this->prev = nullptr;
                this->next = nullptr;
    }
    T value;
    Node *prev , *next;
};

template<class T>
class LinkedList {
public:
    /// default constructor
    LinkedList() { head = nullptr ; tail = nullptr; }

    // Push
    void Push (T data) {
         Node<T> * newNode = new Node<T>(data);
         if (head == nullptr && tail == nullptr) {
               head = newNode;
               tail = newNode;
               return;
         }

         newNode->next = head;
         head->prev = newNode;
         head = newNode;
    }

    // Push_back
    void Push_Back (T data) {
         Node<T>* newNode = new Node<T>(data);
         if (head == nullptr && tail == nullptr) {
               head = newNode;
               tail = newNode;
               return;
         }

         newNode->prev = tail;
         tail->next = newNode;
         tail = newNode;
    }

    // Insert
    void Insert (Node<T>* node , T data) {
         if (node == nullptr) return;

         if(node == tail) {
             Push_Back(data);
             return;
         }

         Node<T>* newNode = new Node<T>(data);
         newNode->prev = node;
         newNode->next = node->next;
         node->next = newNode;
    }

    // Delete from top
    void Pop () {
                if (head == nullptr && tail == nullptr) return;
                if (head == tail) {
                     delete head;
                     head = nullptr;
                     tail = nullptr;
                     return;
                }

                Node<T>* auxiliary = head;
                head = head->next;
                delete auxiliary;
    }

    // Pop back
    void Pop_Back () {
                if (head == nullptr && tail == nullptr) return;
                if (head == tail) {
                            delete head;
                            head = nullptr;
                            tail = nullptr;
                            return;
                }

                Node<T>* auxiliary = tail;
                tail = tail->prev;
                delete auxiliary;
    }

    // Delete at specific pos
    void Delete (Node<T>* node) {
               if (node == head) head = head->next;
               if (node == tail) tail = tail->prev;

               if (node->next  != nullptr) node->next->prev = node->prev;
               if (node->prev  != nullptr) node->prev->next = node->next;

               delete node;
    }

    Node<T>* GetNode (int pos) {
            Node<T>* node = head;
            while (node != head)

    }
private:
    Node<T> *head , *tail;
};




int main () {

}