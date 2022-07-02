//
// Dependencies : STD
//

#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <string>
#include <iomanip>
#include "../FileManager/SaveSystem.h"

using namespace std;

/*
 * Input Stuff
 */

void PrintError (const char*);
string GetString (const char*);
bool GetChoice (const char*);
void PrintChar (const char , int);

/* Polymorphism */
void SetOffSet (int);
template<class TYPE> void SetOffSet (TYPE val , int width , const char separator);

template<class TYPE> TYPE GetInput (const char*);
template<class TYPE> TYPE GetValueUnder (TYPE  , const char* , const char* );
template<class TYPE> TYPE GetValueUpper (TYPE , const char* , const char*);
template<class TYPE> TYPE GetInputInRange ( TYPE , TYPE   , const char * , const char *);


// @ Displays Error
void PrintError (const char* message) { cout << "\n Error : " << message << " \n"; }

// @ Gets String Input
string GetString (const char* message) {
    cout << "\n >> "<< message;
    string str;
    do
    {
        cin.clear(); // ! clear previous buffer
        cin.sync(); //  reset flags
        getline(cin, str);
        if (str.empty()) cout << "\n >> "<< message;
    }
    while (str.empty());
    return str;
}

// @ Gets  input of Type <Any>
template<class TYPE>
TYPE GetInput (const char* message) {
    TYPE auxiliary;
        do
    {
        cout << "\n >> " << message;
        cin.clear(); // ! clear previous buffer
        cin.sync(); // reset flags
        cin >> auxiliary;
        if (cin.fail()) PrintError("Invalid Input");
    }
        while (cin.fail());
    return auxiliary;
}

// @ Get input in give range from user
template<class TYPE>
TYPE GetInputInRange( TYPE min , TYPE max , const char * message , const char* err ) {
    TYPE aux ;
        do
    {
        aux = GetInput<TYPE>(message);
        if (!(aux >= min && aux <= max)) PrintError(err);
    }
        while (!(aux >= min && aux <= max));
    return aux;
}

// @ Returns new Value that must be under the given value
template<class TYPE>
TYPE GetValueUnder(TYPE value , const char* message , const char* err) {
    TYPE auxiliary;
        do
    {
        auxiliary = GetInput<TYPE>(message);
        if (!(auxiliary < value)) PrintError(err);
    }
        while (!(auxiliary < value));
    return auxiliary;
}

// @ Returns new Value that must be greater then given value
template<class TYPE> TYPE GetValueUpper (TYPE value , const char* message , const char* err) {
    TYPE auxiliary ;
        do
    {
        auxiliary = GetInput<TYPE>(message);
        if(!(auxiliary > value)) PrintError(err);
    }
        while (!(auxiliary > value));
    return auxiliary;
}

// Returns => User Choice Y/N
bool GetChoice(const char *message) {
    cout << message;
    char aux;
    cin >> aux;
    return aux == 'Y' || aux == 'y';
}

// Offset
void SetOffSet (int offset) {
    if (offset < 1) return;
    for (int i  = 0 ; i < offset ; i += 1) cout << "\t";
}

// Sets Width
template<class TYPE> void SetOffSet (TYPE val , int width , const char separator) { cout << " "<< setw(width) << val << "  " << separator << " "; }

// Prints Char
void PrintChar (const char _char ,int len) {
   cout << "\n\n";
   for (int  i = 0 ; i < len ; i += 1) cout << _char;
   cout << "\n\n";
}

#endif //INPUT_H
