#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include "./Input.h"
#include "./Utilities.h"
#include "./Array.h"
#include <fstream>

using namespace std;

static const string FOLDER_NAME = "FM/";

namespace FileSystem {

    static string FilterString (string& _str) {
        string str  = _str;
        replace(str.begin() , str.end() , ' ' , '%');
        return str;
    }

    static string AddSpaces (string& _str) {
        string str  = _str;
        replace(str.begin() , str.end() , '%' , ' ');
        return str;
    }

    static bool IsExists  (string& fileName) {
        ifstream in;
        in.open(FOLDER_NAME + fileName + ".text" , ios::in);
        bool res = in.fail();
        in.close();
        return res;
    }

    static void CreateFile (string& fileName) {
        if(IsExists(fileName))
            return;
        ofstream out;
        out.open(FOLDER_NAME + fileName + ".text", ios::out);
        out.close();
    }

    static bool IsEmpty(std::ifstream& pFile){return pFile.peek() == ifstream::traits_type::eof();}

    template<class CallBack>
    static void ReadFile (string& fileName , CallBack callBack) {
        ifstream in;
        in.open(FOLDER_NAME + fileName + ".text" , ios::in);
        if (IsEmpty(in) || in.fail()) return;
        string aux ="";
        while (getline(in , aux , '\n')) {
            aux = AddSpaces(aux);
            callBack(aux);
            aux.clear();
        }
        in.close();
    }

    template<class T>
    static void WriteData (string& fileName , vector<T> arr) {
        ofstream out;
        out.open(FOLDER_NAME + fileName + ".text", ios::out);
        if (out.fail()) return;
        for (T& obj : arr) {
            string aux = static_cast<Interfaces::ISaveAble<T> &>(obj).ToString();
            aux = FilterString(aux);
            out << aux << "\n";
        }
        out.close();
    }

    static void WriteData (string& fileName , vector<string> arr , bool podType ) {
        ofstream out;
        out.open(FOLDER_NAME + fileName + ".text", ios::out);
        if (out.fail()) return;
        for (string& obj : arr) {
            string aux = FilterString(obj);
            out << aux << "\n";
        }
        out.close();
    }

    /*
     * A POD type is a C++ type that has an equivalent in C, and that uses the same rules as C uses for initialization,
     * copying, layout, and addressing. As an example, the C declaration struct Fred x; does not initialize the members
     * of the Fred variable x
     */


}

#endif
