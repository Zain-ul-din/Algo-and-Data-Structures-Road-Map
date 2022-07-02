//
/// Assigment 3
//

#include<iostream>
#include<string>

using namespace std;

///  Problem # _ 1 

/* 
 @  Converts : decimal number to a binary, octal, and hexadecimal
 @  Params : double number , int base
 @  returns => string 
*/
string Convert (double number , int base) {
    string auxiliary;
    while (number --) {

    }
}

/// Problem # _ 2


/// Problem # _ 4

/*
  @ Params : int number 
  @ Returns => Reverse of a int
*/
int Reverse (int number) {
    int reverseNumber = 0;

    for (int i = number ; i > 0 ; i /= 10) {
       reverseNumber *= 10;
       reverseNumber += i % 10;
    }

    return reverseNumber;
}

/// Problem # _ 5



// Driver Code
int main () {
  cout << Reverse(80893);
}