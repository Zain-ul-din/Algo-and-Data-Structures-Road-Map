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
int GetInt (const char*);
double GetDouble(const char*);

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

// @ Gets int input
int GetInt (const char* message) {
    cout << message;
    int auxiliary = 0;
    cin.clear(); // ! clear previous buffer
    cin.sync(); // reset flags
    cin >> auxiliary;
    if (!cin.fail()) return auxiliary;
    PrintError("Invalid Input Expected : number");
    GetInt(message);
    return 0;
}

// @ Gets Double Input
double GetDouble (const char* message) {
    cout << message;
    double auxiliary = 0;
    cin.clear(); // ! clear previous buffer
    cin.sync(); // reset flags
    cin >> auxiliary;
    if (!cin.fail()) return auxiliary;
    PrintError("Invalid Input Expected : float | number");
    GetDouble(message);
    return 0.0;
}



#endif //INPUT_H
