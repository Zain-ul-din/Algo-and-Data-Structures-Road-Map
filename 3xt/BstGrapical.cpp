



#include <iostream>
#include <vector>



class Node{
public:
    int data;
    Node* left , *right;
};



class BST{
public:
   BST(){
       root = nullptr;
   }

   void Insert(const int data){
       if(root == nullptr){
           root = new Node{data , nullptr , nullptr};
           return;
       }

       Node* itr  = root;
       while (true){
           if(data < itr->data){ // left
               if(itr->left == nullptr){
                   itr->left = new Node{data , nullptr , nullptr};
                   return;
               }
               else itr = itr->left;
           }
           else if(data > itr->data){ // right
               if(itr->right == nullptr){
                   itr->right = new Node{data , nullptr , nullptr};
                   return;
               }
               else itr = itr->right;
           }
           else{ //  Duplicate Check
               std::cout << "\nCan't Add Duplicate in BST \n";
               return;
           }
       }
   }


   void Display(Node* root){
       if(this->root == nullptr)
           std::cout << " \n Empty ! \n";

       if(root == nullptr)
           return;

       std::cout << " " << root->data << " ";

       Display(root->left);
       Display(root->right);
   }

  

   Node* GetNode(){
       return root;
   }
private:
    Node* root;

   
};

// Driver Code
int main (){
    
  
    BST bst;
    bst.Insert(3);
    bst.Insert(2);
    bst.Insert(7);
    bst.Insert(5);
    bst.Insert(10);
    bst.Insert(9);
    bst.Insert(8);
    bst.Insert(15);
    bst.Insert(30);

    bst.Display(bst.GetNode());
    
    std::vector<int> vec;
    system("pause");
    main(); 
    return 0;
}