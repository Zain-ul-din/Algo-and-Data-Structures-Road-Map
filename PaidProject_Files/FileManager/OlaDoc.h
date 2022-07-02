//
// Created by 97152 on 31/05/2022.
//

#ifndef OLADOC_H
#define OLADOC_H

#include "./Manager/OlaDoc_Manager.h"

#define MAX 100000

using namespace std;

class OlaDoc {
public:
     void RunApplication ();

private:
    OlaDoc_Manager olaDocManager;
};

void OlaDoc::RunApplication () {
     system("pause");
     for ( ; ;)
     {
         system("cls");
         cout << "\n -- OlaDoc Panel \n";
         cout << "\n  - Patient Login - 0\n";
         cout << "\n  - Doctor Login  - 1 \n";
         cout << "\n  - Admin  Login  - 2\n";
         int choice = GetInput<int>("Enter choice : ");
         switch (choice) {
             case 0:
                 olaDocManager.Show_PatientPanel();
                 break;
             case 1:
                 olaDocManager.Show_DoctorPanel();
                 break;
             case 2:
                 olaDocManager.Show_AdminPanel();
                 break;
             default:
                 PrintError("Invalid Choice !!");
         }
         cout << "\n\n";
         system("pause");
     }
}

#endif //OLADOC_H
