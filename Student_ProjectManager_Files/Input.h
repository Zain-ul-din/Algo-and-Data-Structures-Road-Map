
#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

#include "./Dependencies/Randoms_Color.h"

using namespace std;
using namespace Randoms;

namespace Input {

    static void Print(const char *buffer , Colors color = white ) { cout << color << buffer; }
    static void Error(const char *error) { cout  << "\n"<< red << "-- Error : " << error << white <<" \n"; }
    static void Warning (const char* warning) { cout  << "\n"<< yellow << "-- Warning : " << warning << white <<" \n";}

    static void Refresh ();

    static void InitInput () { Init(); }

    static string GetLine(const char *message){
        Print(message);
        string temp = "aux";
        Refresh ();
        do {
            Refresh();
            getline(cin, temp);
            if (temp.empty()) {
                Error("String Should Not Be NULL ");
                Print(message);
            } else return temp;
        }  while (temp.empty());
        return temp;
    }

    template <class T>
    static T GetInput(const char *message){
        Print(message);
        T temp;
        Refresh();
        cin >> temp;
        if (!cin.fail()) return temp;
        Error("Invalid Input");
        GetInput<T>(message);
    }

    static bool GetChoice (const char* message) {
        char choice = GetInput<char>(message);
        return choice == 'Y' || choice == 'y';
    }

    static void PrintStr (const char* buffer, const int width , const char SEP = '|' , string color = "white"){
        cout  << " ";
        cout << std::setfill (' ') << std::setw (width);

        if (color == "green") cout << green << buffer << " " << white << SEP;
        else if (color == "green") cout << yellow << buffer << " " << white << SEP;
        else if (color == "red") cout << red << buffer << " " << white << SEP;
        else cout << white << buffer << " " << white << SEP;
    }

    inline static void Refresh () {
        cin.clear();
        cin.sync();
    }

}

#endif
