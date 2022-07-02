//
// Dependencies :
//

#ifndef OLDA_DOC_MANAGER_H
#define OLDA_DOC_MANAGER_H

#include "./Doctors.h"
#include "./Patients.h"
#include "./Appointments.h"
#include "../Users/Admin.h"

class OlaDoc_Manager {
public:
     OlaDoc_Manager();
     void Show_DoctorPanel ();
     void Show_PatientPanel ();
     void Show_AdminPanel ();

private:
      Admin admin;
      Doctors doctors;
      Patients patients;
      Appointments appointments;

      void DoctorMenu ();
      void PatientMenu ();

      void SearchDoctors_Menu(string options );
      void Appointments_Menu();

      // Helpers
      void ShowDoctorAppointments (Doctor& doctor ,string options);
      void ShowPatientAppointments (Patient& patient,string options);

      void ShowAppointmentsDetails_Doctor (Doctor& doctor);
      void ShowAppointmentsDetails_Patient (Patient& patient);

      // Admin Helpers
      void DoctorEditMenu ();
      void PatientEditMenu ();

      void Doctor_UD(); // Update Delete
      void Appointment_UD(); // Update Delete
      void Patient_UD(); // Update Delete
};

OlaDoc_Manager::OlaDoc_Manager() {
    cout << " \n Add Intro Here \n";
}


void OlaDoc_Manager::Show_DoctorPanel() {
       system("cls");
       cout << "\n -- Doctor Panel \n";
       cout << "\n  - Login with existing account     - 0\n";
       cout << "\n  - Sign Up ( new to OlaDoc )       - 1\n";
       cout << "\n  - Exit                            - 2\n";
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
    system("pause");
    if (this->doctors.currentLoggedInDoctorIdx != -1) DoctorMenu();
}

void OlaDoc_Manager::Show_PatientPanel() {
        system("cls");
        cout << "\n -- Patient Panel \n";
        cout << "\n  - Login with existing account     - 0\n";
        cout << "\n  - Sign Up ( new to OlaDoc )       - 1\n";
        cout << "\n  - Exit                            - 3\n";
        int choice = GetInput<int>("Enter Choice _ ");
        switch (choice)
    {
        case 0:
            this->patients.SignIn();
            break;
        case 1:
            this->patients.SignUp();
            break;
        case 3:
            cout << "\n -- Exit \n";
        default:
            PrintError(" Invalid Choice !!");
    }

    system("pause");
    if (this->patients.currentLoggedInPatientIdx != -1)
        PatientMenu();
}

void OlaDoc_Manager::DoctorMenu () {
     appointments.CalculateRating(*(this->doctors.doctors[this->doctors.currentLoggedInDoctorIdx]));
     doctors.SaveData();
          int choice = 0;
          for (; choice != 4 ;)
    {
          system("cls");
          int newAppointmentCount = this->appointments.Search(*(this->doctors.doctors[this->doctors.currentLoggedInDoctorIdx]));
          cout << "\n -- Welcome to OlaDoc \n";
          if (newAppointmentCount > 0)
              cout << "\n --  you have " << newAppointmentCount
                   << " appointments pending. please check them out :-) \n";
          cout << "\n  - View Profile       - 0 \n";
          cout << "\n  - Edit Profile       - 1 \n";
          cout << "\n  - Check Appointments - 2 \n";
          cout << "\n  - Reset Password     - 3 \n";
          cout << "\n  - LogOut             - 4 \n";
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
                this->ShowDoctorAppointments( *(this->doctors.doctors[this->doctors.currentLoggedInDoctorIdx]), "NONE");
                break;
            case 3:
                this->doctors.doctors[this->doctors.currentLoggedInDoctorIdx]->setPassword(GetString("Enter new Password : "));
                this->doctors.SaveData();
                break;
            case 4:
                this->doctors.currentLoggedInDoctorIdx = -1;
                cout << "\n -- Logged Out \n";
                break;
            default:
                PrintError("Invalid Choice ! ");
        }
        system("pause");
    }
}

void OlaDoc_Manager::PatientMenu() {

    int choice = 0;
    for ( ; choice != 6 ;)
    {
        int updateCounts = this->appointments.Search(*(this->patients.patients[this->patients.currentLoggedInPatientIdx]));
        system("cls");
        cout << "\n -- Welcome to OlaDoc \n";
        if (updateCounts > 0)
            cout << "\n  -- Hey , You have " << updateCounts << " new updated please check them out ! \n";

        cout << "\n  - View Profile        - 0 \n";
        cout << "\n  - Edit Profile        - 1 \n";
        cout << "\n  - Search Doctors      - 2 \n";
        cout << "\n  - View Appointments   - 3 \n";
        cout << "\n  - ReCharge Account    - 4 \n";
        cout << "\n  - Reset Password      - 5 \n";
        cout << "\n  - LogOut              - 6 \n";
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
                   this->SearchDoctors_Menu("Patient");
            break;
            case 3:
                   this->ShowPatientAppointments( *(this->patients.patients[this->patients.currentLoggedInPatientIdx]), "NONE");
            break;
            case 4:
                   this->patients.patients[this->patients.currentLoggedInPatientIdx]->setBalance(
                           this->patients.patients[this->patients.currentLoggedInPatientIdx]->getBalance() + Payment::ReChargeAccount()
                   );
                   this->patients.SaveData();
            break;
            case 5:
                this->patients.patients[this->patients.currentLoggedInPatientIdx]->setPassword(GetPassword("Enter new Password : "));
                this->patients.SaveData();
            break;
            case 6:
                this->patients.currentLoggedInPatientIdx = -1;
                cout << "\n -- Logged out \n";
            break;
            default:
                PrintError("Invalid Choice ! ");
        }
        system("pause");
    }

}

void OlaDoc_Manager::SearchDoctors_Menu(string options= "Patient") {
    int choice = 0;
    for ( ; choice != 4 ; )
    {
        system("cls"); //Patient can search for doctors by (Specialty, Area, and Hospitals)

        cout << "\n -- Welcome to OlaDoc Search Menu . Here you can find best doctors in less time  \n";
        cout << "\n  - Search doctor by Specialty - 0 \n" ;
        cout << "\n  - Search doctor by Area      - 1 \n" ;
        cout << "\n  - Search doctor by Hospital  - 2 \n" ;
        cout << "\n  - Let me choose              - 3 \n" ;
        cout << "\n  - Exit                       - 4 \n" ;
        choice = GetInput<int>("Enter Choice : ");
        string match , match1 , match2;
        bool isFound ;
        switch (choice)
        {
            case 0:
                match = Doctor::GetSpecializationAreaInput();
                isFound = this->doctors.Search(match , "Specialty");
                if (!isFound) cout << "\t\t -- Not Found \n";
                else if (options == "Admin") this->Doctor_UD();
                else Appointments_Menu();
            break;
            case 1:
                match = GetString("Enter doctor Area (city name) : ");
                isFound = this->doctors.Search(match , "Area");
                if (!isFound) cout << "\t\t -- Not Found \n";
                else if (options == "Admin") this->Doctor_UD();
                else Appointments_Menu();
            break;
            case 2:
                match = GetString("Enter Hospital Name : ");
                isFound = this->doctors.Search(match , "Hospital");
                if (!isFound) cout << "\t\t -- Not Found \n";
                else if (options == "Admin") this->Doctor_UD();
                else Appointments_Menu();
            break;
            case 3:
                        for ( ; choice != 4 ; )
                {
                         isFound = false;
                        system("cls");
                        cout << "\n - Search by Specialty + Area            - 0\n";
                        cout << "\n - Search by Hospital + Specialty        - 1\n";
                        cout << "\n - Search by Area + Hospital             - 2\n";
                        cout << "\n - Search by Specialty + Area + Hospital - 3\n";
                        cout << "\n - Exit                                  - 4\n";
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
                                  , GetChoice(" >> Do you want to match all queries Y/N : "));
                            break;
                        case 4:
                            cout << " -- Exit \n";
                            break;
                        default:
                            PrintError("Invalid Choice");
                    }
                    if (!isFound) cout << "\t\t -- Not Found \n";
                    else if (options == "Admin") this->Doctor_UD();
                    else Appointments_Menu();
                    system("pause");
                }
                choice = 0;
            break;
            case 4:
                cout << " -- Exit \n";
            break;
            default:
                PrintError("Invalid Choice ! ");
        }
        if (!isFound) cout << "\t\t -- Not Found \n";
        else if (options == "Admin") cout << "admin";
        else Appointments_Menu();
        system("pause");
    }
}

void OlaDoc_Manager::Appointments_Menu() {
    if (!GetChoice("\n >> Do You want to make Appointment with any of these doctors Y/N : ")) return;
    int idx = GetInput<int>("Enter Serial No of doctor for more details : ");
    if (!this->doctors.Search(idx)) {
        PrintError("Invalid Serial Number !! ");
        return;
    }
    system("cls");
    cout << *(this->doctors.doctors[idx]) ;
    this->appointments.Print(*(this->doctors.doctors[idx]) , 5);
    PrintChar('-' , 100);
    if (!GetChoice(" >> Do you want to make appointment with this doctor Y/N : ")) return;
    this->appointments.MakeAppointment(*(this->doctors.doctors[idx] ), *(this->patients.patients[this->patients.currentLoggedInPatientIdx]));
    this->patients.SaveData();
}

void OlaDoc_Manager::ShowDoctorAppointments(Doctor& doctor , string options) {
    appointments.Print("Patient");
    if (appointments.idx == -1) {
        cout << "\n -- No Appointment So far \n";
        return;
    }

    int idx = appointments.idx + 1;
    bool isFound = false;
    while (idx --) {
        if (appointments.appointments[idx] == NULL) break;
        if (appointments.appointments[idx]->getDoctorCnic() == doctor.getCnicNumber()) {
            appointments.Print(idx, *(patients.Search(appointments.appointments[idx]->getPatientCnic())),
                               *(this->appointments.appointments[idx]));
            isFound = true;
        }
    }

    if (options == "Admin") {
        if (!isFound) { cout << " \n -- No Appointment So far \n"; return;}
        Appointment_UD();
        this->appointments.SaveData();
        return;
    }

    this->appointments.SaveData();
    if (!isFound) cout << " \n -- No Appointment So far \n";
    else this->ShowAppointmentsDetails_Doctor(*(this->doctors.doctors[this->doctors.currentLoggedInDoctorIdx]));
}

void OlaDoc_Manager::ShowPatientAppointments( Patient & patient, string options) {
    appointments.Print("Doctor");
    if (appointments.idx == -1) {
        cout << "\n -- No Appointment So far \n";
        return;
    }
    int idx = appointments.idx + 1;
    bool isFound = false;
    while (idx --) {
        if (appointments.appointments[idx] == NULL) break;
        if (appointments.appointments[idx]->getPatientCnic() == patient.getCnicNumber()) {
            appointments.Print(idx, *(doctors.Search(this->appointments.appointments[idx]->getDoctorCnic(), true)),
                               *(this->appointments.appointments[idx]));
            if (options != "Admin") appointments.appointments[idx]->setIsSeen(true);
            isFound = true;
        }
    }
    if (options == "Admin") {
        if (!isFound) { cout << " \n -- No Appointment So far \n"; return;}
        Appointment_UD();
        this->appointments.SaveData();
        return;
    }
    this->appointments.SaveData();
    if (!isFound) cout << " \n -- No Appointment So far \n";
    else this->ShowAppointmentsDetails_Patient(*(this->patients.patients[this->patients.currentLoggedInPatientIdx]));
}

void OlaDoc_Manager::ShowAppointmentsDetails_Doctor(Doctor& doctor) {
    if (!GetChoice("\n >> Do you see any appointment details Y/N ")) return;
    int idx = GetInput<int>("Enter serial no of appointment for more details : ");
    if (this->appointments.Search(idx) == NULL || this->appointments.Search(idx)->getDoctorCnic() != doctor.getCnicNumber()) {
        PrintError("Invalid Serial Number ");
        return;
    }
    system("cls");
    // Valid Idx => Show Patient
    cout << "\n" << *(this->patients.Search(this->appointments.appointments[idx]->getPatientCnic()));
    PrintChar('-' , 100);
    if (!GetChoice("\n >> Do you want to edit appointment detail Y/N : ")) return;
    this->appointments.appointments[idx]->Update("Doctor");
    this->appointments.SaveData();
}

void OlaDoc_Manager::ShowAppointmentsDetails_Patient(Patient& patient) {
    if (!GetChoice("\n >> Do you see any appointment details Y/N ")) return;
    int idx = GetInput<int>("Enter serial no of appointment for more details : ");
    if (this->appointments.Search(idx) == NULL || this->appointments.Search(idx)->getPatientCnic() != patient.getCnicNumber()) {
        PrintError("Invalid Serial Number ");
        return;
    }
    system("cls");
    // Valid Idx => Show Doctor
    cout << "\n" << *(this->doctors.Search(this->appointments.appointments[idx]->getDoctorCnic() , 0));
    this->appointments.Print(*(this->doctors.doctors[idx]) , 5);
    PrintChar('-' , 100);
    if (!GetChoice("\n >> Do you want to edit appointment detail Y/N : ")) return;
    this->appointments.appointments[idx]->Update("Patient");
    this->appointments.Delete(*(this->patients.patients[this->patients.currentLoggedInPatientIdx]));
    appointments.CalculateRating(*(this->doctors.doctors[this->doctors.currentLoggedInDoctorIdx]));
    this->patients.SaveData();
}

void OlaDoc_Manager::Show_AdminPanel() {
   if (!admin.Login()) {
       PrintError("Invalid Password | UserName ");
       return;
   }
   int choice = 0;
            for ( ; choice!= 2;)
   {
            system("cls");
            cout << "\n -- Admin Menu \n";
            cout << "\n  - Edit Doctors Record - 0 \n";
            cout << "\n  - Edit Patient Record - 1 \n";
            cout << "\n  - Exit                - 2 \n";
            choice = GetInput<int>("Enter Choice : ");
            switch (choice)
        {
            case 0:
                this->DoctorEditMenu();
                break;
            case 1:
                this->PatientMenu();
                break;
            case 2:
                cout << "\n -- Exit \n";
                break;
            default:
                PrintError("Invalid Choice !!");
        }
           system("pause");
   }
}


void OlaDoc_Manager::DoctorEditMenu() {
    system("cls");
     cout << "\n -- Doctor Edit Panel \n";
     cout << "\n  - Show All Doctors   - 0\n";
     cout << "\n  - Search Doctors     - 1\n";
     cout << "\n  - Exit               - 2\n";
     int choice = GetInput<int>("Enter Choice : ");
     switch (choice)
     {
         case 0:
             doctors.Search();
             this->Doctor_UD();
             break;
         case 1:
             this->SearchDoctors_Menu("Admin");
             break;
         case 2:
             cout << "\n -- Exit \n";
             break;
         default:
             PrintError("Invalid Choice !!!");
     }
    system("pause");
}

void OlaDoc_Manager::PatientEditMenu() {
    system("cls");
    cout << "\n -- Doctor Edit Panel \n";
    cout << "\n  - Show All Patients   - 0\n";
    cout << "\n  - Search Patients     - 1\n";
    cout << "\n  - Exit                - 2\n";
    int choice = GetInput<int>("Enter Choice : ");
    switch (choice) {
        case 0:
              this->patients.Search();
              this->Patient_UD();
            break;
        case 1:
             cout << "\n You will find Search option in version 2.0 wait for update ! \n";
            break;
        case 2:
            cout << "\n -- Exit \n";
            break;
        default:
            PrintError("Invalid Choice!!");
    }
}

void OlaDoc_Manager::Doctor_UD() {
    if (!GetChoice("\n >> Do you want to edit any of these records Y/N _ ")) return;
    int idx = GetInput<int>("Enter Serial number of Doctor for more details : ");
    if (!this->doctors.Search(idx)) {
        PrintError("Invalid Serial no !!");
        return;
    }
    this->doctors.doctors[idx]->Display();
    cout << "\n -- Select Operation \n";
    cout << "\n  - Show All Appointments of this Doctor - 0 \n";
    cout << "\n  - Delete Account                       - 1 \n";
    cout << "\n  - Update Data                          - 2 \n";
    cout << "\n  - Exit                                 - 3 \n";
    int choice = GetInput<int>("Enter Choice : ");
    switch (choice) {
        case 0:
            this->ShowDoctorAppointments(*(this->doctors.doctors[idx]) , "Admin");
            this->appointments.SaveData();
            this->doctors.SaveData();
            break;
        case 1:
            if (GetChoice(" >> Are you sure to Delete this Account (Note : All appointments will also deleted ! ) Y/N : ")) {
                this->doctors.Delete(idx);
                this->appointments.Delete(*(this->doctors.doctors[idx]));
                this->appointments.SaveData();
                this->doctors.SaveData();
            }
            break;
        case 2:
            this->doctors.Update(idx);
            break;
        default:
            PrintError("Invalid Choice !!");
    }
}

void OlaDoc_Manager::Appointment_UD() {
    if (!GetChoice(" >> Do You wana to Edit any Appointment Details Y/N : ")) return;
    int idx = GetInput<int>("Enter Serial Number of Appointment you wanna to edit : ");
    if (this->appointments.Search(idx) == NULL) {
        PrintError("Invalid Serial Number !!");
        return;
    }
    cout << "\n - Edit - 0 \n";
    cout << "\n - Exit - 1 \n";
    int _choice;
    int choice = GetInput<int>("Enter Choice : ");
    switch (choice) {
        case 0:
            for (; _choice != 2; )
            {
                system("cls");
                cout << "\n Access as a Doctor  - 0\n";
                cout << "\n Access as a Patient - 1\n";
                cout << "\n Exit                - 2\n";
                _choice = GetInput<int>("Enter Choice : ");
                switch (_choice) {
                    case 0:
                        this->appointments.appointments[idx]->Update("Doctor");
                        break;
                    case 1:
                        this->appointments.appointments[idx]->Update("Patient");
                        break;
                    case 2:
                        cout << "\n -- Exit \n";
                        break;
                    default:
                        PrintError("Invalid Choice !!");
                }
                system("pause");
            }
            break;
        case 1:
            cout << "\n -- Exit \n";
            break;
        default:
            PrintError("Invalid Message!!");
    }
}

void OlaDoc_Manager::Patient_UD() {
    if (!GetChoice(" >> Do You wana to Edit any Patient Details Y/N : ")) return;
    int idx = GetInput<int>("Enter Serial Number of Patient you wanna to edit : ");
    if (this->patients.Search(idx)) {
        PrintError("Invalid Serial Number !!");
        return;
    }

    this->patients.patients[idx]->Display();
    cout << "\n -- Select Operation \n";
    cout << "\n  - Show All Appointments of this Doctor - 0 \n";
    cout << "\n  - Delete Account                       - 1 \n";
    cout << "\n  - Update Data                          - 2 \n";
    cout << "\n  - Exit                                 - 3 \n";
    int choice = GetInput<int>("Enter Choice : ");
    switch (choice) {
        case 0:
            this->ShowPatientAppointments(*(this->patients.patients[idx]) , "Admin");
        break;
        case 1:
            if (GetChoice(" >> Are you sure to Delete this Account (Note : All appointments will also deleted ! ) Y/N : ")) {
                this->patients.Delete(idx);
                this->appointments.Delete(*(this->doctors.doctors[idx]));
                this->appointments.SaveData();
                this->doctors.SaveData();
            }
        break;
        case 2:
            this->patients.patients[idx]->Update();
            break;
        default:
            PrintError("Invalid Choice !!");
    }
}


#endif //OLDA_DOC_MANAGER_H
