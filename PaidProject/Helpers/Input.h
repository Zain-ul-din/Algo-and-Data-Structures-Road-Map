//
// Dependencies : NONE
//

#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <string>

using namespace std;

void PrintError (const char*);
string GetString (const char*);
template<class TYPE> TYPE GetInput (const char*);

// @ Displays Error
void PrintError (const char* message) { cout << "\n Error : " << message << " \n"; }

// @ Gets String Input
string GetString (const char* message) {
    cout << message;
    string str;
    cin.clear(); // ! clear previous buffer
    cin.sync(); // reset flags
    getline(cin , str);
    return str;
}

// @ Gets  input of Type <Any>
template<class TYPE>
TYPE GetInput (const char* message) {
    cout << message;
    TYPE auxiliary ;
    cin.clear(); // ! clear previous buffer
    cin.sync(); // reset flags
    cin >> auxiliary;
    if (!cin.fail()) return auxiliary;
    PrintError("Invalid Input Expected : number");
    GetInput<TYPE>(message);
    return auxiliary;
}





#endif //INPUT_H
