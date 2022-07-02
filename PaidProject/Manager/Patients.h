//
// Created by 97152 on 02/06/2022.
//

#ifndef PAIDPROJECT_PATIENTS_H
#define PAIDPROJECT_PATIENTS_H


#include "./Users.h"

#define MAX 100000

class Patients  : public Users{
public:

    Patients();

    /* Over Rides */

    void SignUp() override;
    void SignIn() override;

    void Update(int idx) override;
    /* Load and save functionality */
    void LoadData() override;
    void SaveData() override;

    Patient** patients = NULL;
    int currentLoggedInPatientIdx;

    /* Methods */

    /* Polymorphism */
    void Delete (int idx ) ;
    bool Search (Patient* patient); // returns => patient exists in record
    int  Search (Patient& patient); // returns => Idx of patient in record
    void Search ();
    Patient* Search (string cnicNumber);
    bool Search (int idx);
private:
    static const string PATIENTS_FILEPATH;
    void Init ();

    bool SignUp_Helper (Patient** patient);  // returns => sign up succeed
    bool CheckPassword (Patient& patient); // password checker
};

const string Patients::PATIENTS_FILEPATH = "PATIENTS_DATA.text";

Patients::Patients() { this->Init();}

void Patients::SignUp() {
    Patient* patient = new Patient();
    if (!SignUp_Helper(&patient)) {
        delete patient;
        return;
    }
    idx += 1;
    this->patients[idx] = patient;
    this->currentLoggedInPatientIdx = this->Search(*patient);
    this->SaveData();
}

void Patients::SignIn() {
       Patient* patient = new Patient();
       string email = GetString("Enter You're email _ ");
       patient->setEmail(email);
       if (!Search(&(*patient)))
     {
         PrintError("User don't exists please use sign up instead !");
         return;
     }
       int attempts = 0;
       for ( ; attempts < 3 ; attempts += 1)
     {
         string password = GetString("Enter Password : ");
         patient->setPassword(password);
         if (CheckPassword(*patient)) break;
         PrintError("Wrong password Please type correct password !");
     }

     if (attempts >= 3) PrintError("Some thing went wrong Login Failed");
     if (!CheckPassword(*patient)) {
         delete patient;
         return;
     }
     this->currentLoggedInPatientIdx = Search(*patient);
    // delete patient;
}

void Patients::Update(int idx) {

}

void Patients::LoadData() {
    ifstream in;
    in.open(this->PATIENTS_FILEPATH , ios::in);
    if (in.fail() || IsEmptyFile(in)) {
        in.close();
        this->SaveData();
        return;
    }

    string aux;
    while (getline(in , aux , '\n')) {
        idx += 1;
        this->patients[idx] = Patient::StrToObj(aux);
    }
    in.close();
}


void Patients::SaveData() {
    ofstream out;
    out.open(this->PATIENTS_FILEPATH , ios::out);
    if (out.fail()){
        out.close();
        return;
    }

    for (int  i = 0 ; i < MAX && this->patients[i] != NULL ; i+= 1) out << *(patients[i]);
    out.close();
}

void Patients::Init() {
    this->idx =  -1;
    this->currentLoggedInPatientIdx = -1;
    this->patients = new Patient*[MAX];
    for (int  i = 0 ; i < MAX ; i += 1) patients[i] = NULL;
    LoadData();
}

bool Patients::SignUp_Helper(Patient **patient) {

    string cnic = GetCnic("Enter 13 digit Cnic Number : ");
    (*patient)->setCnicNumber(cnic);
    // Duplicate Check
    if (this->Search(cnic )) {
        PrintError("Account already exists please use signIn instead");
        return false;
    }

    string password =
            GetPassword("Enter password ( Password must be 8 characters , have one special character , uppercase , lowercase , and the numeric digit ) : ");
    (*patient)->setPassword(password);

        bool isEmailAlreadyTaken = false;
        do
    {
        string email = GetString("Enter Email Address : ");
        (*patient)->setEmail(email);
        isEmailAlreadyTaken = this->Search(**patient) != -1;
        if (isEmailAlreadyTaken)
            PrintError("OldaDoc account already exists on this email please use another email address");

    }
        while (isEmailAlreadyTaken);



    cout << "\n -- You're almost done with registration please provide some information about you :-) \n";

    string name = GetString("Enter you're name : ");
    (*patient)->setName(name);
    string contactNumber = GetContactNumber("Enter You're Contact Number : ");
    int age = GetInput<int>("Enter You're Age : ");

    cout << (*patient)->getBalance() << " has been added to you're account :- ) \n";

    (*patient)->setContactNumber(contactNumber);
    (*patient)->setAge(age);

    cout << "\n" << "\n -- Registration Succeed :-) ";
    cout << "\n -- Please use this userName and password to login";
    cout << "\n -- User Name : " << (*patient)->getEmail() ;
    cout << "\n -- Password  : " << (*patient)->getPassword() << "\n";

    return true;
}


bool Patients::CheckPassword(Patient &patient) {
    for (int  i = 0 ; i < MAX && this->patients[i] != NULL ; i += 1) {
        Patient* _patient = this->patients[i];
        if (_patient->getEmail() == patient.getEmail() && _patient->getPassword() == patient.getPassword())
            return true;
    }
    return false;
}

bool Patients::Search(Patient *patient) {
    for (int  i = 0 ; i < MAX && this->patients[i] != NULL ; i += 1)
        if(*(this->patients[i]) == *patient) return true;
    return false;
}

int Patients::Search(Patient &patient) {
    for (int  i = 0 ; i < MAX && this->patients[i] != NULL ; i += 1)
        if (*(this->patients[i]) == patient) return i;
    return -1;
}

Patient *Patients::Search(string cnicNumber) {
    for (int i = 0 ; i < MAX && this->patients[i] != NULL ; i += 1)
        if (this->patients[i]->getCnicNumber() == cnicNumber) return this->patients[i];
    return nullptr;
}

void Patients::Delete(int idx ) {
    if (this->patients[idx+1] == NULL) {
        delete this->patients[idx];
        this->patients[idx] = NULL;
        idx -= 1;
        return;
    }
    Swap(this->patients[idx] , this->patients[idx+1]);
    Delete(idx + 1 );
}

void Patients::Search() {
     for (int i = 0 ; i < MAX && this->patients[i] != NULL ; i +=1)
         this->patients[i]->Display();
}

bool Patients::Search(int idx) {
    for (int  i =0 ; i  < MAX  && this->patients[i] != NULL ; i += 1 )
        if (i == idx) return true;
    return false;
}

#endif //PAIDPROJECT_PATIENTS_H
