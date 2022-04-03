//#include <iostream>
//#include <string>
//#include <sstream>
//#include <algorithm>
//#include <vector>
//#include <fstream>
//
//
//using namespace std;
//
//
//class Book{
//public:
//
//
//    Book(int id , string bookName , string publisherName , int qt)
//            : id(id) , bookName(bookName) , publisherName(publisherName) , qt(qt){}
//
//    Book(){}
//
//    bool operator == (Book& book){
//        return this->bookName == book.bookName
//               || this->id == book.id;
//    }
//
//    friend ostream & operator << (ostream& out , Book& book){
//        out << "\n =================================================\n";
//        out << "\t Book Name      : "<<book.bookName << endl;
//        out << "\t Publisher Name : " <<book.publisherName<<endl;
//        out << "\t Book Quantity  : " << book.qt<<endl;
//        out << "\t ID __________  : " << book.id <<endl;
//        out << "\n =================================================\n";
//        return out;
//    }
//
//    friend istream & operator >> (istream& in , Book & book){
//        cout << "\tEnter Id : "; in >> book.id;
//        cout << "\tEnter Book Name : "; in.sync();
//        getline(in , book.bookName);
//        cout << "\tEnter Publisher Name : "; in.sync();
//        getline(in , book.publisherName);
//        cout << "\tEnter Quantity : "; in >> book.qt;
//        return in;
//    }
//
//    string ToString(){
//        stringstream ss;
//        string str_book = this->bookName;
//        replace(str_book.begin() , str_book.end() ,' ' , '_');
//
//        string str_pubName = this->publisherName;
//        replace(str_pubName.begin() , str_pubName.end() , ' ' , '_');
//
//
//        ss << str_book    << SEPARTOR
//           << str_pubName << SEPARTOR
//           << this->qt    << SEPARTOR
//           << this->id;
//
//        return ss.str();
//    }
//
//    // getter Setter
//
//    int getId() const {return id;}
//
//    void setId(int id) {this->id = id;}
//
//    int getQt() const {return qt;}
//
//    void setQt(int qt) {this->qt = qt;}
//
//    const string &getBookName() const {return bookName;}
//
//    void setBookName(const string &bookName) { this->bookName = bookName;}
//
//    const string &getPublisherName() const {return publisherName;}
//
//    void setPublisherName(const string &publisherName) {this->publisherName = publisherName;}
//
//
//    static Book StrToObj(string& ss ){
//        vector<string > loadedArr = Split(ss , SEPARTOR);
//
//
//        Book book;
//
//        replace(loadedArr[0].begin() , loadedArr[0].end() , '_' ,' ');
//        replace(loadedArr[1].begin() , loadedArr[1].end() , '_' ,' ');
//
//
//        book.bookName = loadedArr[0];
//        book.publisherName = loadedArr[1];
//        book.qt = stoi(loadedArr[2]);
//        book.id = stoi(loadedArr[3]);
//
//        return book;
//    }
//private:
//    int id , qt;
//    string bookName , publisherName;
//
//    static const int MAX_VAR = 4;
//    static const char SEPARTOR = '%';
//
//    static vector<string> Split(string ss , const char sep){
//        vector<string> vec;
//
//        string temp;
//
//        for(int i=0 ; i < ss.length() ; i++)
//            if(ss[i] == sep){
//                if(temp != "") vec.push_back(temp);
//                temp = "";
//            } else temp.push_back(ss[i]);
//
//        if(temp != "")
//            vec.push_back(temp);
//
//        return vec;
//    }
//};
//
//
//
//template<class T>
//class Node{
//public:
//    T data;
//    Node* prev , *next;
//
//    Node(T d){
//        data = d;
//        prev = NULL;
//        next = NULL;
//    }
//};
//
//template<class T>
//class DoublyLinkedList  {
//public:
//
//    DoublyLinkedList(){
//        head = NULL;
//        tail = NULL;
//        LoadData();
//    }
//
//    void Insert(T data, bool save = true){
//
//        Node<T>* newNode = new Node<T>(data);
//        // Null Case
//        if(head == NULL && tail == NULL){
//            head = newNode;
//            tail = newNode;
//            if(save) {
//                Save();
//            }
//            return;
//        }
//
//        Node<T>* temp =head;
//
//        while(temp->next != NULL)
//            temp = temp->next;
//
//        temp->next = newNode;
//        newNode->prev = temp;
//        if(save) {
//            Save();
//        }
//    }
//
//    Node<T>* FindNode(T &data){
//        if(head == NULL && tail == NULL){
//            return NULL;
//        }
//
//        Node<T>* itr = head;
//
//        while(itr != NULL){
//            if(itr->data == data)
//                return itr;
//            itr = itr->next;
//        }
//
//        return NULL;
//    }
//
//
//    void Delete(Node<T>* node) {
//        if(node == head)
//            head = head->next;
//
//        if(node == tail)
//            tail = tail->prev;
//
//
//        if(node->next != NULL)
//            node->next->prev = node->prev;
//
//        if(node->prev != NULL)
//            node->prev->next = node->next;
//
//        delete node;
//        Save();
//    }
//
//    void Display(){
//
//        if(head == NULL && tail == NULL){
//            cout << "\n Empty !\n";
//            return;
//        }
//
//        Node<T> *itr = head;
//
//        while(itr != NULL){
//            cout << itr->data << endl;
//            itr = itr->next;
//        }
//    }
//
//    void Save() {
//        ofstream out;
//        out.open(FILENAME , ios::out);
//        if(!out.is_open())
//            return;
//
//        Node<T>* itr= head;
//        while(itr != NULL){
//            out << itr->data.ToString() << "\n";
//            itr = itr->next;
//        }
//
//        out.close();
//    }
//
//    bool IsContains(T& data){
//        if(head == NULL && tail == NULL)
//            return false;
//        Node<T>* itr = head;
//
//        while (itr != NULL){
//            if(itr->data == data)
//                return true;
//            itr= itr->next;
//        }
//
//        return false;
//    }
//private:
//    Node<T>* head;
//    Node<T>* tail;
//    const char* FILENAME = "DataBase.text";
//
//    void LoadData(){
//        ifstream in;
//        in.open(FILENAME , ios::in);
//        if(!in.is_open())
//            return;
//        if(in.peek() == ifstream::traits_type::eof()) // file is Empty
//            return;
//
//        string temp;
//
//        while (getline(in , temp ,'\n')){
//            Insert(T::StrToObj(temp) , false);
//        }
//        in.close();
//    }
//
//
//};
//
//// Adds new Book
//void AddNewBook(DoublyLinkedList<Book> &list){
//    Book book;
//
//    do{
//        cin >> book;
//        if(list.IsContains(book))
//            cout << "\n\tBook Name or Id already Exist ! TRY AGAIN\n";
//    } while (list.IsContains(book));
//
//    list.Insert(book);
//}
//
//// Display All Books
//void DisplayAllBooks(DoublyLinkedList<Book>& list){
//    list.Display();
//}
//
//void DeleteBook(DoublyLinkedList<Book> &list){
//    list.Display();
//    cout <<"\n";
//    cout << "\n\tEnter id  of Book You wana to Delete: ";
//    int id ; cin >> id;
//
//    Book book; book.setId(id);
//
//    if(list.IsContains(book)){
//        list.Delete(list.FindNode(book));
//        cout << "\tBook Has been Deleted !\n";
//    }
//    else cout << "\t No Book exists with this ID !\n";
//}
//
//void IssueBook (DoublyLinkedList<Book> &list){
//    list.Display();
//    cout << "\n";
//    int id;
//    cout << "Enter id of book you wana to get : ";
//    cin >> id;
//
//    Book book;
//    book.setId(id);
//
//    if(list.IsContains(book)){
//        Book* ptr = &(list.FindNode(book)->data);
//        if(ptr->getQt() > 0){
//            cout << "\n" << " \t" <<ptr->getBookName() << " Has Been Issued !\n";
//            int qt = ptr->getQt();
//            qt --;
//            ptr->setQt(qt);
//            list.Save();
//        } else cout << "\n" << "\t" << "Out Of Stock " << endl;
//    }
//    else cout << "\t No Book exists with this ID !\n";
//}
//
//void PlaySoundFunc(string fileName){
//
//}
//
//int main () {
//    DoublyLinkedList<Book> library;
//
//    int choice ;
//    Book book;
//    do {
//        cout << "\n\tEnter New Book  -1\n";
//        cout << "\tDelete Book     -2\n";
//        cout << "\tDisplay Books   -3\n";
//        cout << "\tIssue Book      -4\n";
//        cout << "\tEnter Choice _ ";
//        cin >> choice;
//        switch (choice) {
//            case 1: // Add New Book Method
//                AddNewBook(library);
//                break;
//            case 2:
//                DeleteBook(library);
//                break;
//            case 3:
//                DisplayAllBooks(library);
//                break;
//            case 4:
//                IssueBook(library);
//                break;
//            default:
//                choice = 0;
//        }
//    } while (choice != 0);
//
//}

#include<iostream>
#include<string>
using namespace std;

#define debug(x) std::cout << "\n" <<#x << " :  " << x << "\n"

class Evolution
{
private:
    int paper1, paper2, paper3, paper4, paper5, average;
    double percent1, percent2, percent3, percent4, percent5;
public:
    void set_paper1(int paper1)
    {
        this->paper1 = paper1;
    }
    int get_paper1()
    {
        return this->paper1;
    }
    void set_paper2(int paper2)
    {
        this->paper2 = paper2;
    }
    int get_paper2()
    {
        return this->paper2;
    }
    void set_paper3(int paper3)
    {
        this->paper3 = paper3;
    }
    int get_paper3()
    {
        return this->paper3;
    }
    void set_paper4(int paper4)
    {
        this->paper4 = paper4;
    }
    int get_paper4()
    {
        return this->paper4;
    }
    void set_paper5(int paper5)
    {
        this->paper5 = paper5;
    }
    int get_paper5()
    {
        return this->paper5;
    }
    void set_average(int average)
    {
        this->average = average;
    }
    int get_average()
    {
        return this->average;
    }
    void set_percent1(double percent1)
    {
        this->percent1 = percent1;
    }
    double get_percent1()
    {
        return this->percent1;
    }
    void set_percent2(double percent2)
    {
        this->percent2 = percent2;
    }
    double get_percent2()
    {
        return this->percent2;
    }
    void set_percent3(double percent3)
    {
        this->percent3 = percent3;
    }
    double get_percent3()
    {
        return this->percent3;
    }
    void set_percent4(double percent4)
    {
        this->percent4 = percent4;
    }
    double get_percent4()
    {
        return this->percent4;
    }
    void set_percent5(double percent5)
    {
        this->percent5 = percent5;
    }
    double get_percent5()
    {
        return this->percent5;
    }
    void calculation()
    {
        cout << "The numbers in first paper are " << get_paper1() << endl;
        cout << "The Percentage for first paper is " << get_percent1() << "%" << endl;
        cout << "The numbers in second paper are " << get_paper2() << endl;
        cout << "The Percentage for second paper is " << get_percent2() << "%" << endl;
        cout << "The numbers in third paper are " << get_paper3() << endl;
        cout << "The Percentage for third paper is " << get_percent3() << "%" << endl;
        cout << "The numbers in fourth paper are " << get_paper4() << endl;
        cout << "The Percentage for fourth paper is " << get_percent4() << "%" << endl;
        cout << "The numbers in fifth paper are " << get_paper5() << endl;
        cout << "The Percentage for fifth paper is " << get_percent5() << "%" << endl;
        cout << "The Average Percentage for all the papers is " << get_average() << "%" << endl;
    }
};
int main()
{
    Evolution salman;
    int num1, num2, num3, num4, num5, percent;
    long long average; // fix
    float perc1 =0 , perc2 = 0, perc3 =0, perc4 =0, perc5 =0;
    cout << "Enter the number of Papers from 0-100." << endl;
    cout << "Paper 1: " << endl;
    cin >> num1;
    if (num1  < 0 || num1 > 100)
    {
        cout << "Invalid Input !" << endl;
        return 0;
    }
    cout << "Paper 2: " << endl;
    cin >> num2;
    if (num2 < 0 || num2 > 100)
    {
        cout << "Invalid Input !" << endl;
        return 0;
    }
    cout << "Paper 3: " << endl;
    cin >> num3;
    if (num3 < 0 || num3 > 100)
    {
        cout << "Invalid Input !" << endl;
        return 0;
    }
    cout << "Paper 4: " << endl;
    cin >> num4;
    if (num4 < 0 || num4 > 100)
    {
        cout << "Invalid Input !" << endl;
        return 0;
    }
    cout << "Paper 5: " << endl;
    cin >> num5;
    if (num5 < 0 || num5 > 100)
    {
        cout << "Invalid Input !" << endl;
        return 0;
    }

    debug(num1);
    debug(num2);
    debug(num3);
    debug(num4);
    debug(num5);
    debug(perc1);

    average = (num1 + num2 + num3 + num4 + num5) / 5;

    perc1 = (num1 / 100) * 150;
    perc2 = (num2 / 100) * 100;
    perc3 = (num3 / 100) * 100;
    perc4 = (num4 / 100) * 100;
    perc5 = (num5 / 100) * 100;

    // Debug
    debug(perc1);
    debug(perc2);
    debug(perc3);
    debug(perc4);
    debug(perc5);
    debug(perc1);

    salman.set_percent1(perc1);
    salman.set_percent2(perc2);
    salman.set_percent3(perc3);
    salman.set_percent4(perc4);
    salman.set_percent5(perc5);

    salman.set_paper1(num1);
    salman.set_paper2(num2);
    salman.set_paper3(num3);
    salman.set_paper4(num4);
    salman.set_paper5(num5);

    salman.set_average(average);
    salman.calculation();
    if (average > 90 && average < 100)
    {
        cout << "Your Grade is 'A'" << endl;
    }
    else if (average > 80 && average < 89)
    {
        cout << "Your Grade is 'B'" << endl;
    }
    if (average > 70 && average < 79)
    {
        cout << "Your Grade is 'C'" << endl;
    }
    else if (average > 60 && average < 69)
    {
        cout << "Your Grade is 'D'" << endl;
    }
    if (average > 50 && average < 59)
    {
        cout << "Your Grade is 'D'" << endl;
    }
    else if(average < 49)
    {
        cout << "You're Fail" << endl;
    }
    system("pause>0");
    return 0;
}