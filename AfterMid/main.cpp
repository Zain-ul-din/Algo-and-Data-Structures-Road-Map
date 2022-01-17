#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>


// Trees
class Node{
public:
    int data;
    Node* left , *right;
};


class Tree{
public:
      Tree(){
          root = nullptr;
      }

      // Insert Data
      void Insert(int data) {
          if(root == nullptr){
              root = new Node{data , nullptr , nullptr};
              return;
          }

          Node* itr = root;

          while (true){
              if(data <= itr->data){
                  if(itr->left == nullptr){
                      itr->left = new Node{data , nullptr , nullptr};
                      return;
                  }
                  else itr = itr->left;
              }
              else{
                  if(itr->right == nullptr){
                      itr->right= new Node{data , nullptr , nullptr};
                      return;
                  }
                  else itr = itr->right;
              }
          }
      }

      // Is Contain Node
      bool IsContain(int data){
          if(root == nullptr) return false;

          Node* itr = root;

          while (itr  != nullptr){
              if(data < itr->data)
                  itr = itr->left;
              else if(data > itr->data)
                  itr = itr->right;
              else return true;
          }

          return false;
      }

      void Display(){
          Debug(root);
      }

      void Delete(int data){
          if(root == nullptr)
              return;


          if(root->left == nullptr && root->right == nullptr){
              delete root;
              return;


          }

          Node* itr = root;
          while(itr!= nullptr){
              if(data < itr->data){
                  itr = itr->left;
              }
              else if(data > itr->data){
                  itr = itr->right;
              }
              else{
                 // Delete on Match
                 itr->data = GetMin(itr);
              }
          }
      }

     // traversal
     void Traversal(){
         _InOrderTraversel(root);
      }

      int GetMin(Node* node){
          Node* itr = node;
          while(node->left != nullptr){
              itr = itr->left;
          }

          int data = itr->data;
          delete itr;
          return data;
      }
private:
    Node* root;

    void Debug(Node *root){
        if(root == nullptr)
            return;

        std::cout<< " " << root->data << " ";

        /*
        if(root->left != nullptr)
            std::cout <<" " << root->left->data << " ";
        if(root->right != nullptr)
            std::cout << " "<< root->right->data << " ";
        */

        if(root->left == nullptr)
            std::cout <<" " << "L" << " ";
        if(root->right == nullptr)
            std::cout << " "<< "R" << " ";

        Debug(root->left);
        Debug(root->right);

        //  3  1  9  5  7
    }

    void _InOrderTraversel(Node* rootNode) {
        if(rootNode == nullptr)
            return;
        _InOrderTraversel(rootNode->left);
        std::cout << " " << rootNode->data << " ";
        _InOrderTraversel(rootNode->right);
    }
};

std::string to_camel_case(std::string text) {
    // TODO: Your code goes here!
    std::string  res;

    for(int i=0 ; i < text.length() ; i++)
        if(text[i] == '-' || text[i] == '_') {
            i++;
            res.push_back(toupper(text[i]));
        }
        else res.push_back(text[i]);

    return res;
}

/*
 * std::string to_camel_case(std::string text)
{
  for(int i = 0; i < text.size(); ++i)
  {
    if(text[i] == '-' || text[i] == '_')
    {
      text.erase(i,1);
      text[i] = toupper(text[i]);
    }
  }
  return text;
}
 */


/*
 std::string to_camel_case(std::string text)
{
  if (text.empty()) return text;

  static std::vector<char> const remove { '-','_' };

  for (auto i = 0; i < text.length();++i) {
    auto current = text[i];
    if (std::find(remove.begin(), remove.end(), current) != remove.end()) {
      text.erase(i, 1);
      text[i] = toupper(text[i]);
    }
  }
  return text;
}
 */

int digital_root(int n)
{
    std::string ss = std::to_string(n);
    int res =0 ;
    for(const char & num : ss){
        std::stringstream sss;
        sss << num;
        int i_num ;
        sss >> i_num;
        res += i_num;
    }
    return res;
}


/*
 *
 * int digital_root(int Z) {
    return --Z % 9 + 1;
}


 */

// 77


#include <vector>

template <typename T> std::vector<T> uniqueInOrder(const std::vector<T>& iterable){
    std::vector<T> res;
    for(int i=0 ; i <iterable.size() ; i++)
        if(iterable[i] == iterable[i+1] && i+1 != iterable.size() && std::find(res.begin() ,res.end() , iterable[i]) != res.end())
            res.push_back(iterable[i]);
    return res;
}

std::vector<char> uniqueInOrder(const std::string& iterable){
    std::vector<char> res;
    for(int  i= 0 ; i <iterable.length(); i++)
        if(iterable[i] == iterable[i+1] && i+1 != iterable.length() && std::find(res.begin() ,res.end() , iterable[i]) != res.end())
            res.push_back(iterable[i]);
    return res;
}



int main() {
    Tree tree;
    tree.Insert(3);
    tree.Insert(1);
    tree.Insert(9);
    tree.Insert(5);
    tree.Insert(7);

    //tree.Delete(9);

    std::cout << (tree.IsContain(5) ? "Have 5 = True" : "Have 5 : false") << "\n";

    tree.Display(); std::cout <<" \n";

    tree.Traversal();


    std::cout << "\n";
    to_camel_case("the_stealth_warrior");
    std::cout
            << digital_root(7)
            << "\n";















    __asm{

    }






}




/*
 *            3
 *           /\
 *          1  9
 *            /\
 *           5  7
 */