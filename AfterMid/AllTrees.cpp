

#include <iostream>


// BST Construction


// BST Node
template<typename T>
class Node{
public:
    T data;
    Node<T> *left , *right;

    T GetMin() {
        if(this->left == nullptr)
            return this->data;

        Node<T>* itr = this->left;
        while (itr != nullptr){
            if(itr->left == nullptr)
                return itr->data;
            itr = itr->left;
        }
        return this->data;
    }

    void InvertNode(){
        if(this->left != nullptr && this->right != nullptr){
            auto* temp = this->left;
            this->left= this->right;
            this->right = temp;
        }
    }
};

template<typename T=int>
class BST{
public:
    BST(){
        root = nullptr;
    }

    // Insert
    void Insert(const T data){
        // Null Case
        if(root == nullptr){
            root = new Node<T>{ data, nullptr , nullptr};
            return;
        }

        Node<T>* itr = root;

        while(true){
            if(data <= itr->data){ // go left
                if(itr->left == nullptr) {
                    itr->left = new Node<T>{data, nullptr, nullptr};
                    return;
                }
                else itr = itr->left;
            }
            else{ //Right Case
                if(itr->right == nullptr){
                    itr->right = new Node<T> { data , nullptr , nullptr};
                    return;
                }
                else itr = itr->right;
            }
        }
    }

    bool InContains(const T data){
        Node<T> *itr = root;
        while (itr != nullptr){
            if(data < itr->data) // left side
                itr = itr->left;
            else if(data > itr->data) // right side
                itr = itr->right;
            else return true;
        }
        return false;
    }

    void Delete(const T data) {
        Node<T> *itr= root;
        Node<T> *parent = nullptr; // to keep track of parent

        while (itr != nullptr){
          if(data < itr->data) { // left side
              parent = itr;
              itr = itr->left;
          }
          else if(data > itr->data) { //right side
              parent = itr;
              itr = itr->right;
          }
          else return DeleteNode(itr , parent); // found
        }


    }

    void Display(){
        _Display(this->root);
    }

    void Invert(Node<T>* root) {
       if(root == nullptr)
           return;

        root->InvertNode();

        Invert(root->left);
        Invert(root->right);
    }

    Node<T>* GetRoot(){return root;}

private:
    Node<T>* root;


    // Helper
    void _Display(Node<T>* root){
        if(root == nullptr)
            return;

        std::cout << " "<< root->data << " ";

        _Display(root->left);
        _Display(root->right);
    }

    // Delete Node Helper
    void DeleteNode(Node<T>* node , Node<T>* parent){

        if(node->left == nullptr && node->right == nullptr) { // leaf node

            if(parent != nullptr){
                if(node->data <= parent->data)
                    parent->left = nullptr;
                else parent->right = nullptr;
            } else root = nullptr;

            delete node;

            return;
        }


        if(node->left == nullptr){ // left is null

          if(parent == nullptr){ // root node case
              root = root->right;
              delete node;
              return;
          }

          if(node->right->data <= parent->data)// insert left
              parent->left = node->right;
          else// insert at right
              parent->right = node->right;

          return;
        }

        if(node->right == nullptr){

            if(parent == nullptr) {
                root = root->left;
                delete node;
                return;
            }

            if(node->left->data <= parent->data) // insert at left side
                parent->left = node->left;
            else parent->right = node->left; // insert at right

            return;
        }

        // if none of the conditions match
        T minData = node->right->GetMin();
        Delete(minData);
        node->data = minData;
    }

    // Helper
    template<class CallBack>
    void _Traversel(Node<T>* root , CallBack callBack ) {
         if(root == nullptr)
             return;
         callBack(root->data);

        _Traversel(root->left);
        _Traversel(root->right);
    }

    // Helper
    template<class CallBack>
    void _InOrderTraversel(Node<T>* root , CallBack callBack) {
        if(root == nullptr)
            return;

        _InOrderTraversel(root->left , callBack);
        callBack(root->data);
        _InOrderTraversel(root->right , callBack);
    }

    // helper
    template<class CallBack>
    void _PreOrderTraversel(Node<T> *root , CallBack callBack) {
        if(root == nullptr)
            return;

        _PreOrderTraversel(root->left , callBack);
        _PreOrderTraversel(root->right , callBack);

        callBack(root->data);
    }
};



int main () {


    BST<int> bst;
    bst.Insert(3);
    bst.Insert(2);
    bst.Insert(7);
    bst.Insert(10);
    bst.Insert(9);
    bst.Insert(8);
    bst.Insert(15);
    bst.Insert(30);

    bst.Delete(7);

    bst.Display();
    std::cout <<"\n Invert BST :- \n";
    bst.Invert(bst.GetRoot());
    bst.Display();

    return 0;
}