//
//
//

#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include "User.h"


class Appointment {
public:

    Appointment();
    Appointment(const string &doctorCnic, const string &patientCnic, double appointmentCost,
    const Time &appointmentTime, const string &appointmentType, const string &appointmentStatus,
    bool isSeen, const string &feedBack , float rating);

    string getDoctorCnic() const;
    void setDoctorCnic(const string &doctorCnic);
    string getPatientCnic() const;
    void setPatientCnic(const string &patientCnic);
    double getAppointmentCost() const;
    void setAppointmentCost(double appointmentCost);
    Time getAppointmentTime() const;
    void setAppointmentTime(const Time &appointmentTime);
    string getAppointmentType() const;
    void setAppointmentType(const string &appointmentType);
    string getAppointmentStatus() const;
    void setAppointmentStatus(const string &appointmentStatus);
    void setIsSeen(bool isSeen);
    string getFeedBack() const;
    void setFeedBack(const string &feedBack);
    bool IsSeen() const;
    float getRating() const;
    void setRating(float rating);

    string Input (const string options);
    void Update (string options);

    friend ofstream & operator << (ofstream&, Appointment&);
    static Appointment* StrToObj (string&);

    static Appointment* MakeAppointment ( User& doctor, User& patient );

private:
    string doctorCnic , patientCnic;
    double appointmentCost;
    Time appointmentTime;
    string appointmentType;
    string appointmentStatus;
    bool isSeen;
    string feedBack;
    float rating;
private:
    static string appointmentsStatus[3];
    static string appointmentTypes [2];
};

ofstream & operator << (ofstream& outFile , Appointment& appointment) {
    outFile <<""<< appointment.doctorCnic << reserveSeparator
    << appointment.patientCnic << reserveSeparator
    << appointment.appointmentCost << reserveSeparator
    << appointment.appointmentTime << reserveSeparator
    << appointment.appointmentType << reserveSeparator
    << appointment.appointmentStatus << reserveSeparator
    << appointment.isSeen << reserveSeparator
    << Replace(appointment.feedBack) << reserveSeparator
    << appointment.rating << "\n";
    return outFile;
}

Appointment *Appointment::StrToObj(string& str) {
    string aux [9];
    int idx = 0;
    for (int i = 0 ; i < str.length() ; i += 1 )
        if (str[i] == reserveSeparator)
            idx += 1;
        else aux[idx].push_back(str[i]);

    Appointment* appointment = new Appointment();
    appointment->setDoctorCnic(aux[0]);
    appointment->setPatientCnic(aux[1]);
    appointment->setAppointmentCost(stod(aux[2]));
    string timeStr = Replace(aux[3] , '_' , ' ');
    appointment->appointmentTime = Time(timeStr);
    appointment->appointmentType = aux[4];
    appointment->appointmentStatus = aux[5];
    appointment->isSeen = aux[6] == "1";
    appointment->feedBack = Replace(aux[7] , '_' , ' ');
    appointment->rating = stof(aux[8]);
}

string Appointment::appointmentsStatus[3] = { "approved" , "pending" "reject" };
string Appointment::appointmentTypes [2]  = {"in-person" , "online"};

Appointment::Appointment() {
    this->doctorCnic = "0";
    this->patientCnic = "0";
    this->appointmentCost = 0;
    this->appointmentType = appointmentTypes[0];
    this->appointmentStatus = appointmentStatus[1];
    this->isSeen = false;
    this->feedBack = "undefined";
    this->rating = 0;
}

// Doctor | Patient
void Appointment::Update(string options) {
   if (options == "Doctor") {
       cout << "\n -- Appointment Update \n";
       cout << "\n  - Change Appointment Status - 0 \n";
       cout << "\n  - Change Appointment Timing - 1 \n";
       cout << "\n  - Exit                      - 1 \n";
       int choice = GetInput<int>("Enter Choice : ");
       switch (choice) {
           case 0:
               this->appointmentStatus = Input("appointmentsStatus");
           break;
           case 1:
               cout << " -- Exit \n";
           break;
           default:
               PrintError("Invalid Choice !!");
       }
   }
   else 
   {
      cout << "\n -- Appointment Update \n";
      cout << "\n  - Edit FeedBack     - 0 \n";
      cout << "\n  - Edit rating       - 1 \n";
   }
}


Appointment::Appointment(const string &doctorCnic, const string &patientCnic, double appointmentCost,
           const Time &appointmentTime, const string &appointmentType, const string &appointmentStatus,
           bool isSeen, const string &feedBack , float rating) : doctorCnic(doctorCnic), patientCnic(patientCnic),
           appointmentCost(appointmentCost),appointmentTime(appointmentTime) ,appointmentType(appointmentType),
           appointmentStatus(appointmentStatus), isSeen(isSeen),feedBack(feedBack) , rating(rating) {}

string Appointment::getDoctorCnic() const {return doctorCnic;}
void Appointment::setDoctorCnic(const string &doctorCnic) {this->doctorCnic = doctorCnic;}
string Appointment::getPatientCnic() const {return patientCnic;}
void Appointment::setPatientCnic(const string &patientCnic) {this->patientCnic = patientCnic;}
double Appointment::getAppointmentCost() const {return appointmentCost;}
void Appointment::setAppointmentCost(double appointmentCost) {this->appointmentCost = appointmentCost;}
Time Appointment::getAppointmentTime() const {return appointmentTime;}
void Appointment::setAppointmentTime(const Time &appointmentTime) {this->appointmentTime = appointmentTime;}
string Appointment::getAppointmentType() const {return appointmentType;}
void Appointment::setAppointmentType(const string &appointmentType) {this->appointmentType = appointmentType;}
string Appointment::getAppointmentStatus() const {return appointmentStatus;}
void Appointment::setAppointmentStatus(const string &appointmentStatus) {this->appointmentStatus = appointmentStatus;}
void Appointment::setIsSeen(bool isSeen) {this->isSeen = isSeen;}
string Appointment::getFeedBack() const { return feedBack;}
void Appointment::setFeedBack(const string &feedBack) {this->feedBack = feedBack;}
bool Appointment::IsSeen() const { return isSeen;}
float Appointment::getRating() const {return rating;}
void Appointment::setRating(float rating) { this->rating = rating;}

// appointmentsStatus | appointmentType
string Appointment::Input(const string options) {
        if (options == "appointmentStatus")
    {
        cout << " -- Select Appointment Status \n";
        for (int i = 0 ; i < 3 ; i += 1)
            cout << "  - " << appointmentsStatus[i] << " - " << i << "\n";
        int idx = GetInputInRange(0 , 2 , "Enter Choice : " , "Invalid Choice");
        return appointmentsStatus[idx];
    }
        else
    {
        cout << " -- Select Appointment Types \n";
        for (int i = 0 ; i < 2 ; i += 1)
            cout << "  - " << appointmentTypes[i] << " - " << i << "\n";
        int idx = GetInputInRange(0 , 1 , "Enter Choice : " , "Invalid Choice");
        return appointmentTypes[idx];
    }
}

Appointment *Appointment::MakeAppointment(User &doctor, User &patient) {
    Appointment* appointment = new Appointment();

    
}


#endif //APPOINTMENT_H
