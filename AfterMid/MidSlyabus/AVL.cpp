#include "SaveSystem.h"




class Node{
public:
    int data;
    Node* left , *right;

    int Depth () {
        return std::max(this->LeftDepth() , this->RightDepth());
    }

    int LeftDepth () {
        if(!this->left)
            return 0;
        return this->left->Depth()+1;
    }

    int RightDepth () {
        if( this->right == nullptr)
            return 0;
        return this->right->Depth()+1;
    }

//    int Depth(){
//        int depth = 0;
//        Helper(this , depth);
//        return depth;
//    }
//private:
//
//    void Helper(Node* root ,int &res){
//        if(root == nullptr)
//            return;
//        root->GetDepth(res);
//        Helper(root->left , res);
//        Helper(root->right , res);
//    }
//    void GetDepth(int &res){
//        int left  = this->left ? 1  : 0;
//        int right = this->right ? 1 : 0;
//        res += std::max(left , right);
//    }
};

// Insert New Node
void InsertNode(Node* &root , const int data){
    if(!root){
        root = new Node{data , nullptr , nullptr};
        return;
    }

    Node* itr = root;

    while(true){
        if(data < itr->data)
           if(itr->left == nullptr) {
               itr->left = new Node{data , nullptr  , nullptr};
               return;
           }else itr = itr->left;
        else if(data  > itr->data)
            if(itr->right == nullptr) {
                itr->right = new Node{data , nullptr  , nullptr};
                return;
            }else itr = itr->right;
        else return;
    }
}

void NodeDepths(Node* root){
    if(root == nullptr)
        return;
    std::cout << " " << root->Depth() << " ";
    NodeDepths(root->left);
    NodeDepths(root->right);
}

using namespace Randoms;

class Data : public SaveSystem{
public:
    Data(int id, const std::string &name) : id(id), name(name) {
        Save();
    }

    void Save(){
        this->ToString(id ,name);
    }


private:
    int id;
    std::string name;
};

class Container : public IIterator{
public:
    void ForEach(std::function<void(SaveSystem &)> function) override {
           for(int i =0 ; i <newData.size(); i++){
               function(static_cast<SaveSystem&>(newData[i]));
           }
    }
    std::vector<Data> newData;
};

int main (){
    Node* root = nullptr;
    InsertNode(root , 3);
    InsertNode(root , 1);
    InsertNode(root , 9);
    InsertNode(root , 5);
    InsertNode(root , 7);
    NodeDepths(root);

    Container container;
    container.newData.push_back(Data{2, "Name"});
    container.newData.push_back(Data{25, "Name1"});
    container.newData.push_back(Data{22, "Name2"});
    container.newData.push_back(Data{24, "Name3"});
    container.newData.push_back(Data{23, "Name4"});

    SaveData("MyFile.text" , container);
}