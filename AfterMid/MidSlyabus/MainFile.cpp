
/*
 * C++ library system
 */
#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include<algorithm>
#include <sstream>

class Book ;
class IString ;
template<class T> class ICompareAble;

Book BookFactory ();
void DeleteBook (const int& id);
void UpdateBook (Book & book);
void SaveSystem (std::vector<IString> & vec);
static  std::vector<Book> library;

// @interfaces
class IString {
public:
    virtual std::string ToString () = 0;
};

template<class T>
class ICompareAble {
public:
    virtual int CompareTo (T& obj ) = 0;
};

class Book : public IString , public  ICompareAble<Book> {
  public:
    Book(){}
    Book(int id, int qt, int inStock, const std::string &bookName, const std::string &authorName,
         const std::string &publishDate) : id(id), qt(qt), inStock(inStock), bookName(bookName), authorName(authorName),
                                           publishDate(publishDate) {}

    int id , qt , inStock;
    std::string bookName , authorName , publishDate ;

    friend std::ostream &operator<<(std::ostream &os, const Book &book) {
        os << "id: " << book.id << ", qt: " << book.qt << ", inStock: " << book.inStock << ", bookName: " << book.bookName
           << ", authorName: " << book.authorName << ", publishDate: " << book.publishDate;
        return os;
    }

    /* @ OverRides */

    std::string ToString() override {
        std::stringstream ss;
        ss << id << " , " << qt << " , " << inStock << " , " << bookName << " , " << authorName << " , " << publishDate ;
        return ss.str();
    }

    int CompareTo(Book &book) override { // compare by QT
        // if equals 0  if : greater then returns  1 else -1
        return (this->qt > book.qt) ? 1 : (this->qt < book.qt) ? -1 : 0;
    }

    /* @ Static Members */
    static std::string GetNowDate (){
        time_t timeNow;
        time(&timeNow);
        return std::string(ctime(&timeNow));
    }
};

Book BookFactory  () {
    Book book ( 1 , 5 , 5 , "c++ in depth" , "unknown" , Book::GetNowDate());
    // Get input && Helper duplicate check
    return book;
}

void UpdateBook (Book & book ){
   // Update Here
   book.authorName = "me";
}

void DeleteBook (const int& idx) { library.erase(library.begin() + idx);}

void Print (const std::wstring buffer){
    std::wcout << buffer;
}

// Driver Code
int main () {
     // choice here
     Print(L"\n Name \n");
    // Add Book
    library.push_back (BookFactory());

    // Display Books
    std::for_each(library.begin() , library.end() , [&] (Book & book) {
          std::cout << book << "\n";
    });

     // Update Book
    const int id = 1 ;
    std::for_each(library.begin() , library.end() , [&](Book& book){
        if(book.id == id)
            return UpdateBook(book);
    });

    // Display Books
    for ( const auto & book  : library)
        std::cout << book << "\n";

    // Delete Book
    for (int idx (0) ; idx < library.size() ; idx += 1)
         if(library [idx].id == id) {
             std::cout << "\n idx : " << idx << "  \n";
            DeleteBook(idx);  break;
         }

    // Display Books
    for (std::vector<Book>::iterator itr = library.begin() ; itr != library.end() ; itr += 1 )
        std::cout << *itr << "\n";

    if(library.empty())
        std::cout << "Nah-Thing in library\n";



    return 0;
}
































//
//#include<iostream>
//#include<memory>
//#include<chrono>
//
//class SQLConectionDetail {
//public:
//    static const char * db , * userName ,* password ,* host;
//};
//
//
//
//// Driver Code
//int main () {
//    std::cout << " " << SQLConectionDetail::db << "  \n";
//    std::cout << " " << SQLConectionDetail::userName << "  \n";
//    std::cout << " " << SQLConectionDetail::password << "  \n";
//    std::cout << " " << SQLConectionDetail::host << "  \n";
//
//    return 0;
//}
//
////template<class T>
////class Node{
////public:
////    T data;
////    std::unique_ptr<Node> next;
////};
////
////
////template<class T>
////class LinkedList {
////  public:
////    LinkedList(){
////        head = nullptr;
////    }
////
////    /*
////     * Insertion
////     */
////    void Push (const T data){
////        std::unique_ptr<Node<T>> newNode (new Node<T>{ data , nullptr });
////
////        if(head == nullptr){
////            head = std::move(newNode);
////            return;
////        }
////
////        newNode->next = std::move(head);
////        head = std::move(newNode);
////    }
////
////    /*
////     * Deletion
////     */
////    void Pop (){
////        if(head == nullptr)
////            return;
////        head = std::move(head->next);
////    }
////
////    T Top () {
////        if(head == nullptr)
////            return -1;
////        return head->data;
////    }
////
////    bool IsEmpty(){
////        return head == nullptr;
////    }
////
////   private:
////     std::unique_ptr<Node<T>> head;
////};
////
////
////
////
////int main () {
////
////    auto startTime = std::chrono::high_resolution_clock::now();
////
////    LinkedList<int> list;
////    list.Push(3);
////    list.Push(1);
////    list.Push(9);
////    list.Push(5);
////    list.Push(7);
////
////    while (!list.IsEmpty()){
////        std::cout << list.Top() << " ";
////        list.Pop();
////    }
////
////    std::cout << list.Top() << " ";
////
////    auto endTime = std::chrono::high_resolution_clock::now();
////    auto timeTook = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
////
////    std::cout << "\nTime Took : " << timeTook.count() << " ms \n";
////
////    return 0;
////}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//const char * SQLConectionDetail::db = "postgres";
//const char * SQLConectionDetail::userName = "postgres";
//const char * SQLConectionDetail::password = "zainuldin";
//const char * SQLConectionDetail::host = "localhost:5432";
//
//
//
//
//
//
//
//
//
//
