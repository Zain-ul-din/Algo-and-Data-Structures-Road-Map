// Tree Construction

#include <iostream>
#include <string>
#include <algorithm>
#include <chrono>


using namespace std;


// Tree Node - __Helper
class Node{
public:
    int data;
    Node* right , *left;
};

// Non-Linear Data Structure
class Tree{
public:
    // Constructor
    Tree() {
        root = nullptr;
    }

    void Insert(int data){
       if(root == nullptr){
           root = new Node {data , nullptr , nullptr};
           return;
       }


    }


   void Display(){
       _Display()
    }
private:
    Node* root;

    void _Display(Node* root){
        if(root == nullptr)
            return;
        cout << "Root Val : " << root->data;
        if(root->left != nullptr)
            cout<< " Root Left Val  : "<<root->left->data << endl;
        if(root->right != nullptr)
            cout<< " Root Right Val : "<<root->right->data <<endl;

        _Display(root->left);
        _Display(root->right);
    }

    /*

     *   Root :-          Main Node have no Parent.

     *   Parent Node :-   Parent Node have at least one child.

     *   Child Node :-    All immediate successor of a node are its children.

     *   Siblings :-      Nodes with the same parent are called siblings .

     *   Leaf :-          Last Node in the tree . there is nothing after this.

     *   Non Leaf Node :- having at least one Node.

     *   Edge :-          Link between the nodes. It is a line between two nodes or a node and a leaf.

     *   Path :-          Sequence of consecutive edges from source node to destination node.

     *   Ancestors :-     Any predecessor on yhe path from root to node.

     *   Predecessor :-   Any Successor on the path from node to leaf.

     *   Degree :-        Total Number of child in tree is degree

     */
};

// Driver Code
int main (){
    Tree tree;
    int * num = new int (2);
    cout << *num << endl;
}

