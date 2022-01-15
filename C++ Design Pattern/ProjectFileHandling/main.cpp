#include<iostream>
#include <fstream>
#include <string>

using namespace std;


#define MAXSIZE 24
// Doubly Linked List in c++
#if __cplusplus 201103L

#define Hey

#else

#undef Hey

#endif


// Custom String Class
class String {
public:

    String(){
        _str = new char[MAXSIZE];
        length = MAXSIZE;
        itr = -1;
    }

    String(const size_t size) {

        _str = new char[size];
        length = size;
        itr = -1;
    }

    void Push_Back(const char c){
        if(itr >= length-1) return;
        itr++;
        _str[itr]  = c;
    }

    void Push_Top(const char c){
        if(itr >= length-1) return;
        itr++;
        for(int i=0;i<itr;i++)
            _str[i+1] = _str[i];
        _str[0] = c;
    }

    void operator = (string ss){
        itr = -1; // clear All Data Before
        for (int i = 0; i < ss.length(); i++)
            Push_Back(ss[i]);
    }

    void operator = (nullptr_t ptr){ itr = -1;}

    void operator += (string ss){ // Append Data to end
        for(int i=0;i<ss.length();i++)
            Push_Back(ss[i]);
    }



    friend ostream& operator << (ostream& out , String& ss){
        for(int i=0;i<ss.itr+1;i++)
            out<<ss._str[i];
        return out;
    }

    friend istream& operator >>(istream& in , String& ss){
        string str;
        in.sync();
        getline(in , str);
        in.clear();
        ss = str;
        return in;
    }

    bool IsEmpty() const {return itr == -1;}

    int Length() const {
        if(IsEmpty()) return 0;
        return itr+1;
    }

    char operator [] (const int index) const{
        if(IsEmpty() || index > itr) return ' ';
        return _str[index];
    }

    // Compare operator overLoading

    bool operator == (String &obj){
        if(this->length != obj.length)return false;
        if(this->Length() != obj.Length()) return false; // compare length
        for(int i=0 ; i < Length() ; i++)
            if(this->_str[i] != obj._str[i]) return false;
        return true;
    }


    ~String(){ delete _str;}

private: // private members
    char *_str;
    int length , itr;

};


#define ll long long

class Contact{
public:
    Contact(){
        userName = "UNSET";
        userContactNumber = 00000000000;
    }

    Contact(const String &userName, ll& userContactNumber) :
            userName(userName),
            userContactNumber(userContactNumber) {}




    // Getter Setter

    const String& getUserName() const { return userName;}
    const ll& getUserContactNumber() const { return userContactNumber;}

    void setUserName(const String &userName) { this->userName = userName;}
    void setUserContactNumber(ll userContactNumber) { this->userContactNumber = userContactNumber; }


    // operator over loading
    friend ostream& operator << (ostream& out , Contact& contact){

        out << "\n\t------------------------------------------------\n";
        cout<<"\tName : "<<contact.userName<<"\n";
        cout<<"\tContact Number : "<<contact.userContactNumber<<"\n";
        out << "\t------------------------------------------------\n";
        return out;
    }

    friend istream& operator >>(istream&  in ,Contact& contact){
        cout<<"Enter Name : ";
        in >> contact.userName;
        cout<<"Enter Contact Number : ";
        in >> contact.userContactNumber;
        return in;
    }

    //  compare

    // obj is Equal
    bool operator == (Contact& contact){
        return userName == contact.userName && userContactNumber == contact.userContactNumber;
    }

    // Obj_l is greater or equal to Obj_r
    bool operator >= (Contact& contact){
        if(this->userName == contact.userName)return true;
        // Compares 1st char
        if(IsLunderR(userName[0] , contact.userName[0])) return false;

        int minLength = (contact.userName.Length() < userName.Length()) ? contact.userName.Length() : userName.Length();

        for(int i=0 ; i <  minLength ; i++)
            if(IsLunderR(userName[0] , contact.userName[0])) return false;

        return true;
    }

    bool operator <= (Contact& contact){
        if(this->userName == contact.userName)return true;
        // Compares 1st char
        if(!IsLunderR(userName[0] , contact.userName[0])) return false;

        int minLength = (contact.userName.Length() < userName.Length()) ? contact.userName.Length() : userName.Length();

        for(int i=0 ; i <  minLength ; i++){
            if(!IsLunderR(userName[i] , contact.userName[i])) return false;
            cout<<userName[i] << " < "<<contact.userName[i]<<endl;
        }

        return true;
    }

private:
    String userName;
    ll userContactNumber;

    const char alphabet[26] = {
            'a' , 'b' , 'c' , 'd' , 'e' , 'f' , 'g' , 'h' , 'i' , 'j' , 'k' , 'l' , 'm' , 'n' , 'o' ,'p' ,
            'q' , 'r'  , 's' , 't' , 'u' , 'v' , 'w' , 'x' , 'y' ,'z'
    };

    const char Alphabet[26] = {
            'A' , 'B' , 'C' , 'D' , 'E' , 'F' , 'G' , 'H' , 'I' , 'J' , 'K' , 'L' , 'M' , 'N' , 'O' ,'P' ,
            'Q' , 'R'  , 'S' , 'T' , 'U' , 'V' , 'W' , 'X' , 'Y' ,'Z'
    };

    bool IsLunderR(char l  , char r) const{

        for(int i=0;i<26;i++){
            if(alphabet[i] == l || Alphabet[i] == l) return true;
            if(alphabet[i] == r || Alphabet[i] == r) return false;
        }
        return l <= r;
    }
};



// Helper Class
template<class T>
class Node{
public:
    T data;
    Node *prev , *next;
};

// Doubly Linked List
template<class T> class DLinkedList{
public:
    DLinkedList(void){
        head = nullptr;
        tail = nullptr;
    }

    // Push
    void Push(T& data){
        Node<T>* newNode = new Node<T>{data , nullptr , nullptr};

        // null case
        if(head == nullptr && tail == nullptr){
            head = newNode;
            tail = newNode;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    //Push Back
    void Push_Back(T& data){
        Node<T>* newNode = new Node<T>{data , nullptr , nullptr};

        // null case
        if(head == nullptr && tail == nullptr){
            head = newNode;
            tail = newNode;
            return;
        }

        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    // push's After a given Node
    void Push_After(Node<T>* node , T& data){

        // case Node is Last Element
        if(node->next == nullptr){
            Push_Back(data);
            return;
        }
        cout<<"I have Control"<<endl;
        Node<T>* newNode = new Node<T>{data , nullptr , nullptr};

        newNode->next = node->next;
        newNode->prev = node;

        node->next->prev = newNode;
        node->next = newNode;
    }

    // Push's Before a given Node
    void Push_Before(Node<T>* node , T& data){
        // case node is First Element
        if(node->prev == nullptr){
            Push(data);
            return;
        }

        Node<T>* newNode = new Node<T>{data , nullptr , nullptr};

        newNode->prev = node->prev;
        newNode->next = node;

        node->prev->next = newNode;
        node->prev = newNode;
    }

    /* Deletion From linkedList */

    // Deletes N Node
    void Remove(Node<T>* node){

        if(node == head) // Case first element
            head = head->next;
        if(node == tail) // Case last element
            tail = tail->prev;

        if(node->prev != nullptr)
            node->prev->next = node->next;
        if(node->next != nullptr)
            node->next->prev = node->prev;

        delete node;
    }

    // Delete's Top Node of LinkedList
    void Pop(void){
        if(IsEmpty()) return; // case no element's in linkedlist

        Node<T>* temp = head;

        head = head->next;
        head->prev = nullptr;

        delete temp;
    }

    // Delete's Last Node of LinkedList
    void RemoveFromLast(void){
        if(IsEmpty()) return;// case no element's in linkedlist

        Node<T>* temp = tail;

        tail = tail->prev;
        tail->prev = nullptr;

        delete temp;
    }

    // Search in Linked List
    Node<T>* IsContainNode(const T& matchData , bool startFromTail = false) const{
        if(IsEmpty())return nullptr; // Null Case

        // finds element in linked List starts from head
        if(!startFromTail){
            Node<T>* itr = head;
            while(itr != nullptr){
                if(itr->data == matchData) return itr;
                itr = itr->next;
            }
            return nullptr; // On Not Found
        }
            // finds element from the linkedlist starts from tail
        else{
            Node<T>* itr = head;
            while(itr != nullptr){
                if(itr->data == matchData) return itr;
                itr = itr->prev;
            }
            return nullptr;// On Not Found
        }
    }

    /* Utilities Functions */

    // returns linkedlist is empty
    bool IsEmpty() const{ return head == nullptr && tail == nullptr;}

    // returns linked List is contains element N
    bool Contains(const T& Data) const {return IsContainNode(Data);}

    // IO operator OverLoad Recommended
    void Display(void){
        if(IsEmpty())return;

        Node<T>* itr =head;
        while(itr!= nullptr){
            cout<<" "<<itr->data<<" "<<endl;
            itr = itr->next;
        }

        cout<<endl;
    }

    Node<T>* getHead() const {
        return head;
    }

    Node<T>* getTail() const {
        return tail;
    }

    void Save(){
        if(IsEmpty()) return;
        ofstream out;
        out.open("DataBase.text" , ios::out);
        Node* itr = head;
        while(itr != nullptr){
            out << itr->data.ToString() << "\n";
            itr = itr->next;
        }
        out.close();
    }

private:
    Node<T> *head , *tail;
};



template<class T>
class Priority_DLinkedList{
public:

    void Insert(T& data){
        if(linkedList.IsEmpty()){ // Null case
            linkedList.Push(data);
            return;
        }

        Node<T>* itr = linkedList.getHead();
        while(itr != nullptr){
            if(data <= itr->data){
                linkedList.Push_Before(itr , data);
                return;
            }
            itr = itr->next;
        }

        linkedList.Push_Back(data);
    }

    void Display(){
        linkedList.Display();
    }
private:
    DLinkedList<T> linkedList;
};

class Data{
public:
   static Data* GetData(){
        if(!isLoaded){ // loading data 1st time
            isLoaded = true;
            ifstream in;
            in.open("DataBase.dat" ,ios::in | ios::binary);
            if(is_Empty(in)){ // no data in file
                cout<<"Empty File"<<endl;
                return &(data);
                in.close();
            }
            in.read(reinterpret_cast<char *>(addressof(data)), sizeof (Data));
            in.close();
        }
        cout<<"return Data";
        return &(data);
    }

     void SaveData(){
        if(!isLoaded) return;
        ofstream out;
        out.open("DataBase.dat", ios::out | ios::binary);
        out.write(reinterpret_cast<const char*>(this) , sizeof(*this));
        out.close();
    }

    Priority_DLinkedList<Contact> contactList;
private:
    Data(){}
    static Data data;

    static  bool is_Empty(std::ifstream& pFile){return pFile.peek() == ifstream::traits_type::eof();}
    static  bool isLoaded ;
};

bool Data::isLoaded = false;
Data Data::data;

int main(){
    Data* data = Data::GetData();
    Contact contact;
    cin>>contact;
    data->contactList.Insert(contact);
    data->SaveData();
}