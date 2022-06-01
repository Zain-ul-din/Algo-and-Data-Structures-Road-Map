//
// Dependencies : User.h
//

#ifndef DOCTOR_H
#define DOCTOR_H

#include <iostream>
#include "./User.h"

using namespace std;

enum class Specialization{
    Gynecologist  ,
    Dermatologist ,
    Oncologist ,
    Orthopedic
};



class Doctor : public User {
public:
    /* Constructor */

    Doctor();
    Doctor(const string &name, const string &cnicNumber, const string &password, const string &email,
           int experienceYears, const string &hospitalName, const string &city, const string &specializationArea,
           int startingHour, int endingHours, double rates, double onLineRates);

    /* Getter Setter */

    const string getEmail() const;
    void setEmail(const string &email);
    int getExperienceYears() const;
    void setExperienceYears(int experienceYears);
    const string getHospitalName() const;
    void setHospitalName(const string &hospitalName);
    const string getCity() const;
    void setCity(const string &city);
    const string getSpecializationArea() const;
    void setSpecializationArea(const string &specializationArea);
    int getStartingHour() const;
    void setStartingHour(int startingHour);
    int getEndingHours() const;
    void setEndingHours(int endingHours);
    double getRates() const;
    void setRates(double rates);
    double getOnLineRates() const;
    void setOnLineRates(double onLineRates);

    /* Operator OverLoading */

   bool operator==(const Doctor &rhs) const;
   bool operator!=(const Doctor &rhs) const;

   /* IO */
   friend ostream &operator << (ostream &os, const Doctor &doctor);

   static const std::string SpecializationList[4] ;
   static string GetSpecializationByIdx (int );
private:
    string email;
    int experienceYears;
    string hospitalName   , city;
    string specializationArea;
    int startingHour , endingHours ; // 24 hours clock format
    double rates , onLineRates; // appointment rates

};

const std::string Doctor::SpecializationList[4] = { "Gynecologist" , "Dermatologist" , "Oncologist" , "Orthopedic" };
string Doctor::GetSpecializationByIdx(int idx) {
    if (idx >= 0 && idx < 4) return SpecializationList[idx];
    return "NULL";
}

/* Constructor */

Doctor::Doctor() {
    this->email = "undefined";
    this->specializationArea = SpecializationList[0];
    this->experienceYears = 0;
    this->city = "undefined";
    this->hospitalName = "undefined";
    this->startingHour = 0;
    this->endingHours = 0;
    this->rates  = 0;
    this->onLineRates = 0;
}

Doctor::Doctor(const string &name, const string &cnicNumber, const string &password, const string &email,
               int experienceYears, const string &hospitalName, const string &city, const string &specializationArea,
               int startingHour, int endingHours, double rates, double onLineRates) : User(name, cnicNumber, password),
                                                                                      email(email),
                                                                                      experienceYears(experienceYears),
                                                                                      hospitalName(hospitalName),
                                                                                      city(city), specializationArea(
                specializationArea), startingHour(startingHour), endingHours(endingHours), rates(rates),
                                                                                      onLineRates(onLineRates) {}

/* Getter Setter */

const string Doctor::getEmail() const { return email;}
void Doctor::setEmail(const string &email) {this->email = email;}
int Doctor::getExperienceYears() const {return experienceYears;}
void Doctor::setExperienceYears(int experienceYears) {this->experienceYears = experienceYears;}
const string Doctor::getHospitalName() const { return hospitalName;}
void Doctor::setHospitalName(const string &hospitalName) { this->hospitalName = hospitalName;}
const string Doctor::getCity() const { return city;}
void Doctor::setCity(const string &city) { this->city = city;}
const string Doctor::getSpecializationArea() const { return specializationArea;}
void Doctor::setSpecializationArea(const string &specializationArea) {this->specializationArea = specializationArea;}
int Doctor::getStartingHour() const { return startingHour;}
void Doctor::setStartingHour(int startingHour) {this->startingHour = startingHour;}
int Doctor::getEndingHours() const {return endingHours;}
void Doctor::setEndingHours(int endingHours) {this->endingHours = endingHours;}
double Doctor::getRates() const { return rates; }
void Doctor::setRates(double rates) { this->rates = rates; }
double Doctor::getOnLineRates() const { return onLineRates; }
void Doctor::setOnLineRates(double onLineRates) { this->onLineRates = onLineRates;}

/* Operator OverLoading */

bool Doctor::operator == (const Doctor &rhs) const { return this->email == rhs.email || this->cnicNumber == rhs.email || this->name == rhs.name;}
bool Doctor::operator!=(const Doctor &rhs) const { return !(rhs == *this);}

ostream &operator<<(ostream &os, const Doctor &doctor) {
    return os;
}




#endif //DOCTOR_H
