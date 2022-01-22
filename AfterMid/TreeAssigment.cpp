/*
  * Name : Zain ul din
  * Roll no : 147
*/
#include <iostream>

// Node
class Node{
public:
    int data;
    Node *left , *right;
};

class BST{
public:
    // BST Construction

    BST();
    void  Insert(int data);
    bool  IsContain(int data);
    Node* GetRoot();
    void  Display(Node*);

    // Bst Assigment Questions

    int    SumOfBSTNodes();
    double Average();
    void   EvenNodes(Node*);
    void   MultipleOf3(Node*);
    void   StatusOfNodes();
    bool   IsValidBST();

private:
    Node* root;
    int   nodeCount;

    // Helper

    void  GetSumOfNodes(Node*, int&);
    void  NodeStatus_Helper(Node*);
    void  IsValidBstHelper(Node*, bool &);
};


int BST::SumOfBSTNodes() {
    int res = 0;
    GetSumOfNodes(root , res);
    return res;
}

double BST::Average() {
    double sumOfNodes = SumOfBSTNodes();
    return sumOfNodes / nodeCount;
}


void BST::EvenNodes(Node* root) {
    if(root == nullptr)
        return;

    if(root->data % 2 == 0)
        std::cout << " " << root->data << " ";

    EvenNodes(root->left);
    EvenNodes(root->right);
}

void BST::MultipleOf3(Node *root) {
    if(root == nullptr)
        return;
    if(root->data % 3 == 0 )
        std::cout << " " << root->data << " ";

    MultipleOf3(root->left);
    MultipleOf3(root->right);
}

void BST::StatusOfNodes() {
    return NodeStatus_Helper(root);
}

bool BST::IsValidBST() {
    bool isValidBST  = true;
    IsValidBstHelper(root , isValidBST);
    return isValidBST;
}

/// HELPER METHODS

// Helper
void BST::GetSumOfNodes(Node* root, int &res) {
    if(root == nullptr)
        return;
    res += root->data;

    GetSumOfNodes(root->left, res);
    GetSumOfNodes(root->right, res);
}

// Helper
void BST::NodeStatus_Helper(Node *root) {
    if(root == nullptr)
        return;

    if(root == this->root){
        std::cout << " " << "\tRoot : " << root->data << "\n";
        NodeStatus_Helper(root->right);
        NodeStatus_Helper(root->left);
        return;
    }

    if(root->left != nullptr || root->right != nullptr)
        std::cout << " " << "\tParent Node : "<<root->data <<"\n";

    if(root->right == nullptr && root->left == nullptr)
        std::cout << " "  << "\tLeaf Node  : "<<root->data  <<"\n";

    NodeStatus_Helper(root->right);
    NodeStatus_Helper(root->left);
}



// Helper
void BST::IsValidBstHelper(Node *root, bool &isValidBST) {
    if(!isValidBST)
        return;

    if(root == nullptr){
        isValidBST = true;
        return;
    }


    if(root->left != nullptr && !(root->left->data <= root->data))
        isValidBST = false;

    if(root->right != nullptr && !(root->right->data > root->data))
        isValidBST = false;

    IsValidBstHelper(root->left , isValidBST);
    IsValidBstHelper(root->right , isValidBST);
}



// BST Construction

BST::BST() {
    root = nullptr;
    nodeCount = 0;
}

void BST::Insert(int data) {
    if(root == nullptr){
        root = new Node{data , nullptr , nullptr};
        nodeCount++;
        return;
    }

    Node* itr = root;
    while (true){
        if(data <= itr->data){ // right
            if(itr->left == nullptr){
                itr->left = new Node{data , nullptr , nullptr};
                nodeCount++;
                return;
            }
            else itr = itr ->left;
        }
        else{
            if(itr->right == nullptr){
                itr->right = new Node{data , nullptr , nullptr};
                nodeCount++;
                return;
            }
            else itr = itr->right;
        }
    }
}

bool BST::IsContain(int data) {
    if(root == nullptr) return false;

    Node* itr = root;
    while (itr != nullptr){
        if(data < itr->data){
            itr = itr->left;
        }else if(data > itr->data){
            itr = itr->right;
        }
        else return true;
    }

    return false;
}


Node *BST::GetRoot() {
    return this->root;
}

void BST::Display(Node *root) {
    if(root == nullptr)
        return;
    std::cout <<" "<<root->data <<" ";
    Display(root->left);
    Display(root->right);
}

int main(){
    BST bst;
    // Time | O(n)
    bst.Insert(3);
    bst.Insert(1);
    bst.Insert(9);
    bst.Insert(5);
    bst.Insert(7);
    bst.Insert(8);

    // Display | O(n) Time
    std::cout << ">> BST Nodes :- ";
    bst.Display(bst.GetRoot());
    std::cout<<"\n";

    // IsContain Node | O(n) Time
    const int nodeToFind = 8;
    if(bst.IsContain(nodeToFind))
        std::cout <<  "\n>> BST Contains " << nodeToFind <<"\n";
    else std::cout << "\n>> BST doesn't Contains " <<nodeToFind <<"\n";

    // BST Nodes Sum  | O(n) Time
    std::cout << "\n>> BST Nodes Sum :- ";
    std::cout << bst.SumOfBSTNodes() << "\n";

    // Average | O(n) Time
    std::cout << "\n>> Average of BST Nodes :- ";
    std::cout << bst.Average() <<"\n";

    // Even Nodes in BST | O(n) Time
    std::cout << "\n>> Even Nodes in BST : ";
    bst.EvenNodes(bst.GetRoot());

    // Multiple of 3 | O(n) time
    std::cout << "\n\n>> Multiples of Three in BST : ";
    bst.MultipleOf3(bst.GetRoot());
    std::cout <<"\n";

    // BST Node Status | O(n) Time
    std::cout << "\n>> Status of BST Nodes :- \n";
    bst.StatusOfNodes();

    // Is Valid Bst  | O(n) Time
    std::cout << "\n>> IsValid BST ? ";
    if(bst.IsValidBST())
        std::cout << " _  Valid BST \n";
    else std::cout <<" _ InValid BST \n";
}

/*
 * OUTPUT:-

     >> BST Nodes :-  3  1  9  5  7  8

     >> BST Contains 8

     >> BST Nodes Sum :- 33

     >> Average of BST Nodes :- 5.5

     >> Even Nodes in BST :  8

     >> Multiples of Three in BST :  3  9

     >> Status of BST Nodes :-
        Root : 3
        Parent Node : 9
        Parent Node : 5
        Parent Node : 7
        Leaf Node  : 8
        Leaf Node  : 1

     >> IsValid BST ?  _  Valid BST
 */