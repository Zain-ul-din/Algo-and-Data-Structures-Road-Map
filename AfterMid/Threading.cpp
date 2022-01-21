/*
 * Contact Manager Console App
*/

#include<iostream>
#include<string>
#include<fstream>
#include<windows.h>
#include<sstream>
#include<iterator>
#include<algorithm>

using namespace std;


//#define FILENAME "DataBase.text"
#define NEVERMIND cout <<"\tNEVER MIND !\n";

static string FILENAME;

void frontpage()
{
    cout<<"==============================================================================="<<endl;
    cout<<"|                                                                             |"<<endl;
    cout<<"|                     WELCOME TO OUR CONTACT MANAGER                          |"<<endl;
    cout<<"|                                                                             |"<<endl;
    cout<<"==============================================================================="<<endl;

    cout<<"\n\n      CREATED BY:           BSCS (E)"<<endl<<endl;
    cout<<"                         M. Fahad Hassan (482)"<<endl;
    cout<<"                         Zain Ul Din     (147)"<<endl;
    cout<<"                         Hassan Raza     (238)"<<endl;
    cout<<"                         Umer Mahmood    (170)"<<endl;
    cout<<"                         Raheel Arshad   (159)"<<endl;

}

class Userid
{
public:
    char id[15];
    char name[10];
    char pass[8];

    Userid() = default;


    bool checkID()
    {
        if(id==id){
            cout<<"ID ALREADY EXISTS..."<<endl;
            return false;
        }
        else{
            return true;
        }
    }

    void Signup()
    {
        cout<<"Enter Your Front Name : ";cin>>name;
        cout<<"Enter Your ID (14 Char): ";cin>>id;
        cout<<"Enter Your Password (7 Char): ";cin>>pass;
    }

    void Displayid()
    {
        cout<<"ID: "<<id<<endl;
        cout<<"User Name: "<<name<<endl;
        cout<<"Pass: "<<pass<<endl;

    }
};

string nametofname(char c[],int count)
{
    string fileName;
    for(int i=0;i<count;i++)
    {
        fileName+= c[i];
    }
    fileName=fileName.c_str();
    fileName+=".txt";
    return fileName;
}
void saving(Userid &e)
{
    string nwfile;
    fstream file;
    fstream ax;
    file.open("Accounts.txt",ios::app);
    e.Signup();
    file.write( reinterpret_cast<char*>(&e), sizeof(e) );
    nwfile=nametofname(e.id,15);
    ax.open (nwfile.c_str(),ios::out);
    file.close();
    ax.close();
}

void display(Userid &e)
{
    fstream file;
    file.open("Accounts.txt",ios::in);
    while (true)
    {
        file.read(reinterpret_cast<char*>(&e), sizeof(e));
        if(file.eof())
        {
            break;

        }
        e.Displayid();
    }
    file.close();
}

char* login(Userid &e)
{
    fstream file;
    string user;
    string pass;
    int k;
    char j;
    do
    {
        k=0;
        file.open("Accounts.txt",ios::in);
        cout<<"\n\nEnter Your ID: ";
        cin>>user;
        file.seekg(0);
        file.read( reinterpret_cast<char*>(&e), sizeof(e) );
        while(!file.eof())
        {
            if(e.id==user)
            {
                cout<<"Enter Password: ";cin>>pass;
                if(e.pass==pass)
                {
                    j='N';
                    file.close();
                    system("cls");

                    cout<<"WELCOME... "<<e.name<<" to YOUR CONTACTS!!!!!!!"<<endl;
                    system("pause");
                    return e.id;
                }
                else
                {
                    cout<<"\nWrong Password...."<<endl;
                    j='Y';
                    cout<<"Try Again..."<<endl;
                    break;
                }
            }
            else
            {
                //if id don't matches
                k++;
            }

            file.read( reinterpret_cast<char*>(&e), sizeof(e) );
        }

        if(k!=0)
        {
            cout<<"\nWrong ID...."<<endl;
            j='Y';
            cout<<"Try Again..."<<endl;
        }
        file.close();
    }
    while(j=='Y');
    file.close();
}

void deleteid(Userid &e)
{
    char j;
    int k;
    fstream ax;
    fstream file;
    fstream temp;
    string user;
    string pass;
    cout<<"\nTo Remove Account...."<<endl;
    do
    {
        k=0;
        file.open("Accounts.txt",ios::in);
        cout<<"\n\nEnter Your ID: ";
        cin>>user;
        file.seekg(0);
        file.read( reinterpret_cast<char*>(&e), sizeof(e) );
        while(!file.eof())
        {
            j='Y';
            if(e.id==user)
            {
                cout<<"Enter Password: ";cin>>pass;
                if(e.pass==pass)
                {
                    j='N';
                    file.close();

                    break;
                }
                else
                {
                    cout<<"\nWrong Password...."<<endl;
                    j='Y';
                    cout<<"Try Again..."<<endl;
                    break;
                }
            }
            else
            {
                //if id don't matches
                k++;
            }

            file.read( reinterpret_cast<char*>(&e), sizeof(e) );
        }

        if(k!=0)
        {
            cout<<"\nWrong ID...."<<endl;
            j='Y';
            cout<<"Try Again..."<<endl;
        }
        file.close();
    }
    while(j=='Y');

    file.close();
    file.open("Accounts.txt",ios::in);
    temp.open("Fah.txt",ios::out);
    file.seekg(0);

    while (true)
    {
        file.read( reinterpret_cast<char*>(&e), sizeof(e) );
        if(file.eof()){
            break;
        }
        if(e.id!=user)
        {
            temp.write( reinterpret_cast<char*>(&e), sizeof(e) );
        }
    }
    file.close();
    temp.close();
    user=user+".txt";
    remove(user.c_str());
    remove("Accounts.txt");
    rename("Fah.txt","Accounts.txt");
    cout<<"\n\nRecord Deleted .."<<endl;
}

//ZAIN PROGRAMS

// Doubly Linked List in c++
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
    Node<T>* IsContainNode(T& matchData , bool startFromTail = false) const{
        if(IsEmpty())return NULL; // Null Case

        // finds element in linked List starts from head
        if(!startFromTail){
            Node<T>* itr = head;
            while(itr != NULL){
                if(itr->data == matchData) return itr;
                itr = itr->next;
            }
            return NULL; // On Not Found
        }
            // finds element from the linkedlist starts from tail
        else{
            Node<T>* itr = head;
            while(itr != NULL){
                if(itr->data == matchData) return itr;
                itr = itr->prev;
            }
            return NULL;// On Not Found
        }
    }

    /* Utilities Functions */

    // returns linkedlist is empty
    bool IsEmpty() const{ return head == NULL && tail == NULL;}

    // returns linked List is contains element N
    bool Contains(T& Data){return IsContainNode(Data);}

    // IO operator OverLoad Recommended
    void Display(void){
        if(IsEmpty())return;
        int id = 0;
        Node<T>* itr =head;
        while(itr!= NULL){
            cout<<" "<<"_ID : "<<id << endl;
            cout<<" "<<itr->data<<" "<<endl;
            itr = itr->next; id++;
        }

        cout<<endl;
    }

    Node<T>* getHead() const {
        return head;
    }

    Node<T>* getTail() const {
        return tail;
    }



private:
    Node<T> *head , *tail;

};



template<class T>
class Priority_DLinkedList {
public:

    Priority_DLinkedList(){
        LoadData();
    }

    void Insert(T& data,bool save=true){
        if(linkedList.IsEmpty()){ // Null case
            linkedList.Push(data);
            if(save) Save();
            return;
        }

        Node<T>* itr = linkedList.getHead();
        while(itr != NULL){
            if(data <= itr->data){
                linkedList.Push_Before(itr , data);
                if(save) Save();
                return;
            }
            itr = itr->next;
        }

        if(save) Save();
        linkedList.Push_Back(data);
    }

    void Display(){ linkedList.Display();}

    // Operator OverLoading

    void operator += (T& data){Insert(data);}

    void operator ++(){	Save(); }

    void operator -= (int id){
        cout << "I Invoked"<<"\n";
        abs(id); int _id = 0;
        // Valid Id Check
        ForEach([&](T &data , bool& isDone ){

            if(id == _id){
                this->stopItr = true;
                if(linkedList.Contains(data)){
                    char choice;
                    cout << ">> Do You Wana to Delete this Contact Y?N __ ";
                    cin >> choice;
                    if(choice == 'y' || choice == 'Y'){
                        linkedList.Remove(linkedList.IsContainNode(data));
                        cout << "Contact Has Beeen Deleted !"<<"\n";
                        Save();
                        return;
                    }else{
                        NEVERMIND
                        return;
                    }
                }
            } //if

            _id++;
        });
        if(!stopItr) cout << "\nInValid Id !!" <<" \n";
    }

    // IO
    friend ostream& operator << (ostream& out , Priority_DLinkedList<T> list){
        list.linkedList.Display();
        out << "\n";
        return out;
    }

    template<class CB>
    void ForEach(CB Func){
        Node<T>* itr = linkedList.getHead();
        stopItr = false;
        while(itr != NULL){
            if(stopItr) break;
            Func(itr->data , stopItr);
            itr = itr->next;
        }
    }

    Node<T>* operator [] (int &index){
        abs(index);
        int _index = 0;
        Node<T>* itr = linkedList.getHead();
        while(itr != NULL){
            if(index == _index)
                return itr;
            _index ++ ;
            itr = itr->next;
        }
        return NULL;
    }

private:
    DLinkedList<T> linkedList;
    bool stopItr = false;
    // Save
    void Save(){
        if(linkedList.IsEmpty()){
            return;
        }
        ofstream out;
        out.open(FILENAME , ios::out);

        Node<T>* itr = linkedList.getHead();

        while(itr != nullptr){
            out << itr->data;
            itr = itr->next;
        }

        out.close();
    }

    void LoadData(){
        ifstream in;
        in.open(FILENAME , ios::in);
        if(!in.is_open() || is_Empty(in)) return;
        string ss;
        while(getline(in , ss, '\n')){
            T data = T::StrToContact(ss);
            Insert(data,false);
        }
        in.close();
    }

    static  bool is_Empty(std::ifstream& pFile){return pFile.peek() == ifstream::traits_type::eof();}
};



#define ll long long
class Contact {
public:
    Contact() {
        userName = "UNSET";
        userContactNumber = 00000000000;
        fav = false;
    }

    Contact(const string& userName, ll& userContactNumber) :
            userName(userName),
            userContactNumber(userContactNumber) {}




    // Getter Setter

    const string& getUserName() const { return userName; }
    const ll& getUserContactNumber() const { return userContactNumber; }

    void setUserName(const string& userName) { this->userName = userName; }
    void setUserContactNumber(ll userContactNumber) { this->userContactNumber = userContactNumber; }



    // operator over loading
    friend ostream& operator << (ostream& out, Contact& contact) {

        out << "\n\t------------------------------------------------\n";
        cout << "\tName : " << contact.userName << "\n";
        cout << "\tContact Number : " << "0"<<contact.userContactNumber << "\n";
        out << "\t------------------------------------------------\n";
        return out;
    }

    friend istream& operator >>(istream& in, Contact& contact) {
        cout << "Enter Name : ";
        in.sync();
        getline(in , contact.userName);
        in.clear();
        cout << "Enter Contact Number : ";
        in >> contact.userContactNumber;
        return in;
    }

    //  compare

    // obj is Equal
    bool operator == (Contact& contact) {
        return userName == contact.userName && userContactNumber == contact.userContactNumber;
    }

    // Obj_l is greater or equal to Obj_r
    bool operator >= (Contact& contact) {
        if (this->userName == contact.userName)return true;
        // Compares 1st char
        cout << " " << userName[0] << " " << contact.userName[0];
        if (IsLunderR(userName[0], contact.userName[0])) return false;

        unsigned int minLength = (contact.userName.length() < userName.length()) ? contact.userName.length() : userName.length();

        for (int i = 0; i < minLength; i++)
            if (IsLunderR(userName[i], contact.userName[i])) return false;

        return true;
    }

    bool operator <= (Contact& contact) {
        if (this->userName == contact.userName) return true;
        // Compares 1st char
        if (userName[0] != contact.userName[0]) return IsLunderR(userName[0], contact.userName[0]); // if not equal


        unsigned int minLength = (contact.userName.length() < userName.length()) ? contact.userName.length() : userName.length();
        // 1 str
        for (int i = 0; i < minLength; i++)
            if (userName[i] == contact.userName[i]) continue;
            else {
                // if (IsLunderR(userName[i], contact.userName[i])) {
                // cout << " " << userName[i] << " < " << contact.userName[i] << endl;
                // }
                //else cout << " " << userName[i] << " > " << contact.userName[i] << endl;
                return IsLunderR(userName[i], contact.userName[i]);
            }

        //  if(!IsLunderR(userName[i] , contact.userName[i])) return false;

        return true;
    }

    string ToString(){
        stringstream ss;
        string s_userName = userName;
        replace(s_userName.begin() , s_userName.end() , ' ', '`' );
        ss << s_userName<<"$"<< userContactNumber<<"$"<<fav;
        return ss.str();
    }


    bool IsFavourite(void){return fav;}

    friend ofstream& operator << (ofstream& fileOut , Contact& contact){
        fileOut << contact.ToString() << "\n";
        return fileOut;
    }

    static Contact StrToContact(string ss){

        string arr[3];
        int index = 0;

        // split string to array
        for(int i=0;i<ss.length() ;i++) {
            if (ss[i] != '$') arr[index] += ss[i];
            else
                index++;
        }


        string t_userName = arr[0];
        int long long t_contactNumber = stoll(arr[1]);



        bool _fav= arr[2] == "0" ? false : true;

        replace(t_userName.begin() , t_userName.end() , '`' , ' ');
        Contact contact(t_userName , t_contactNumber);
        contact.fav = _fav;

        return contact;
    }

    void SetFav(bool state){
        fav = state;
    }

    bool operator != (Contact& obj){
        return this->userName != obj.userName && this->userContactNumber != obj.userContactNumber;
    }

private:
    string userName;
    ll userContactNumber;
    bool fav;

    const char alphabet[26] = {
            'a' , 'b' , 'c' , 'd' , 'e' , 'f' , 'g' , 'h' , 'i' , 'j' , 'k' , 'l' , 'm' , 'n' , 'o' ,'p' ,
            'q' , 'r'  , 's' , 't' , 'u' , 'v' , 'w' , 'x' , 'y' ,'z'
    };

    const char Alphabet[26] = {
            'A' , 'B' , 'C' , 'D' , 'E' , 'F' , 'G' , 'H' , 'I' , 'J' , 'K' , 'L' , 'M' , 'N' , 'O' ,'P' ,
            'Q' , 'R'  , 'S' , 'T' , 'U' , 'V' , 'W' , 'X' , 'Y' ,'Z'
    };

    bool IsLunderR(char l, char r) const {
        for (int i = 0; i < 26; i++) {
            if (alphabet[i] == l || Alphabet[i] == l) return true;
            if (alphabet[i] == r || Alphabet[i] == r) return false;
        }
        return l < r;
    }
};

void start()
{



    frontpage();
    //sndPlaySound("D:/PROJECT/1.wav",SND_FILENAME);

    system("PAUSE");

    Userid u;
    int n;

    do
    {
        system("cls");
        cout<<"CHOOSE AN OPTION: "<<endl;
        cout<<"1. LOGIN"<<endl;
        cout<<"2. SIGNUP"<<endl;
        cout<<"3. DELETE AN ID"<<endl;
        cout<<"4. DEBUG IDs"<<endl;
        cout<<"0. EXIT"<<endl;
        cin>>n;
        switch(n)
        {
            case 1:
                login(u);
                n=0;
                break;
            case 2:
                saving(u);
                break;
            case 3:
                deleteid(u);
                break;
            case 4:
                display(u);
                system("pause");
                break;
            case 0:
                break;
            default:
                cout<<"Wrong input..."<<endl;
                break;
        }

    }while(n!=0);

}


bool DuplicateCheck(Priority_DLinkedList<Contact> list , Contact& contact ,bool ignore = false){
    bool isFound = false;

    list.ForEach([&](Contact& _contact , bool& canStop){
        if(contact.getUserName() == _contact.getUserName() ||
           contact.getUserContactNumber() == _contact.getUserContactNumber()) {
            if(ignore && contact == _contact){

            }
            else{
                isFound = true;
                canStop = true;
                cout << "\nNAME OR CONTACT NUMBER ALREADY EXSIST IN APP !!! \n"<< "\n";
            }
        }
    });

    return isFound;
}

int main() {

    FILENAME = "MyFile.text";

    Priority_DLinkedList<Contact> list;
    cout << list;

    Contact contact;

    ///STATING FROM SOUND AND LOGIN
    // start();

    int n;
    do
    {
        system("pause");
        system("cls");

        cout<<"MENU: "<<endl;
        cout<<"1. ADD NUMBER"<<endl;
        cout<<"2. FIND NUMBER"<<endl;
        cout<<"3. FAKE CALL"<<endl;
        cout<<"4. RECENTS"<<endl;
        cout<<"5. FAVORITES"<<endl;
        cout<<"6. DELETE CONTACT"<<endl;
        cout<<"7. MANAGE CONTACT"<<endl;
        cout<<"8. SHOW ALL CONTACTS"<<endl;
        cout<<"0. EXIT"<<endl;
        cin>>n;


        bool found = false;
        switch(n)
        {
            case 1:

                ////ADD NUMBER USING FILEHANDLING
                do{
                    cin >> contact;
                }while(DuplicateCheck(list , contact));

                list += contact;

                break;
            case 2:
                // SEARCH FOR NUMBER BY TAKING INPUT FOR NAME
                found = false;
                [&](){
                    int choice;
                    cout <<"SEARCH BY NAME     -1 \n";
                    cout <<"SEARCH BY NUMBER   -2 \n";
                    cout << "Enter Choice _ ";
                    cin >> choice;
                    if(choice == 1){
                        string nameMatch;
                        cout <<">> Enter Name _ ";
                        cin.sync();
                        getline(cin , nameMatch);

                        list.ForEach([&](Contact c , bool& isDone){
                            if(c.getUserName() == nameMatch){
                                isDone =true;
                                cout << c <<"\n";
                                found = true;
                                return;
                            }
                        }); // lambda
                        if(!found)
                            cout << " ! No Contact Found With this Name \n";
                        found = false;
                    } else if(choice ==2){
                        ll numberMatch;
                        cout << ">> Enter Number __ ";
                        cin >> numberMatch;
                        list.ForEach([&](Contact c , bool& isDone){
                            if(c.getUserContactNumber() == numberMatch){
                                isDone =true;
                                cout << c <<"\n";
                                found = true;
                                return;
                            }
                        }); // lambda
                        if(!found)
                            cout << " ! No Contact Found With this Number \n";
                        found =false;
                    } else NEVERMIND
                }  (); // lambda
                break;
            case 3:
                ////FAKE CALL FUNCTION WITH SOUND

                break;
            case 4:
                ////AFTER FAKE CALL NUMBER WILL BE IN RECENT

                break;
            case 5:
                ////FAVOURITES
                list.ForEach([&](Contact c , bool isDone = false){
                    if(c.IsFavourite()) {
                        cout << c << "\n";
                        found = true;
                    }
                });
                if(!found) cout << "Empty\n";
                found =false;
                break;
            case 6:
                ////DELETE NUMBER

                [&](){
                    cout << list ;
                    int id;
                    cout << " >> Enter _ID of Contact You wana to Delete _ _ ";
                    cin >> id;
                    list -= id;
                }();

                break;
            case 7:
                ////MANAGE CONTACT
                [&](){
                    cout << list ;
                    int id;
                    cout << " >> Enter _ID of Contact You wana to Manage _ _ ";
                    cin >> id;

                    if(list[id] != nullptr){
                        cout << "\nYou Selected -> \n";
                        cout << list[id]->data;
                        int choice;
                        cout << "\tADD TO FAVOURITE      - 1\n";
                        cout << "\tREMOVE FROM FAVOURITE - 2\n";
                        cout << "\tChange Contact Number - 3\n";
                        cout << "\tChange Name           - 4\n";
                        cout << "\tEnter Choice _ _ ";
                        cin  >> choice;

                        switch(choice){
                            case 1: // add fav
                                list[id]->data.SetFav(true);
                                cout << "\n\tContact Has Been Added to Favourite \n";
                                break;

                            case 2: // remove from fav
                                list[id]->data.SetFav(false);
                                cout << "\n\tContact Has Been Removed to Favourite \n";
                                break;

                            case 3: // change number
                                [&](){
                                    ll newNumber;
                                    do{
                                        cout << "\n\tEnter New Number _ _ ";
                                        cin >> newNumber;
                                        auto t_Contact = list[id]->data;
                                        t_Contact.setUserContactNumber(newNumber);
                                    }while(DuplicateCheck(list , list[id]->data , true));
                                    cout << "\n\t AllSet \n";
                                }();
                                break;
                            case 4: // change Name
                                [&](){
                                    string newName;
                                    do{
                                        cout << "\n\tEnter New Name _ _ ";
                                        cin.sync();
                                        getline(cin  , newName);

                                        auto t_Contact = list[id]->data;
                                        t_Contact.setUserName(newName);
                                    }while(DuplicateCheck(list , list[id]->data , true));
                                    cout << "\n\t AllSet \n";
                                }();
                                break;
                            default:
                                NEVERMIND
                        }
                        ++list;
                    }
                }();
                break;
            case 8:
                ////DISPLAY ALL CONTACTS IN SORTING FORM
                cout << list;
                break;
            case 0:
                cout<<"THANKS FOR USING OUR PROGRAM...."<<endl;
                cout<<"       SEE YOU AGAIN..."<<endl;
                break;
            default:
                cout<<"Wrong input..."<<endl;
                break;
        }

    }while(n!=0);

}