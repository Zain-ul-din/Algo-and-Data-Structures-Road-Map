//
// Dependencies : SaveSystem.h
//

#ifndef USERS_H
#define USERS_H

#include "../FileManager/SaveSystem.h"
#include "../Helpers/Input.h"
#include "../Helpers/ErrorHandler.h"

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
