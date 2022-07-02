//
//
//

#ifndef APPOINTMENT_H
#define APPOINTMENT_H


#include "./Doctor.h"
#include "./Patient.h"

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
    Time getApplyTime() const;
    void setApplyTime(const Time &applyTime);
    bool IsDeleted ();
    string Input (const string options);
    void Update (string options);

    friend ofstream & operator << (ofstream&, Appointment&);

    static Appointment* StrToObj (string&);
    static Appointment* MakeAppointment ( Doctor& doctor, Patient& patient );

private:
    string doctorCnic , patientCnic;
    double appointmentCost;
    Time applyTime;
    Time appointmentTime;
    string appointmentType;
    string appointmentStatus;
    bool isSeen;
    string feedBack;
    float rating;
    bool isDeleted;

private:
    static string appointmentsStatus[3];
    static string appointmentTypes [2];
};

ofstream & operator << (ofstream& outFile , Appointment& appointment) {
    outFile << appointment.doctorCnic << reserveSeparator
    << appointment.patientCnic << reserveSeparator
    << appointment.appointmentCost << reserveSeparator
    << Replace(appointment.appointmentTime.getTimeStr())<< reserveSeparator
    << appointment.appointmentType << reserveSeparator
    << appointment.appointmentStatus << reserveSeparator
    << appointment.isSeen << reserveSeparator
    << Replace(appointment.feedBack) << reserveSeparator
    << appointment.rating << reserveSeparator
    << Replace(appointment.applyTime.getTimeStr()) << "\n";
    return outFile;
}

Appointment *Appointment::StrToObj(string& str) {
    string aux [10];
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
    string applyTimeStr = Replace(aux[9] , '_' , ' ');
    appointment->applyTime = Time(applyTimeStr);
    return appointment;
}

string Appointment::appointmentsStatus[3] = { "approved" , "pending" , "reject" };
string Appointment::appointmentTypes [2]  = {"in-person" , "online"};

Appointment::Appointment() {
    this->doctorCnic = "0";
    this->patientCnic = "0";
    this->appointmentCost = 0;
    this->appointmentType = appointmentTypes[0];
    this->appointmentStatus = appointmentStatus[1];
    this->isSeen = true;
    this->feedBack = "undefined";
    this->rating = 0;
    this->isDeleted = false;
}

// Doctor | Patient
void Appointment::Update(string options) {

   if (options == "Doctor") {
       int choice = 0;
       for ( ; choice != 2; ) {
           cout << "\n -- Appointment Update \n";
           cout << "\n  - Change Appointment Status - 0 \n";
           cout << "\n  - Change Appointment Timing - 1 \n";
           cout << "\n  - Exit                      - 2 \n";
           choice = GetInput<int>("Enter Choice : ");
           switch (choice) {
               case 0:
                   this->appointmentStatus = Input("appointmentStatus");
                   this->isSeen = false;
                   break;
               case 1:
                   this->appointmentTime = GetTime(" >> Enter Time :- ", "Time must be greater then time now !! ");
                   this->isSeen = false;
                   break;
               case 2:
                   cout << " -- Exit \n";
                   break;
               default:
                   PrintError("Invalid Choice !!");
           }
           system("pause");
           system("cls");
       }
   }
   else 
   {
      int choice = 0;
      double refunds = 0;
      for ( ; choice != 3; ) {
          cout << "\n -- Appointment Update \n";
          cout << "\n  - Send FeedBack           - 0 ( recommended )\n";
          cout << "\n  - rating                  - 1 ( recommended )\n";
          cout << "\n  - Cancel Appointment      - 2\n";
          cout << "\n  - Exit                    - 3\n";
          choice = GetInput<int>("Enter Choice : ");
          Time timeNow;
          switch (choice) {
              case 0:
                  if (this->feedBack != "undefined") {
                      PrintError("You Already sent a feedback");
                      break;
                  }
                  if (timeNow > this->appointmentTime)
                      this->feedBack = GetString("Enter FeedBack : ");
                  else cout << "\n You can send feedback after appointment \n";
                  break;
              case 1:
                  if (this->rating != 0) {
                      PrintError("You Already rated this doctor");
                      break;
                  }
                  if (timeNow > this->appointmentTime)
                      this->rating = GetInputInRange(1 , 5 , "Rate (1-5) : " , "Invalid input !");
                  else cout << "\n You can rate after appointment \n";
                  break;
              case 2:
                  if (timeNow.getDay() - applyTime.getDay() == 0 ) {
                      refunds = this->appointmentCost;
                      cout << "\n -- " << refunds << " will be refund to you  -0% 0 day policy \n";
                  }
                  else if (timeNow.getDay() - applyTime.getDay() == 1) {
                      refunds = GetPercentageOf(this->appointmentCost , 60);
                      cout << "\n -- " << refunds << " will be refund to you 60%  1 day policy\n";
                  }
                  else if (timeNow.getDay() - applyTime.getDay() == 2) {
                      refunds = GetPercentageOf(this->appointmentCost , 30);
                      cout << "\n -- " << refunds << " will be refund to you 30% 2 days policy\n";
                  }
                  else cout << "\n -- " << " -- no money will be refund to you 3 days has been passed - 100 _ 3 days policy \n";
                  if (GetChoice("\n >> Do You want to cancel appointment Y/N : ")) {
                      isDeleted = true;
                      refunds = 0;
                      this->appointmentCost = refunds;
                      cout << "\n -- Appointment has been cancelled \n";
                      choice = 3;
                  }
                  break;
              case 3:
                   cout << "\n -- Exit \n";
                  break;
              default:
                  PrintError("Invalid Choice !!");
          }
          system("pause");
          system("cls");
      }
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
Time Appointment::getApplyTime() const { return applyTime;}
void Appointment::setApplyTime(const Time &applyTime) { this->applyTime = applyTime;}
bool Appointment::IsDeleted() { return this->isDeleted;}

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
        cout << " -- Select Appointment Type \n";
        for (int i = 0 ; i < 2 ; i += 1)
            cout << "  - " << appointmentTypes[i] << " - " << i << "\n";
        int idx = GetInputInRange(0 , 1 , "Enter Choice : " , "Invalid Choice");
        return appointmentTypes[idx];
    }
}

Appointment *Appointment::MakeAppointment(Doctor &doctor, Patient &patient) {
     cout << "\n\n";
     Appointment* appointment = new Appointment();
     appointment->doctorCnic = doctor.getCnicNumber();
     appointment->patientCnic = patient.getCnicNumber();
     appointment->appointmentType = appointment->Input("appointmentType");
     appointment->appointmentCost = appointment->appointmentType == "in-person" ? doctor.getRates() : doctor.getOnLineRates();

     Time timeNow , inputTime = GetTime(" >> Enter Time :- " , "Time must be greater then time now !! ");
     cout << inputTime << "\n";
     if(GetChoice("\n -- Set time to now for testing __ OlaDoc Developers Y/N : "))
         appointment->appointmentTime = timeNow;
     else appointment->appointmentTime = inputTime;
     appointment->applyTime = timeNow;
     appointment->appointmentStatus = "pending";
     cout << "\n-- You're Appointment is pending wait for doctor reply \n";
     return appointment;
}




#endif //APPOINTMENT_H
