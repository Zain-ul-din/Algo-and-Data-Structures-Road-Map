#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

//#include "Time.h"

using namespace std;
#define ll long long

// Whats App Status
class User{
public:

    // Constructor
    User() {
        userName = "Unknown";
        userNumber = 9999999999;
        filePath = L"Unknown";
    }


    User(string &userName, long long int userNumber, bool haveStatus , wstring &filePath) : userName(userName),
    userNumber(userNumber),
    haveStatus(haveStatus) , filePath(filePath) {}

    // Getter Setter

    const string &getUserName() const {
        return userName;
    }

    void setUserName(const string &userName) {
        User::userName = userName;
    }

    long long int getUserNumber() const {
        return userNumber;
    }

    void setUserNumber(long long int userNumber) {
        User::userNumber = userNumber;
    }

    const wstring &getFilePath() const {
        return filePath;
    }

    void setFilePath(const wstring &filePath) {
        User::filePath = filePath;
    }

    // Operator OverLoading

    bool operator == (const User& user){
        return this->userName == user.userName || this->userNumber == user.userNumber;
    }

    bool operator <= (const User& user) {
        return this->userName <= user.userName;
    }

    bool operator < (const User& user) {
        return this->userName <= user.userName;
    }

    bool operator > (const User& user) {
        return this->userName > user.userName;
    }

    bool operator >= (const User& user) {
        return this->userName > user.userName;
    }


    friend ostream &operator << (ostream& out , User& user){
        out << "\n" << "\tUserName   : " <<user.userName <<endl;
        out <<         "\tUserNumber : " <<user.userNumber <<endl;
        return out;
    }

    friend istream &operator >> (istream& in , User &user) {
        cout <<"\n" << "\tEnter User Name   : "; in.sync();
        getline(in , user.userName );
        cout        << "\tEnter User Number : ";
        cin >> user.userNumber;
        cout << "\n\t==================================================\n";
        cout << "\n\t\tDRAG AND DROP YOUR FILE HERE !\n";
        cout << "\n\t==================================================";
        in.sync();
        getline(wcin , user.filePath);
        cout << "\n\tFile Path Has Been Added ___ ";
        wcout << user.filePath << endl;
        return in;
    }

    static void playStatus(User& user){
        stringstream ss;
        ss << "\"" << string(user.filePath.begin() , user.filePath.end()) << "\"";
        system(ss.str().c_str());
    }

    string ToString() {
        stringstream ss;
        //  string ` number ` wstring ` bool status //  Writing format
        ss << userNumber << SEPARTOR << userNumber << SEPARTOR
           << filePath.c_str() << SEPARTOR << haveStatus;
        return ss.str();
    }


    static User StringToUser(string ss) {
        vector<string> res = Split(ss);

        if(res.size() < NUMBEROFVAR)
            return User();

        //  string ` number ` wstring ` bool status //  Loading format

        User user;
        user.userName = res[0];
        user.userNumber = stoll(res[1]);
        user.filePath = wstring(res[2].begin() , res[2].end());
        user.haveStatus = res[3] == "1";

        return user;
    }

private:
    string userName;
    ll userNumber;
    wstring filePath;
    bool haveStatus;

    static const char SEPARTOR = '`';
    static const unsigned int NUMBEROFVAR = 4;

    static vector<string> Split(string ss) {
        vector<string> vec;
        string temp;

        for(int i = 0 ; i < ss.length() ; ++i )
            if(ss[i] == SEPARTOR ){
                vec.push_back(temp);
                temp = "";
            }  else temp += ss[i];

        return vec;
    }
};





int main() {
    User user;
    cin >> user;
    User::playStatus(user);
    cout << user;
}
