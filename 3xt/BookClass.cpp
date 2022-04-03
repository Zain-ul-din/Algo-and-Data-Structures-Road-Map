
// Class Node
#include <iostream>
#include <string>

// Book Class
class Book{
public:
    Book(){}


    char name[50] , publisherName[50];
    int id;

    friend std::ostream &operator<<(std::ostream &os, const Book &book) {
        os << "\n name: " << book.name << "\n publisherName: " << book.publisherName << "\n id: " << book.id;
        return os;
    }

    friend std::istream & operator >> (std::istream &in , Book &book) {
        std::cout << "\nEnter Book Name : ";
        in.sync();
        in.getline(book.name , sizeof (char[50]));
        std::cout << "Enter Publisher Name : ";
        in.sync();
        in.getline(book.publisherName , sizeof (char[50]));
        std::cout << "Enter Book Id : ";
        in >> book.id;
        return in;
    }
};

namespace LIB{class Lib;}

// Driver Code
int main () {
	std::cout << "Enter File Path : ";
	std::string ss;
	std::cin >> ss;
	std::cout << ss << std::endl;
}

// Node

class LIB::Lib{
 public:
 	int name;
};