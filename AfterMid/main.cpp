#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <map>
#include<regex>

// SOLID
// Single Responsibility principle
// open close principle
// liskov substitution principle
// interface segregation principle
// dependency inversion

// using namespace


// Solid
// Single Responsibility
// open-close
// liskov substitution
// interface segregation
// dependency inversion

class Data{
public:
   int data;

};



std::vector<std::string> find_Duplicate(std::string ss){
    std::vector<std::string> res;
    std::map<char , int> table;

    for(const auto &c :ss)
        table[c]++;

   for(auto itr = table.begin() ; itr!= table.end() ; itr++){
       if(itr->second > 1){
           std::string  ss ;
           ss+=itr->first;
           res.push_back(ss);
       }
   }

    return res;
}

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


    int rightIndent = 9;

    for(int i=0; i < 10; i++) {
        for (int j = 0; j < 10; j++)
            if (i == j || j == rightIndent && i != rightIndent)
                std::cout << "*";
            else std::cout << " ";
        rightIndent--;
            std::cout <<"\n";
    }

//    __asm{
//        MOV DX , 3
//        MOV AH ,2
//        INT 21H
//    }



    for(int i=0 ;i <5; i++){
        for(int j =0 ; j<i ;j++)
            std::cout<<"*";
        std::cout<<"\n";
    }


   for(auto i : find_Duplicate("myname")){
       std::cout << i <<std::endl;
   }

}


#include <typeinfo>


/*
 * Move the first letter of each word to the end of it, then add "ay" to the end of the word. Leave punctuation marks untouched.
:-
  Examples:-
          pigIt('Pig latin is cool'); // igPay atinlay siay oolcay
          pigIt('Hello world !');     // elloHay orldway !


 // Oay emporatay oay oresmay !
 O emporatay o oresmay !
 */

std::string pig_it_Helper(std::string str){
    if(str.length() <= 1 && !isalpha(str[0]))
        return str;

    std::string ss;

    for(size_t i=0 ; i <str.length() ; i++)
        if(i != 0 ) ss.push_back(str[i]);
    ss.push_back(str[0]);
    return ss + "ay";
}

std::string pig_it(std::string str){
    std::string res;

    std::vector<std::string> vec;

    std::string tempStr;

    // Converts into sub strings
    for(size_t i = 0 ; i<str.length() ; i++){
        if(str[i] == ' '){
            if(!tempStr.empty())
                vec.push_back(tempStr);
            tempStr=""; // reset back to null
        }else tempStr.push_back(str[i]);
    }

    if(!tempStr.empty())
        vec.push_back(tempStr); // copy remaining string

    for(size_t i =0 ; i < vec.size() ; i++)
        res += pig_it_Helper(vec[i]) +((i != vec.size() -1) ? " " : "");

    return res;

}


/*
 expected 'uutnlwCIDFgaeZMBway . hcahKIpdlhigCwCmYKQay lFfZfUWRUJPZOQEuwUay ? HMyxDdrEpay bfvBTay WGiaTwhgSxMPOay XFunay eHfay undefineday fqay ! aBygJlFAKUray QACuGbrJqVhrGKJzay undefineday NuyAMnUTtay mbcNhhUNFay' to equal 'uutnlwCIDFgaeZMBway . hcahKIpdlhigCwCmYKQay lFfZfUWRUJPZOQEuwUay ? HMyxDdrEpay bfvBTay WGiaTwhgSxMPOay XFunay eHfay fqay ! aBygJlFAKUray QACuGbrJqVhrGKJzay NuyAMnUTtay mbcNhhUNFay'


 */

/*
 * std::string pig_it_Helper(std::string str){
     if(str.length() <= 1 && !isalpha(str[0]))
        return str;

    std::string ss;

    for(size_t i=0 ; i <str.length() ; i++)
        if(i != 0 ) ss.push_back(str[i]);
    ss.push_back(str[0]);
    return ss + "ay";
}

std::string pig_it(std::string str){
    std::string res;

    std::vector<std::string> vec;

    std::string tempStr;

    // Convert into sub strings
    for(size_t i = 0 ; i<str.length() ; i++){
        if(str[i] == ' '){
            if(!tempStr.empty())
                vec.push_back(tempStr);
            tempStr=""; // reset back to null
        }else tempStr.push_back(str[i]);
    }

    if(!tempStr.empty())
        vec.push_back(tempStr); // copy remaining string

    for(size_t i =0 ; i < vec.size() ; i++)
        res += pig_it_Helper(vec[i]) +((i != vec.size() -1) ? " " : "");

    return res;
}
 */



/*
 *            3
 *           /\
 *          1  9
 *            /\
 *           5  7
 */


/*
 *
 * #include <string>
#include <regex>
using namespace std;
string pig_it(string Z) {
    regex reg(("(\\w)(\\w*)(\\s|$)"));
    return regex_replace(Z, reg, "$2$1ay$3");
}
 */

/*
 #include<iostream>
#include<sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string pig_it(string str)
{

  string punctuation = "!.,:;?";
  string result = "";
  stringstream ss;
  ss << str;

  for (char ch; ss.get(ch);) { //read char and whitespace

    if (isspace(ch))
      result += ch;

    else {
      ss.putback(ch); //read a word from the stream
      string word;
      ss >> word;

      if (find(punctuation.begin(), punctuation.end(), word[0]) == punctuation.end()) {
        word.push_back(word[0]);
        word.erase(word.begin());
        word.push_back('a');
        word.push_back('y');
      }
      result += word;
    }
  }

  return result;
}
 */