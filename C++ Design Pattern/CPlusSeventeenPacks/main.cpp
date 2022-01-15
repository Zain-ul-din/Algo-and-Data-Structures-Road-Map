
/*
 * Py:- Delete N Node from the Doubly linked List
 * node
 * if head is node: head = head.next
 * if tail is node: tail = tail.prev
 *
 * if node->next is not None:
 *    node.next.prev = node.prev
 * if node->prev is not Node:
 *    node.prev.next = node.next
 *
 *    node = None
 */

//#include <istream>
//#include <typeinfo>
//int main();
//
//#if __cplusplus <= 201702L
//#define cplusplus
//#endif
//
//
//template<typename... T>
//void PROSPERITY(T... type){
//    ([=](auto t){
//     // u can do any thing here
//        std::cout << "Type : "<<sizeof (type) << "Byte \n";
//    }(type),...);
//}
//
//// c++ Macros
//
//
//int main() {
//
//#ifdef clpusplus
//   std::cout<<" C++ 17 :-) ";
//#endif
//
//    std::cout << "Hello, World!" << std::endl;
//    int num = 20; float f_Num = 0.34; std::string s_Num = "friend";
//    PARSERTYPEINFO(num  , f_Num , s_Num);
//    return 0;
//}

// Binary Search Tree (BST) Construction



//
///*
// * In Bst all val less then root Val going to be in left and greater going to be in right
// * All parent node will follow this rule which children are up to or 1
// *                           10
// *                     5            15
// *                2        5    13       22
// *                                 14
//*/
//#include<vector>
//class Node{
//public:
//    int value;
//    Node* left , *right;
//    ~Node(){
//        delete left;
//        delete right;
//    }
//};
//
//class BST{
//public:
//   BST() {
//       root = nullptr;
//   }
//
//   // Insertion in BST
//   void Insert(int val){
//       // First Case nothing in BST
//       if(root == nullptr){
//           root = new Node{val , nullptr , nullptr};
//           return;
//       }
//
//       Node* itrNode = root;
//       while(true){ // we are looking wrt to parent
//           if(val < itrNode->value){ // we have to move left
//               if(itrNode->left == nullptr){
//                   itrNode->left = new Node{val , nullptr , nullptr};
//                   return;
//               }else itrNode = itrNode->left; // Keep Searching
//           }else{ //  val is greater then Root
//               if(itrNode->right == nullptr){
//                   itrNode->right = new Node{val , nullptr , nullptr};
//                   return;
//               } else itrNode = itrNode->right; // Keep Searching
//           }
//       }
//   }
//   // Get Max Number Params : int  , int => max Number
//   int GetMaxNumber(int val , int val2){
//       return val > val2 ? val : val2;
//   }
//
//
//    bool Contains(int val){
//        if(root == nullptr) return false;
//        Node* itr = root;
//        while (itr != nullptr){
//            if(val < itr->value)
//                itr = itr->left; // look At left
//            else if(val  > itr->value)
//                itr = itr->right; // look At Right
//            else return true;
//        }
//        return false;
//
//    }
//
//   void Remove(int val){
//       if(root == nullptr) return;
//       if(root->right == nullptr && root->left == nullptr) {
//           delete root;
//           return;
//       }
//       Node* itr = root;
//       while (itr != nullptr){
//           if(val < itr->value)
//               itr = itr->left;
//           else if(val > itr->value)
//               itr = itr->right;
//           else{
//               // Node Found
//               if(itr->left == nullptr) {
//                   itr = itr->right;
//                   return;
//               } else{
//                   Node* findNode = *GetMinNode(&itr); //  Getting By Ref
//                   if(findNode == nullptr){
//                       delete itr;
//                       return;
//                   }
//                   itr->value = findNode->value;
//                   delete findNode;
//               }
//           }
//       }
//   }
//private:
//   Node* root;
//
//
//   Node** GetMinNode(Node** node){
//       Node* itr = *node;
//       if(itr->left == nullptr) return nullptr;
//
//       while(itr->left != nullptr){
//           itr = itr->left;
//       }
//
//       return &(itr);
//   }
//
//
//};

#include<iostream>
#include<sstream>
#include <string>
#include<algorithm>

using namespace std;
// Driver Code
int main (){
    // Main Re Define Define
    string name = "Fahad Hassan";
    replace(name.begin() , name.end() , ' ', '~');
    cout << name << "\n";

}

