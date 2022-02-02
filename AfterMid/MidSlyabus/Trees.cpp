



#include <iostream>
#include <chrono>


class Node{
public:
    int data;
    Node* left , *right;

    int GetMinVal() const{
        Node* itr = this->right;

        while (itr != nullptr){
            if(itr->left == nullptr)
                return itr->data;
            itr = itr->left;
        }

        return this->right->data;
    }
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

   Node* FindNode(const int data){
       Node* itr = this->root;

       while (itr != nullptr){
           if(data < itr->data)
               itr = itr->left;
           else if(data > itr->data)
               itr = itr->right;
           else return itr;
       }
       return nullptr;
   }

   bool IsContainNode(const int data){
       return FindNode(data) != nullptr;
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

   void Remove(const int data){

       Node* itr = root;
       Node* parent  = nullptr; // to keep track of parent

       while (itr != nullptr){
           if(data < itr->data){
               parent = itr;
               itr = itr->left;
           }
           else if(data > itr->data){
               parent = itr;
               itr = itr->right;
           }
           else return RemoveHelper(itr , parent);
       }
   }

   Node* GetNode(){
       return root;
   }
private:
    Node* root;

   void RemoveHelper(Node* node , Node* parent){
       if(node->left == nullptr && node->right == nullptr) { // have no child or may be single root node
           if(parent == nullptr)
               root = nullptr;
           else{
               if(parent->left == node)
                   parent->left = nullptr;
               else parent->right = nullptr;
           }

           delete node;
           return;
       }

       if(node->left != nullptr && node->right != nullptr){ // none of the child nodes is not null
           int minVal = node->GetMinVal();
           this->Remove(minVal);
           node->data = minVal;

           return;
       }

       if(node->left == nullptr){ // left node is null
           if(parent != nullptr){ // if it's not root
               if(node->data < parent->data)
                   parent->left = node->right;
               else parent->right = node->right;
           }
           else root = root->right; // if it's root move root only

           delete node;
           return;
       }

       if(node->right == nullptr){ // right Node is null
           if(parent != nullptr){ // if it's not root
               if(node->data < parent->data)
                   parent->left = node->left;
               else parent->right = node->left;
           }
           else
               root = root->left; // if is root node move root


           delete node;
           return;
       }
   }
};

// Driver Code
int main (){
    // you're strongly encourage to change and play with Driver Code


    auto startTime = std::chrono::high_resolution_clock::now();
    // Add Code here


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

    bst.Remove(10);
    bst.Remove(3);
    bst.Remove(7);
    bst.Remove(15);
    bst.Remove(30);
    bst.Remove(2);
    bst.Remove(5);
    bst.Remove(9);
    bst.Remove(8);

    bst.Insert(1);
    std::cout << "\n After Deletion !\n";
    bst.Display(bst.GetNode());

    auto endTime = std::chrono::high_resolution_clock::now();
    auto timeTook = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

    std::cout << "\nTime Took : " <<timeTook.count() << " ms\n";

     return 0;
}

