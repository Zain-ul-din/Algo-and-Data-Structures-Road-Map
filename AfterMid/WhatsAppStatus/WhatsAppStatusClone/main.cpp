#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

//#include "Time.h"

using namespace std;

#define ll long long

class User;

template < class T > class Node;

template < class T > class Tree;


template<class T = User>
class Node{
public:
    T data;
    Node* left , *right;

    bool IsLeafNode(){return left == nullptr && right == nullptr;}

    // Find Min from Right
    Node<T>* GetMin (){
        Node<T>* itr = right;

        while(itr->left != nullptr)
            itr = itr->left;

        return itr;
    }
};

enum TraversalType{
    Simple , order , inorder , preorder
};

template<class T = User>
class Tree {
public:
    Tree(string& fileName , bool debug = false) {
        this->fileName = fileName;
        root = nullptr;
    }

    void Insert(T& data,bool saveData = true) {
          if(root == nullptr){
              root = new Node<T> {data , nullptr , nullptr};
              SaveData();
              count++;
              return;
          }

          Node<T>* itr = root;
          while(true) {
              if(data < itr->data){
                  if(itr->left == nullptr){
                      itr->left = new Node<T> {data , nullptr , nullptr};
                      count++;
                      return;
                  } else itr = itr->left;
              }
              else if(data > itr->data) {
                  if(itr-> right == nullptr) {
                      itr->right = new Node<T> {data , nullptr , nullptr};
                      count++;
                      return;
                  } else itr = itr->right;
              }
              else return;
          }
    }



    void Delete (Node<T> *node){
        if(root == nullptr)
            return;

        Node<T>* itr = root;
        Node<T>* parent  = nullptr;

        while (itr != nullptr) {
            if(node->data < itr->data){
                parent = itr;
                itr = itr->left;
            }
            else if(node->data > itr->data){
                parent = itr;
                itr = itr->right;
            }
            else return DeleteHelper(&node , parent); // found
        }
    }

    template<class CallBack>
    void ForEach(CallBack callBack , TraversalType type = TraversalType::Simple){
        switch (type) {
            case TraversalType::Simple:
                Traversal(root , callBack);
            break;
        }
    }

    int getCount() const {return count;}

    friend ostream &operator << (ostream& out , Tree<T> &tree){
        tree.ForEach([&](auto obj){
            out << obj << "\n";
        });
        return out;
    }


private:

    Node<T>* root;
    string fileName;
    int count;


private:



    void DeleteHelper(Node<T>** node , Node<T>* parent = nullptr){
        if((*node)->IsLeafNode()){
            Node<T>* temp = *node;
            delete temp;
            node = nullptr;
            return;
        }

        if((*node)->left != nullptr && (*node)->right != nullptr){
            (*node)->data = (*node)->GetMin();
            Delete((*node)->GetMin());
            return;
        }

        // root Node case
        if(parent == nullptr && node == root){
            root = (root->left == nullptr) ? root->right : root->left;
            delete *node;
            return;
        }

        if((*node)->left == nullptr) {
            if((*node)->right->data < parent->data)
                parent->left = (*node)->right;
            else
                parent->right = (*node)->right;

            Node<T>* temp = *node;
            delete temp;
            node = nullptr;

            return;
        }

        if((*node)->right == nullptr) {
            if((*node)->left->data < parent->data)
                parent->left = (*node)->right;
            else
                parent->right = (*node)->right;

            Node<T>* temp = *node;
            delete temp;
            node = nullptr;

            return;
        }

    }

    template<class CallBack>
    void Traversal(Node<T>* node , CallBack& callBack){
      if(node == nullptr) return;

        callBack(node->data);

        Traversal(node->left , callBack);
        Traversal(node->right , callBack);
    }

    void LoadData () {
        ifstream in;
        in.open(fileName , ios::in);
        if(in.peek() == ifstream::traits_type::eof()) //  file is empty
            return;
        while (!in.eof()){
            string ss;
            getline(in , ss , '\n');
            Insert(T::StringToUser (wstring(ss.begin() , ss.end())) , false );
        }
        in.close();
    }

    void SaveData () {
        ofstream out;
        out.open(fileName , ios::out);
        ForEach([&] (T& obj){
            stringstream ss;
            ss << obj.ToString().data();
            out << ss.str() << "\n";
        });
        out.close();
    }
};


// Whats App Status
class User{
public:

    // Constructor
    User() {
        userName = "Unknown";
        userNumber = 9999999999;
        filePath = L"Unknown";
    }


    User(string &userName, long long int userNumber, bool haveStatus , wstring &filePath) : userName(userName),
    userNumber(userNumber),
    haveStatus(haveStatus) , filePath(filePath) {}

    // Getter Setter

    const string &getUserName() const {
        return userName;
    }

    void setUserName(const string &userName) {
        User::userName = userName;
    }

    long long int getUserNumber() const {
        return userNumber;
    }

    void setUserNumber(long long int userNumber) {
        User::userNumber = userNumber;
    }

    const wstring &getFilePath() const {
        return filePath;
    }

    void setFilePath(const wstring &filePath) {
        User::filePath = filePath;
    }

    // Operator OverLoading

    bool operator == (const User& user){
        return this->userName == user.userName || this->userNumber == user.userNumber;
    }

    bool operator <= (const User& user) {
        return this->userName <= user.userName;
    }

    bool operator < (const User& user) {
        return this->userName <= user.userName;
    }

    bool operator > (const User& user) {
        return this->userName > user.userName;
    }

    bool operator >= (const User& user) {
        return this->userName > user.userName;
    }


    friend ostream &operator << (ostream& out , User& user){
        out << "\n" << "\tUserName   : " <<user.userName <<endl;
        out <<         "\tUserNumber : " <<user.userNumber <<endl;
        return out;
    }

    friend istream &operator >> (istream& in , User &user) {
        cout <<"\n" << "\tEnter User Name   : "; in.sync();
        getline(in , user.userName );
        cout        << "\tEnter User Number : ";
        cin >> user.userNumber;
        cout << "\n\t==================================================\n";
        cout << "\n\t\tDRAG AND DROP YOUR FILE HERE !\n";
        cout << "\n\t==================================================";
        in.sync();
        getline(wcin , user.filePath);
        cout << "\n\tFile Path Has Been Added ___ ";
        wcout << user.filePath << endl;
        return in;
    }

    static void playStatus(User& user){
        stringstream ss;
        ss << "\"" << string(user.filePath.begin() , user.filePath.end()) << "\"";
        system(ss.str().c_str());
    }

    wstring ToString() {
        stringstream ss;
        //  string ` number ` wstring ` bool status //  Writing format
        ss << userNumber << SEPARTOR << userNumber << SEPARTOR
           << filePath.c_str() << SEPARTOR << haveStatus;
        return wstring (ss.str().begin() , ss.str().end());
    }


    static User StringToUser(wstring ss) {
        vector<string> res = Split(ss);

        if(res.size() < NUMBEROFVAR)
            return User();

        //  string ` number ` wstring ` bool status //  Loading format

        User user;
        user.userName = res[0];
        user.userNumber = stoll(res[1]);
        user.filePath = wstring(res[2].begin() , res[2].end());
        user.haveStatus = res[3] == "1";

        return user;
    }

private:
    string userName;
    ll userNumber;
    wstring filePath;
    bool haveStatus;

    static const char SEPARTOR = '`';
    static const unsigned int NUMBEROFVAR = 4;

    static vector<string> Split(wstring ss) {
        vector<string> vec;
        string temp;

        for(int i = 0 ; i < ss.length() ; ++i )
            if(ss[i] == SEPARTOR ){
                vec.push_back(temp);
                temp = "";
            }  else temp += ss[i];

        return vec;
    }
};





int main() {
    User user;
    cin >> user;
    User::playStatus(user);
    string fileName = "Name.text";
    Tree<User> tree(fileName);
    tree.Insert(user);
}
