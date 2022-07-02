//
// Created by 97152 on 02/06/2022.
//

#ifndef PATIENT_H
#define PATIENT_H

#include "./User.h"

class Patient : public User {
public:

    /* Constructor */
    Patient();

    Patient(const string &name, const string &cnicNumber, const string &password, const string &email,
    const string& contactNumber, double balance, int age);

    /* Getter Setter */
    double getBalance() const;
    void setBalance(double balance) ;
    int getAge() const ;
    void setAge(int age);
    string getContactNumber() const;
    void setContactNumber(const string& contactNumber);
    string getEmail() const;
    void setEmail(const string &email);

    /* Over Rides */
    void Update() override ;

    /* Methods */
    void ReChargeBalance ();
    void Display ();

    static Patient* StrToObj (string&);

    /* Operator OverLoading */

    friend ostream &operator<<(ostream &os, const Patient &patient);
    bool operator==(const Patient &rhs) const;
    bool operator!=(const Patient &rhs) const;
    friend ofstream &operator << (ofstream &outFile , const Patient& patient);

private:
    string email; // user name for login
    string contactNumber;
    double balance;
    int age;
};

/* Constructor */

Patient::Patient() {
    this->balance = 3500;
    this->age = 18;
}

Patient::Patient(const string &name, const string &cnicNumber, const string &password, const string &email,
                 const string& contactNumber, double balance, int age) : User(name, cnicNumber, password), email(email),
                 contactNumber(contactNumber), balance(balance),age(age) {}

/* Getter Setter */

double Patient::getBalance() const { return balance;}
void Patient::setBalance(double balance) { this->balance = balance;}
int Patient::getAge() const { return age;}
void Patient::setAge(int age) { this->age = age;}
string Patient::getContactNumber() const { return contactNumber;}
void Patient::setContactNumber(const string &contactNumber) { this->contactNumber = contactNumber;}
string Patient::getEmail() const { return email; }
void Patient::setEmail(const string &email) { this->email = email;}

bool Patient::operator==(const Patient &rhs) const { return this->cnicNumber == cnicNumber || email == rhs.email; }
bool Patient::operator!=(const Patient &rhs) const { return !(rhs == *this);}

/* Over Rides */
void Patient::Update() {
      cout << "\n -- Update Menu \n";
      cout << "  - Edit Contact Number - 1 \n";
      cout << "  - Edit age            - 2 \n";
      cout << "  - Edit Name           - 3 \n";
      cout << "  - Reset Password      - 4 \n";
      cout << "  - Exit                - 5 \n";
      int choice = GetInput<int>(" Enter Choice _ ");
      switch (choice)
    {
        case 1:
            this->contactNumber = GetContactNumber(" Enter new Contact Number : ");
            break;
        case 2:
            this->age = GetInput<int>("Enter correct age : ");
            break;
        case 3:
            this->name = GetString("Enter new Name : ");
            break;
        case 4:
            this->password = GetPassword("Enter new Password");
            break;
        default:
            cout << " -- Never Mind \n";
    }
}

/* Methods */
void Patient::ReChargeBalance() { }

/* Operator OverLoading */
ostream &operator<<(ostream &os, const Patient &patient) {
    PrintChar('-' , 100);
#define OffSet SetOffSet(2)
    OffSet; os << "Name           : " << patient.name << "\n";
    OffSet; os << "Age            : " << patient.age << "\n";
    OffSet; os << "Contact Number :  " << patient.contactNumber << "\n";
#undef OffSet
    return os;
}

// File Write
ofstream &operator << (ofstream &outFile , const Patient& patient) {
    outFile << patient.name << reserveSeparator
    << patient.cnicNumber << reserveSeparator
    << patient.password << reserveSeparator
    << patient.age << reserveSeparator
    << patient.balance << reserveSeparator
    << patient.contactNumber << reserveSeparator
    << patient.email << "\n";
    return outFile;
}

// File Read
Patient *Patient::StrToObj(string &str) {
    string aux [7];
    int idx  = 0 ;
    for (int i = 0 ; i < str.length() ; i += 1)
        if (str[i] == reserveSeparator) idx += 1;
        else aux[idx].push_back(str[i]);

    Patient* patient = new Patient();
    patient->name = Replace(aux[0] , '_' , ' ');
    patient->cnicNumber = aux[1];
    patient->password = aux[2];
    patient->age = stoi(aux[3]);
    patient->balance = stod(aux[4]);
    patient->contactNumber = aux[5];
    patient->setEmail(aux[6]);
    return patient;
}

void Patient::Display() {
     cout << *this;
     SetOffSet(2); cout << "Cnic Number    : " << this->cnicNumber << "\n";
     SetOffSet(2); cout << "Email Address  : " << this->email << "\n";
     SetOffSet(2); cout << "Password       : " << this->password << "\n";
     SetOffSet(2); cout << "Balance        : " << this->balance << "\n";
     PrintChar('-' , 100);
}

#endif //PATIENT_H
