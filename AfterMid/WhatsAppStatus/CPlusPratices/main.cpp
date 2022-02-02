#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <fstream>


using namespace std;


class Book{
public:


    Book(int id , string bookName , string publisherName , int qt)
            : id(id) , bookName(bookName) , publisherName(publisherName) , qt(qt){}

    Book(){}

    bool operator == (Book& book){
        return this->bookName == book.bookName
               || this->id == book.id;
    }

    friend ostream & operator << (ostream& out , Book& book){
        out << "\n =================================================\n";
        out << "\t Book Name      : "<<book.bookName << endl;
        out << "\t Publisher Name : " <<book.publisherName<<endl;
        out << "\t Book Quantity  : " << book.qt<<endl;
        out << "\t ID __________  : " << book.id <<endl;
        out << "\n =================================================\n";
        return out;
    }

    friend istream & operator >> (istream& in , Book & book){
        cout << "\tEnter Id : "; in >> book.id;
        cout << "\tEnter Book Name : "; in.sync();
        getline(in , book.bookName);
        cout << "\tEnter Publisher Name : "; in.sync();
        getline(in , book.publisherName);
        cout << "\tEnter Quantity : "; in >> book.qt;
        return in;
    }

    string ToString(){
        stringstream ss;
        string str_book = this->bookName;
        replace(str_book.begin() , str_book.end() ,' ' , '_');

        string str_pubName = this->publisherName;
        replace(str_pubName.begin() , str_pubName.end() , ' ' , '_');


        ss << str_book    << SEPARTOR
           << str_pubName << SEPARTOR
           << this->qt    << SEPARTOR
           << this->id;

        return ss.str();
    }

    // getter Setter

    int getId() const {return id;}

    void setId(int id) {this->id = id;}

    int getQt() const {return qt;}

    void setQt(int qt) {this->qt = qt;}

    const string &getBookName() const {return bookName;}

    void setBookName(const string &bookName) { this->bookName = bookName;}

    const string &getPublisherName() const {return publisherName;}

    void setPublisherName(const string &publisherName) {this->publisherName = publisherName;}


    static Book StrToObj(string& ss ){
        vector<string > loadedArr = Split(ss , SEPARTOR);


        Book book;

        replace(loadedArr[0].begin() , loadedArr[0].end() , '_' ,' ');
        replace(loadedArr[1].begin() , loadedArr[1].end() , '_' ,' ');


        book.bookName = loadedArr[0];
        book.publisherName = loadedArr[1];
        book.qt = stoi(loadedArr[2]);
        book.id = stoi(loadedArr[3]);

        return book;
    }
private:
    int id , qt;
    string bookName , publisherName;

    static const int MAX_VAR = 4;
    static const char SEPARTOR = '%';

    static vector<string> Split(string ss , const char sep){
        vector<string> vec;

        string temp;

        for(int i=0 ; i < ss.length() ; i++)
            if(ss[i] == sep){
                if(temp != "") vec.push_back(temp);
                temp = "";
            } else temp.push_back(ss[i]);

        if(temp != "")
            vec.push_back(temp);

        return vec;
    }
};



template<class T>
class Node{
public:
    T data;
    Node* prev , *next;

    Node(T d){
        data = d;
        prev = NULL;
        next = NULL;
    }
};

template<class T>
class DoublyLinkedList  {
public:

    DoublyLinkedList(){
        head = NULL;
        tail = NULL;
        LoadData();
    }

    void Insert(T data, bool save = true){

        Node<T>* newNode = new Node<T>(data);
        // Null Case
        if(head == NULL && tail == NULL){
            head = newNode;
            tail = newNode;
            if(save) {
                Save();
            }
            return;
        }

        Node<T>* temp =head;

        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
        if(save) {
            Save();
        }
    }

    Node<T>* FindNode(T &data){
        if(head == NULL && tail == NULL){
            return NULL;
        }

        Node<T>* itr = head;

        while(itr != NULL){
            if(itr->data == data)
                return itr;
            itr = itr->next;
        }

        return NULL;
    }


    void Delete(Node<T>* node) {
        if(node == head)
            head = head->next;

        if(node == tail)
            tail = tail->prev;


        if(node->next != NULL)
            node->next->prev = node->prev;

        if(node->prev != NULL)
            node->prev->next = node->next;

        delete node;
        Save();
    }

    void Display(){

        if(head == NULL && tail == NULL){
            cout << "\n Empty !\n";
            return;
        }

        Node<T> *itr = head;

        while(itr != NULL){
            cout << itr->data << endl;
            itr = itr->next;
        }
    }

    void Save() {
        ofstream out;
        out.open(FILENAME , ios::out);
        if(!out.is_open())
            return;

        Node<T>* itr= head;
        while(itr != NULL){
            out << itr->data.ToString() << "\n";
            itr = itr->next;
        }

        out.close();
    }

    bool IsContains(T& data){
        if(head == NULL && tail == NULL)
            return false;
        Node<T>* itr = head;

        while (itr != NULL){
            if(itr->data == data)
                return true;
            itr= itr->next;
        }

        return false;
    }
private:
    Node<T>* head;
    Node<T>* tail;
    const char* FILENAME = "DataBase.text";

    void LoadData(){
        ifstream in;
        in.open(FILENAME , ios::in);
        if(!in.is_open())
            return;
        if(in.peek() == ifstream::traits_type::eof()) // file is Empty
            return;

        string temp;

        while (getline(in , temp ,'\n')){
            Insert(T::StrToObj(temp) , false);
        }
        in.close();
    }


};

// Adds new Book
void AddNewBook(DoublyLinkedList<Book> &list){
    Book book;

    do{
        cin >> book;
        if(list.IsContains(book))
            cout << "\n\tBook Name or Id already Exist ! TRY AGAIN\n";
    } while (list.IsContains(book));

    list.Insert(book);
}

// Display All Books
void DisplayAllBooks(DoublyLinkedList<Book>& list){
    list.Display();
}

void DeleteBook(DoublyLinkedList<Book> &list){
    list.Display();
    cout <<"\n";
    cout << "\n\tEnter id  of Book You wana to Delete: ";
    int id ; cin >> id;

    Book book; book.setId(id);

    if(list.IsContains(book)){
        list.Delete(list.FindNode(book));
        cout << "\tBook Has been Deleted !\n";
    }
    else cout << "\t No Book exists with this ID !\n";
}

void IssueBook (DoublyLinkedList<Book> &list){
    list.Display();
    cout << "\n";
    int id;
    cout << "Enter id of book you wana to get : ";
    cin >> id;

    Book book;
    book.setId(id);

    if(list.IsContains(book)){
        Book* ptr = &(list.FindNode(book)->data);
        if(ptr->getQt() > 0){
            cout << "\n" << " \t" <<ptr->getBookName() << " Has Been Issued !\n";
            int qt = ptr->getQt();
            qt --;
            ptr->setQt(qt);
            list.Save();
        } else cout << "\n" << "\t" << "Out Of Stock " << endl;
    }
    else cout << "\t No Book exists with this ID !\n";
}

void PlaySoundFunc(string fileName){

}

int main () {
    DoublyLinkedList<Book> library;

    int choice ;
    Book book;
    do {
        cout << "\n\tEnter New Book  -1\n";
        cout << "\tDelete Book     -2\n";
        cout << "\tDisplay Books   -3\n";
        cout << "\tIssue Book      -4\n";
        cout << "\tEnter Choice _ ";
        cin >> choice;
        switch (choice) {
            case 1: // Add New Book Method
                AddNewBook(library);
                break;
            case 2:
                DeleteBook(library);
                break;
            case 3:
                DisplayAllBooks(library);
                break;
            case 4:
                IssueBook(library);
                break;
            default:
                choice = 0;
        }
    } while (choice != 0);

}