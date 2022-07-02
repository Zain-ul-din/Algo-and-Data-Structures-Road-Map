//
//
//

#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <iostream>
#include <string>

using namespace std;

const char reserveSeparator = '`';

string Replace (string , const char  , const char );
template< class TYPE > TYPE Clamp (TYPE  , TYPE  , TYPE );
bool IsContainsChar (string& , char);
template<class  TYPE> bool IsInRange (TYPE , TYPE ,TYPE);
void RemoveChar (string& , char);

double GetPercentageOf (double val , float percent);
float GetPercentageOf (float val , float percent);

int CharToInt (char _char);

// Swap two pointers
template<class TYPE>
void Swap (TYPE* ptr1 , TYPE* ptr2) {
    TYPE* temp = ptr1;
    ptr1 = ptr2;
    ptr2 = temp;
}

// Returns=> Char to int
int CharToInt(char _char) { return int(_char) - 48;}

// Returns => String Replace old char with new
string Replace (string str , const char _old = ' ', const char _new  = '_') {
    string auxiliary;
    for (int  i = 0 ; i < str.length() ; i += 1)
        if (str[i] == _old) auxiliary.push_back(_new);
        else if (str[i] == reserveSeparator) auxiliary.push_back('?');
        else auxiliary.push_back(str[i]);
    return auxiliary;
}

// @ Returns => value btw min max
template<class TYPE>
TYPE Clamp(TYPE val, TYPE min , TYPE max) {
    if (val < min) return min;
    if (val > max) return max;
    return val;
}

// @ Returns => string contains Char
bool IsContainsChar(string& str ,string match) {
    for (int  i = 0 ; i < str.length() ; i += 1)
        if (str[i] == match[0]) return true;
    return false;
}

// @ Returns => val in range of min and max
template<class  TYPE> bool IsInRange (TYPE val, TYPE min,TYPE max) {
    return val >= min && val <= max;
}

// @ Removes char from str
void RemoveChar (string& str , char _char) {
    string aux = str;
    str = "";
    for (int  i = 0 ; i < aux.length() ; i += 1 )
        if (aux[i] != _char) str.push_back(aux[i]);
}

// @ Returns Percentage
double GetPercentageOf(double val, float percent) { return (val / 100) * percent;}
float GetPercentageOf(float val, float percent) { return (val / 100) * percent;}

// @ Returns Char in String
bool IsContainsChar(string &str, char _char) {
    for (int i = 0 ; i < str.length() ; i += 1)
        if (str[i] == _char) return true;
    return false;
}

#endif //ALGORITHM_H
