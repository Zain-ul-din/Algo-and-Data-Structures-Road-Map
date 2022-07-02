//
// Dependencies : NONE
//

#ifndef USERS_H
#define USERS_H

#include "../Users/Doctor.h"
#include "../Users/Patient.h"
#include "../Users/Appointment.h"

class Users;

class Users {
public:

    virtual void SignUp () = 0;
    virtual void SignIn () = 0;

    virtual void Delete(string options = "") = 0;
    virtual void Update(string options = "") = 0;

    virtual void LoadData () = 0;
    virtual void SaveData () = 0;

    int idx = 0 ;
};

#endif //USERS_H
