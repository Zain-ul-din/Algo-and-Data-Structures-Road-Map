//
// Dependencies : NONE
//

#ifndef ADMIN_H
#define ADMIN_H

#include "../Helpers/Input.h"
#include "../Helpers/Algorithm.h"

class Admin {
public:
   Admin ();
   void Init ();
   bool Login ();

private:
      bool canSignIn;
      string userName  , password;
      static string ADMINFILE_PATH;
      void SaveData ();
      void LoadData ();
};

Admin::Admin() {
    this->userName = "undefined";
    this->password = "undefined";
    this->Init();
}

void Admin::Init() {
    canSignIn = false;
    LoadData();
}

string Admin::ADMINFILE_PATH = "ADMIN_DATA.text";

bool Admin::Login() {
    system("cls");
    if(this->canSignIn) {

        cout << "\n -- Admin Panel \n";
        cout << "\n  - Login - 0 \n";
        cout << "\n  - Exit  - 1 \n";
        int choice = GetInput<int>("Enter Choice : ");
        string userName , password;
        switch (choice) {
            case 0:
                userName = GetString("Enter User Name : ");
                password = GetPassword("Enter Password : ");
                return userName == this->userName && password == this->password;
            case 1:
                cout << "\n -- Exit \n";
                break;
            default:
                PrintError("Invalid Choice ");
        }
    }
    else{
        system("cls");
        cout << "\n -- Admin Panel \n";
        cout << "\n  - SignUp - 0 \n";
        cout << "\n  - Exit   - 1 \n";
        int choice = GetInput<int>("Enter Choice : ");
        string userName , password;
        switch (choice) {
            case 0:
                this->userName = GetString("Enter User Name : ");
                this->password = GetPassword("Enter Password : ");
                this->canSignIn = true;
                this->SaveData();
                return true;
                break;
            case 1:
                cout << "\n -- Exit \n";
                break;
            default:
                PrintError("Invalid Choice ");
        }
    }
    return false;
}

void Admin::SaveData() {
    ofstream out;
    out.open(this->ADMINFILE_PATH , ios::out);
    if (out.fail()) {
        out.close();
        return;
    }
    out << Replace(this->userName)  << reserveSeparator << this->password << "\n";
    out.close();
}

void Admin::LoadData() {
    ifstream in;
    in.open (this->ADMINFILE_PATH , ios::in);
    if (in.fail() || IsEmptyFile(in)) {
        in.close();
        this->SaveData();
        return;
    }
    string aux , auxArray[2];
    while (getline(in , aux , '\n' )) {
        int idx = 0;
        for (int i = 0 ; i < aux.length() ; i += 1)
             if (aux[i] == reserveSeparator) idx += 1;
             else auxArray[idx].push_back(aux[i]);
        break;
    }
    in.close();

    this->userName = Replace(auxArray[0] , '_' , ' ');
    this->password = auxArray[1];

    this->canSignIn = this->password != "undefined";
}

#endif //ADMIN_H
