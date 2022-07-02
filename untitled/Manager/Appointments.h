//
//
//

#ifndef APPOINTMENTS_H
#define APPOINTMENTS_H

#include "../Users/Appointment.h"

#define MAX 100000

class Appointments  {
public:
    Appointments();

    Appointment** appointments;

    void LoadData ();
    void SaveData ();


private:
    int idx ;
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
    out.open(APPOINTMENTS_FILEPATH , ios::in);
    if (out.fail()) {
        out.close();
        return;
    }
    for (int i = 0 ; i < MAX && this->appointments[i] != NULL ; i +=1)
        out << *(this->appointments[i]);
    out.close();
}


#endif //APPOINTMENTS_H
