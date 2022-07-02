//
// Dependencies :- NONE
//
#ifndef USER_H
#define USER_H


#include "../Login/Validator.h"
#include "../FileManager/SaveSystem.h"
#include "../Helpers/Time.h"

using namespace std;

// @ User Base Class
class User {
public:
    /* Constructor */

    User(const string &name, const string &cnicNumber, string password) : name(name),
    cnicNumber(cnicNumber),
    password(password) {}

    User() {
        this->name = "undefined";
        this->cnicNumber = "undefined";
        this->password = "undefined";
    }

    /* Getter &  Setter's */

    string getName() const { return name; }
    void setName(const string &name) { this->name = name;}
    string getCnicNumber() const { return cnicNumber;}
    void setCnicNumber(const string &cnicNumber) { this->cnicNumber = cnicNumber;}
    string getPassword() const { return password;}
    void setPassword(const string &password) { this->password = password;}


    /* Virtual Functions */

    virtual void Update () = 0;
protected:
    string name;
    string cnicNumber;
    string password;
};

#endif //USER_H
