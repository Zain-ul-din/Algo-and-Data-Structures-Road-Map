//
// Dependencies :
//

#ifndef OLDA_DOC_MANAGER_H
#define OLDA_DOC_MANAGER_H

#include "./Doctors.h"
#include "./Patients.h"

class OldaDoc_Manager {
public:


     void Show_DoctorPanel ();
     void Show_PatientPanel ();

private:
      Doctors doctors;
      Patients patients;

      void DoctorMenu ();
      void PatientMenu ();

      void SearchDoctors_Menu();
};

void OldaDoc_Manager::Show_DoctorPanel() {
       cout << "\n -- Doctor Panel \n";
       cout << "  - Login with existing account     - 0\n";
       cout << "  - Sign Up ( new to OldaDoc )      - 1\n";
       cout << "  - Exit                            - 2\n";
       int choice = GetInput<int>("Enter Choice _ ");
       switch (choice)
    {
        case 0:
            this->doctors.SignIn();
            break;
        case 1:
            this->doctors.SignUp();
            break;
        default:
            PrintError(" -- Exit \n");
    }

    if (this->doctors.currentLoggedInDoctorIdx != -1) DoctorMenu();
}

void OldaDoc_Manager::Show_PatientPanel() {
        cout << "\n -- Patient Panel \n";
        cout << "  - Login with existing account     - 0\n";
        cout << "  - Sign Up ( new to OldaDoc )      - 1\n";
        int choice = GetInput<int>("Enter Choice _ ");
        switch (choice)
    {
        case 0:
            this->patients.SignIn();
            break;
        case 1:
            this->patients.SignUp();
            break;
        default:
            PrintError(" -- Exit \n");
    }

    if (this->patients.currentLoggedInPatientIdx != -1)
        PatientMenu();
}

void OldaDoc_Manager::DoctorMenu () {
          int choice = 0;
          for (; choice != 3 ;)
    {
          system("cls");
          cout << "\n -- Welcome to OldaDoc \n";
          cout << "\n  - View Profile       - 0 \n";
          cout << "\n  - Edit Profile       - 1 \n";
          cout << "\n  - Check Appointments - 2 \n";
          cout << "\n  - LogOut             - 3 \n";
          choice = GetInput<int>("Enter Choice : ");
          switch (choice)
        {
            case 0:
                this->doctors.doctors[this->doctors.currentLoggedInDoctorIdx]->Display();
                break;
            case 1:
                this->doctors.doctors[this->doctors.currentLoggedInDoctorIdx]->Update();
                this->doctors.SaveData();
                break;
            case 2:
                cout << "Appointments Check \n";
                break;
            case 3:
                this->doctors.currentLoggedInDoctorIdx = -1;
                cout << " -- Logged Out \n";
                break;
            default:
                PrintError("Invalid Choice ! ");
        }
        system("pause");
    }
}

void OldaDoc_Manager::PatientMenu() {
    int choice = 0;
    for ( ; choice != 4 ;)
    {
        system("cls");
        cout << "\n -- Welcome to OldaDoc \n";
        cout << "\n  - View Profile        - 0 \n";
        cout << "\n  - Edit Profile        - 1 \n";
        cout << "\n  - Search Doctors      - 2 \n";
        cout << "\n  - View Appointments   - 3 \n";
        cout << "\n  - LogOut              - 4 \n";
        choice = GetInput<int>("Enter Choice : ");
        switch (choice)
        {
            case 0:
                   this->patients.patients[this->patients.currentLoggedInPatientIdx]->Display();
            break;
            case 1:
                   this->patients.patients[this->patients.currentLoggedInPatientIdx]->Update();
                   this->patients.SaveData();
            break;
            case 2:
                   this->SearchDoctors_Menu();
            break;
            case 3:
                   cout << "\n View Appointments \n";
            break;
            case 4:
                   this->patients.currentLoggedInPatientIdx = -1;
            break;
            default:
                PrintError("Invalid Choice ! ");
        }
        system("pause");
    }

}

void OldaDoc_Manager::SearchDoctors_Menu() {
    int choice = 0;
    for ( ; choice != 4 ; )
    {
        system("cls"); //Patient can search for doctors by (Specialty, Area, and Hospitals)

        cout << "\n -- Welcome to OldaDoc Search Menu . Here you can find best doctors in less time  \n";
        cout << "\n Search doctor by Specialty - 0 \n" ;
        cout << "\n Search doctor by Area      - 1 \n" ;
        cout << "\n Search doctor by Hospital  - 2 \n" ;
        cout << "\n Let me choose              - 3 \n" ;
        cout << "\n Exit                       - 4 \n" ;
        choice = GetInput<int>("Enter Choice : ");
        string match , match1 , match2;
        bool isFound ;
        switch (choice)
        {
            case 0:
                match = Doctor::GetSpecializationAreaInput();
                isFound = this->doctors.Search(match , "Specialty");
                if (!isFound) cout << "\t\t -- Not Found \n";
            break;
            case 1:
                match = GetString("Enter doctor Area (city name) : ");
                isFound = this->doctors.Search(match , "Area");
                if (!isFound) cout << "\t\t -- Not Found \n";
            break;
            case 2:
                match = GetString("Enter Hospital Name : ");
                isFound = this->doctors.Search(match , "Hospital");
                if (!isFound) cout << "\t\t -- Not Found \n";
            break;
            case 3:
                        for ( ; choice != 4 ; )
                {
                        system("cls");
                        cout << "\n Search by Specialty + Area            - 0\n";
                        cout << "\n Search by Hospital + Specialty        - 1\n";
                        cout << "\n Search by Area + Hospital             - 2\n";
                        cout << "\n Search by Specialty + Area + Hospital - 3\n";
                        cout << "\n Exit                                  - 4\n";
                        choice = GetInput<int>("Enter Choice : ");
                        switch (choice)
                    {
                        case 0:
                            match = Doctor::GetSpecializationAreaInput();
                            match1 = GetString("Enter doctor Area (city name) : ");
                            isFound = this->doctors.Search(match , match1  , "Specialty+Area");
                            break;
                        case 1:
                            match = GetString("Enter Hospital Name : ");
                            match1 = Doctor::GetSpecializationAreaInput();
                            isFound = this->doctors.Search( match, match1, "Hospital+Specialty");
                            break;
                        case 2:
                            match = GetString("Enter doctor Area (city name) : ");
                            match1 = GetString("Enter Hospital Name : ");
                            isFound = this->doctors.Search( match, match1, "Area+Hospital");
                            break;
                        case 3:
                            match = Doctor::GetSpecializationAreaInput();
                            match1 = GetString("Enter doctor Area (city name) : ");
                            match2 = GetString("Enter Hospital Name : ");
                            isFound = this->doctors.Search(match , match1 , match2
                                  , GetChoice("Do you want to match all queries Y/N : "));
                            break;
                        case 4:
                            cout << " -- Exit \n";
                            break;
                        default:
                            PrintError("Invalid Choice");
                    }
                    if (!isFound) cout << "\t\t -- Not Found \n";
                    system("pause");
                }
                choice = 0;
            break;
            default:
                PrintError("Invalid Choice ! ");
        }
        system("pause");
    }
}

#endif //OLDA_DOC_MANAGER_H
