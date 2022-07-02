//
//
//

#ifndef DOCTORS_H
#define DOCTORS_H

#include "./Users.h"

#define MAX 100000

class Doctors;

class Doctors : public Users {
public:
    Doctors();

    /* OverRides */

    void SignUp() override;
    void SignIn() override;
    void Delete(string options = "") override;
    void Update(string options = "") override;
    void LoadData() override;
    void SaveData() override;

    /* Methods */

    int Search (Doctor& doctor) const; // returns => Idx of doctor in record
    int Search (string& doctorName) const; // returns => idx of element where name == doctorName
    bool Search (Doctor* doctor) const; // returns => doctor exists in record
    bool Search (string& match, string options) const; // Search functionality for (Specialty, Area, and Hospitals)
    bool Search (string& match1 , string& match2 , string options) const; // ..
    bool Search (string& specialty , string& area , string& hospital , bool matchAll = true) const; // ..
    bool Search (int idx);

    int currentLoggedInDoctorIdx;
    Doctor** doctors = NULL;
private:
    static const string DOCTORS_FILEPATH;

    // Helpers
    static void DisplayRow(int idx , Doctor& doctor); // display column of doctors
    static void DisplayRow (); // Displays top header

    void Init ();
    bool SignUp_Helper (Doctor** doctor);  // returns => sign up succeed
    bool CheckPassword (Doctor& doctor); // password checker
};

const string Doctors::DOCTORS_FILEPATH = "DOCTORS_DATA.text";

Doctors::Doctors() { this->Init(); }

void Doctors::SignUp() {
     Doctor* doctor = new Doctor();
     if (!SignUp_Helper(&doctor)) { // input Handler
         delete doctor;
         return;
     }
     this->idx += 1;
     this->currentLoggedInDoctorIdx = this->Search(*doctor);
     this->doctors[idx] = doctor;
     this->SaveData();
}

void Doctors::SignIn() {
     Doctor* doctor = new Doctor ();
     string userName = GetString("Enter User Name : ");
     doctor->setName(userName);
         if(!Search(&(*doctor)))
     {
         PrintError("User don't exists please use sign up instead !");
         return;
     }
        int attempts = 0;
        for ( ; attempts < 3 ; attempts += 1)
     {
         string password = GetString("Enter Password : ");
         doctor->setPassword(password);
         if (CheckPassword(*doctor)) break;
         PrintError("Wrong password Please type correct password !");
     }

     if (attempts >= 3) PrintError("Some thing went wrong Login Failed");

     // Password Check
     if (!CheckPassword(*doctor)) {
         delete doctor;
         return;
     }
     this->currentLoggedInDoctorIdx = Search(*doctor);
     delete doctor;
}

void Doctors::LoadData() {
    ifstream in;
    in.open(DOCTORS_FILEPATH , ios::in);
    if (in.fail() || IsEmptyFile(in)) {
        in.close();
        this->SaveData();
        return;
    }

    string aux;
    while (getline(in , aux , '\n')){
        idx += 1;
        this->doctors[idx] = Doctor::StrToObj(aux);
    }
    in.close();
}

void Doctors::SaveData() {
    ofstream out;
    out.open(DOCTORS_FILEPATH , ios::out);

    if (out.fail()) {
        out.close();
        return ;
    }

    for (int  i = 0 ; i < MAX && this->doctors[i] != NULL ; i += 1) out << *(this->doctors[i]);
    out.close();
}

void Doctors::Delete(string options ) {

}



/*  Helpers */

void Doctors::Init() {
    idx = -1;
    currentLoggedInDoctorIdx = -1;
    this->doctors = new Doctor*[MAX];
    for (int i = 0 ; i < MAX ; i += 1) this->doctors[i] = NULL;
    this->LoadData();
}

bool Doctors::SignUp_Helper(Doctor **doctor) {

    string email = GetEmail("Enter Email Address : ")
    , cnicNumber= GetCnic("Enter Cnic Number : ");
    (*doctor)->setEmail(email);
    (*doctor)->setCnicNumber(cnicNumber);

    // Duplicate Check
    if (this->Search(&(**doctor))) {
        PrintError("Account already exists please use signIn instead");
        return false;
    }

    // sign Up Logic
    string password = GetPassword
    ("Enter password ( Password must be 8 characters , have one special character , uppercase , lowercase , and the numeric digit ) : ") ,   name;
    (*doctor)->setPassword(password);

    bool isNameAlreadyTaken = false;
        do
    {
        name = GetString("Enter user name _ ");
        isNameAlreadyTaken = Search(name) != -1;
        if (isNameAlreadyTaken) PrintError("Name Already Taken please use new name ");
    }
        while (isNameAlreadyTaken);

    // gets doctor associated data
    cout << "\n -- You're almost done with registration please provide some information about you :-) \n";

    (*doctor)->InputSpecializationArea();
    (*doctor)->InputAvailableDays();

    int experienceYears = Clamp(GetInput<int>("How many years of experience you have _ ") , 0 , 100);
    string hospitalName  = GetString("Enter you're hospital name _ ")
    , city = GetString("Enter city name _ ");
    (*doctor)->InputAppointmentsTime();
    string accountNumber = GetAccountNumber("Enter you're account Number : " , 11);
    (*doctor)->setAccountNumber(accountNumber);
    cout << " -- Revenue will be send after appointment \n";
    double rates  = abs(GetInput<double>("Enter in person appointment rate _ "))
    , onLineRates = abs(GetInput<double>("Enter online appointment rate _ "));

    (*doctor)->setName(name);
    (*doctor)->setExperienceYears(experienceYears);
    (*doctor)->setCity(city);
    (*doctor)->setHospitalName(hospitalName);
    (*doctor)->setRates(rates);
    (*doctor)->setOnLineRates(onLineRates);

    cout << "\n -- Registration Succeed :-) ";
    cout << "\n -- Please use this userName and password to login";
    cout << "\n -- User Name : " << (*doctor)->getName() ;
    cout << "\n -- Password  : " << (*doctor)->getPassword() << "\n";

    return true;
}


bool Doctors::CheckPassword(Doctor &doctor) {
    for (int  i = 0 ; i < MAX && this->doctors[i] != NULL ; i += 1){
        Doctor* _doctor = this->doctors[i];
        if( _doctor->getPassword() == doctor.getPassword() && doctor.getName() == _doctor->getName()) return true;
    }

    return false;
}


void Doctors::Update(string options) {

}

/* Search Functionality */
// string specialty, string hospital, string area
bool Doctors::Search(string& match, string options) const {
    this->DisplayRow();
    bool isFound = false;
    if (options == "Specialty") {
        for (int i = 0; i < MAX && this->doctors[i] != NULL; i += 1)
            if (match == this->doctors[i]->getSpecializationArea()) {
                DisplayRow(i, *(this->doctors[i]));
                isFound = true;
            }
    }
    else if (options == "Area") {
        for (int i = 0; i < MAX && this->doctors[i] != NULL; i += 1)
            if (match == this->doctors[i]->getCity()) {
                DisplayRow(i, *(this->doctors[i]));
                isFound = true;
            }
    }
    else
        for (int i = 0 ; i < MAX && this->doctors[i] != NULL ; i += 1)
            if (match == this->doctors[i]->getHospitalName()){
                DisplayRow(i , *(this->doctors[i]));
                isFound = true;
            }
    return isFound;
}

// Search functionality (Specialty, Area, and Hospitals)
bool Doctors::Search(string& match1, string& match2, string options) const {
    this->DisplayRow();
    bool isFound = false;
        if(options == "Specialty+Area")
    {
        for (int i = 0; i < MAX && this->doctors[i] != NULL; i += 1)
            if (this->doctors[i]->getSpecializationArea() == match1 && this->doctors[i]->getCity() == match2){
                DisplayRow(i , *(this->doctors[i]));
                isFound = true;
            }
    }
        else if (options == "Area+Hospital")
    {
        for (int i = 0; i < MAX && this->doctors[i] != NULL; i += 1)
            if (this->doctors[i]->getCity() == match1 && this->doctors[i]->getHospitalName() == match2){
                DisplayRow(i , *(this->doctors[i]));
                isFound = true;
            }
    }
        else
    {
        for (int i = 0; i < MAX && this->doctors[i] != NULL; i += 1)
            if (this->doctors[i]->getSpecializationArea() == match1 && this->doctors[i]->getHospitalName() == match2){
                DisplayRow(i , *(this->doctors[i]));
                isFound = true;
            }
    }
     return isFound;
}

bool Doctors::Search(string& specialty, string& area, string& hospital, bool matchAll) const {
    this->DisplayRow();
    bool isFound = false;

          if (matchAll)
      {
          for (int i = 0; i < MAX && this->doctors[i] != NULL; i += 1)
              if (   this->doctors[i]->getSpecializationArea() == specialty
                  && this->doctors[i]->getCity() == area
                  && this->doctors[i]->getHospitalName() == hospital){
                  DisplayRow(i , *(this->doctors[i]));
                  isFound = true;
              }
      }
          else
          for (int i = 0; i < MAX && this->doctors[i] != NULL; i += 1)
              if (   this->doctors[i]->getSpecializationArea() == specialty
                     || this->doctors[i]->getCity() == area
                     || this->doctors[i]->getHospitalName() == hospital){
                  DisplayRow(i , *(this->doctors[i]));
                  isFound = true;
              }
      return isFound;
}

int Doctors::Search(string &doctorName) const{
    for (int  i = 0 ; i < MAX && this->doctors[i] != NULL ; i += 1)
        if (doctorName == this->doctors[i]->getName()) return i;
    return -1;
}

int Doctors::Search(Doctor &doctor) const {
    for (int  i = 0 ; i < MAX && this->doctors[i] != NULL ; i ++)
        if (doctor == *(this->doctors[i])) return i;
    return -1;
}

bool Doctors::Search(Doctor *doctor) const {
    for (int i = 0 ; i < MAX && this->doctors[i] != NULL ; i += 1 )
        if (*(this->doctors[i]) == *doctor) return true;
    return false;
}

bool Doctors::Search(int idx) {
     for (int i = 0 ; i < MAX && this->doctors[i] != NULL ; i += 1)
         if (idx == i) return true;
     return false;
}

void Doctors::DisplayRow(int idx, Doctor& doctor) {
    SetOffSet(idx, 9 , '|' );
    SetOffSet(doctor.getName() , 15 , '|');
    SetOffSet(doctor.getRating() , 6 , '|');
    SetOffSet(doctor.getSpecializationArea() , 13 , '|');
    SetOffSet(doctor.getHospitalName() , 12 , '|');
    SetOffSet(doctor.getCity() , 12 , '|');
    SetOffSet(doctor.IsAvailableToday() ? "YES" : "NO" , 10 , ' ');
    cout << "\n";
}

void Doctors::DisplayRow() {
    cout << "\n\n";
    SetOffSet("Serial No", 9 , '|' );
    SetOffSet("Doctor Name" , 15 , '|');
    SetOffSet("Rating" , 6 , '|');
    SetOffSet("Specialty" , 13 , '|');
    SetOffSet("Hospital" , 12 , '|');
    SetOffSet("Area" , 12 , '|');
    SetOffSet("Available Today" , 12 , ' ');
    cout << "\n";
}




#endif //DOCTORS_H
