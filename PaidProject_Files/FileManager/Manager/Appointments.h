//
//
//

#ifndef APPOINTMENTS_H
#define APPOINTMENTS_H

#include "../Users/Appointment.h"
#include "../Users/Payment.h"

#define MAX 100000

class Appointments  {
public:
    Appointments();

    Appointment** appointments;

    void LoadData ();
    void SaveData ();

    void MakeAppointment (Doctor& doctor, Patient& patient);

    bool Search (Doctor& doctor , Patient& patient , Time& appointmentTime); // returns true if appointment time is same
    int Search (Doctor& doctor); // Returns count of new appointments
    Appointment* Search (const int idx); // Find Appointment by idx
    int Search (Patient& patient);

    void Print (int idx , Doctor& doctor , Appointment& appointment);
    void Print (int idx , Patient& patient , Appointment& appointment);
    void Print (string user);
    void Print (Doctor& doctor , int max); // feedbacks

    void Delete (Patient& patient);
    void Delete (int index);
    void Delete (Doctor& doctor);
    void Delete (Patient& patient , int flag);

    void CalculateRating (Doctor& doctor);

    int idx ;
private:
    static string APPOINTMENTS_FILEPATH ;
};

string Appointments::APPOINTMENTS_FILEPATH = "APPOINTMENTS_DATA.text";

Appointments::Appointments() {
     this->idx = -1;
     this->appointments = new Appointment*[MAX];
     for (int i = 0 ; i < MAX ; i += 1)
         this->appointments[i] = NULL;
     this->LoadData();
}

void Appointments::LoadData() {
     ifstream in;
     in.open(APPOINTMENTS_FILEPATH , ios::in);
     if (in.fail() || IsEmptyFile(in)) {
         in.close();
         this->SaveData();
         return;
     }
     string aux;
     while (getline(in , aux , '\n')){
       idx += 1;
       this->appointments[idx] = Appointment::StrToObj(aux);
     }
    in.close();
}

void Appointments::SaveData() {
    ofstream out;
    out.open(APPOINTMENTS_FILEPATH , ios::out);
    if (out.fail()) {
        out.close();
        return;
    }
    for (int i = 0 ; i < MAX && this->appointments[i] != NULL ; i +=1)
        out << *(this->appointments[i]);
    out.close();
}

void Appointments::MakeAppointment(Doctor &doctor, Patient& patient) {
     cout << "\n -- Terms and Polices :- \n";
     cout << "\n  - You can refund you're appointment fee at any time but there are some policy you should follow along \n";
     cout << "    - 0 day policy  : full money return \n";
     cout << "    - 1 day policy  : 60%  money return \n";
     cout << "    - 2 days policy : 30% money return \n";
     cout << "    - 3 days policy : 0% money return \n";

    if (!GetChoice("\n    >> I Agree with Polices : Y/N : ")) return;

     Appointment appointment;
     Appointment * appointmentObj = appointment.MakeAppointment(doctor , patient);
     Time _time = appointmentObj->getAppointmentTime();
     if (Search(doctor , patient , _time)){
         PrintError("You can't have two appointments at a same time with same doctor !! ");
         delete appointmentObj;
         return;
     }

     double appointmentFee = appointment.getAppointmentType() == "in-person" ? doctor.getRates() : doctor.getOnLineRates();

     if (appointmentFee > patient.getBalance()) {
         while (appointmentFee > patient.getBalance()) {
             PrintError("Insufficient funds ");
             if (GetChoice("Do You wanna to Recharge You're Account : ")) {
                 patient.setBalance(patient.getBalance() + Payment::ReChargeAccount());
             } else{
                 cout << "Appointment Canceled \n";
                 delete appointmentObj;
                 return;
             }

             if (patient.getBalance() > appointmentFee) {
                 cout << "\n -- Doctor Fee : " << appointmentFee << "\n";
                 cout << "\n -- In Account : " << patient.getBalance() << "\n";
                 patient.setBalance(patient.getBalance() - appointmentFee);
                 cout << "\n -- Remaining Balance : " << patient.getBalance() << "\n";
             }
         }
     } else{
         cout << "\n -- Doctor Fee : " << appointmentFee << "\n";
         cout << "\n -- In Account : " << patient.getBalance() << "\n";
         if (!GetChoice("\n >> Do You wanna to pay fee Y/N :")) {
             cout << "Appointment Canceled \n";
             delete appointmentObj;
             return;
         }
         patient.setBalance(patient.getBalance() - appointmentFee);
         cout << "\n -- Remaining Balance : " << patient.getBalance() << "\n";
     }
     idx += 1;
     this->appointments[idx] = appointmentObj;
     cout << "\n -- Appointment Succeed from olaDoc side  \n";
     this->SaveData();
}

bool Appointments::Search(Doctor &doctor, Patient &patient, Time &appointmentTime) {
    for (int  i = 0 ; i < MAX && this->appointments[i] != NULL ; i += 1)
        if (doctor.getCnicNumber() == this->appointments[i]->getDoctorCnic() && patient.getCnicNumber() == this->appointments[i]->getPatientCnic())
            if (appointmentTime == this->appointments[i]->getAppointmentTime())
                return true;
    return false;
}

void Appointments::Print(int idx, Doctor &doctor , Appointment& appointment) {
    SetOffSet(idx, 9 , '|');
    SetOffSet(doctor.getName() , 12 , '|');
    SetOffSet(doctor.getEmail() , 25 , '|');
    SetOffSet(appointment.getAppointmentStatus() , 10 , '|');
    SetOffSet(appointment.getAppointmentType() , 10 , '|');
    SetOffSet(appointment.getRating() , 7 , '|');
    SetOffSet(appointment.getAppointmentTime() , 17 , ' ');
    cout << "\n";
}

void Appointments::Print(int idx, Patient &patient , Appointment& appointment) {
    SetOffSet(idx , 9 , '|');
    SetOffSet(patient.getName() , 12 , '|');
    SetOffSet(patient.getContactNumber() , 25 , '|');
    SetOffSet(appointment.getAppointmentStatus() , 10 , '|');
    SetOffSet(appointment.getAppointmentType() , 10 , '|');
    SetOffSet( patient.getAge() , 8 , '|');
    SetOffSet(appointment.getRating() , 7 , '|');
    SetOffSet(appointment.getAppointmentTime() , 17 , ' ');
    cout << "\n";
}

// Patient | Doctor
void Appointments::Print(string user) {
    cout << "\n\n";
    SetOffSet("Serial no" , 9 , '|');
    SetOffSet(user , 12 , '|');
    SetOffSet("Contact" , 25 , '|');
    SetOffSet("Status" , 10 , '|');
    SetOffSet("Type" , 10 , '|');
    if (user == "Patient") SetOffSet("Age" , 8 , '|');
    SetOffSet("Rating" , 7 , '|');
    SetOffSet("Timing" , 17 , ' ');
    cout << "\n";
}

int Appointments::Search(Doctor &doctor) {
    int count = 0;
    for (int  i = 0 ; i < MAX && this->appointments[i] != NULL ; i += 1)
        if (doctor.getCnicNumber() == this->appointments[i]->getDoctorCnic() && this->appointments[i]->getAppointmentStatus() == "pending") count += 1;
    return count;
}

Appointment *Appointments::Search(const int idx) {
    for (int i = 0 ; i < MAX && this->appointments[i] != NULL ; i += 1)
        if (i == abs(idx)) return this->appointments[i];
    return NULL;
}

int Appointments::Search(Patient &patient) {
    int count = 0;
    for (int  i = 0 ; i < MAX && this->appointments[i] != NULL ; i += 1)
        if (patient.getCnicNumber() == this->appointments[i]->getPatientCnic() && !this->appointments[i]->IsSeen()) count += 1;
    return count;
}

void Appointments::Print(Doctor &doctor , int max) {
    cout << " \n\t -- Other Patients FeedBack About this Doctor :- \n";
    int maxCount = max;
    bool isFound = false;
    int i = this->idx + 1;
    while (i--)
        if (this->appointments[i]->getDoctorCnic() == doctor.getCnicNumber() && this->appointments[i]->getFeedBack() != "undefined") {
            if (maxCount == 0) return;
            maxCount -= 1;
            cout << "\n\t \"\" " << this->appointments[i]->getFeedBack() << " \"\" \n";
            isFound = true;
        }
    if (!isFound)
        cout << "\n\t !! No feedback so far !! \n";
    cout << "\n";
}

void Appointments::Delete(Patient& patient) {
     for (int i = 0 ; i < MAX && this->appointments[i] != NULL ; i += 1)
         if (this->appointments[i]->IsDeleted()) {
             double refunds = this->appointments[i]->getAppointmentCost();
             patient.setBalance(patient.getBalance() + this->appointments[i]->getAppointmentCost());
             cout << "\n -- " << refunds << " RS has been refund to you're account \n";
             cout << "\n -- Current Balance : " << patient.getBalance() << "\n";
             Delete(i);
         }
     this->SaveData();
}

void Appointments::Delete(int index) {
    if (this->appointments[index + 1] == NULL ){
        this->idx -= 1;
        delete this->appointments[index];
        this->appointments[index] = NULL;
        return;
    }
    Swap(this->appointments[index] , this->appointments[index + 1]);
    Delete(index + 1);
}

void Appointments::Delete(Doctor &doctor) {
     for (int i = 0 ; i < MAX && this->appointments[i] != NULL ; i += 1)
         if (this->appointments[i]->getDoctorCnic() == doctor.getCnicNumber())
             this->Delete(i);
}

void Appointments::Delete(Patient &patient, int flag) {
    for (int i = 0 ; i < MAX && this->appointments[i] != NULL ; i += 1)
        if (this->appointments[i]->getPatientCnic() == patient.getCnicNumber())
            this->Delete(i);
}

void Appointments::CalculateRating(Doctor &doctor) {
    float rating = 0;
    int count;
     for (int i = 0 ; i < MAX && this->appointments[i] != NULL ; i += 1)
         if (doctor.getCnicNumber() == this->appointments[i]->getDoctorCnic()) {
             rating += this->appointments[i]->getRating();
             count += 1;
         }
     double  finalRating = rating / count;
     doctor.setRates(finalRating);
}

#endif //APPOINTMENTS_H
