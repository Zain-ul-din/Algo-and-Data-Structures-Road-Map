#include <iostream>
#include <cstring>

class Node{
public:
    int data;
    Node * next , * prev;
};

// Driver Code

int main () {

    Node *node = new Node{ 3 , nullptr , nullptr };
    Node *ptr = node;

    // setting memory to null
    memset(node, 0, sizeof(Node));
    delete node;
    // here node gets deleted from memory and ptr pointing to invalid memory address

    if(reinterpret_cast<char*>(ptr)[0] == '\0')
        std::cout << "ptr is null \n";
    else std::cout << "ptr is not null !\n";
    return 0;
}