//
// Dependencies :- NONE
//
#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

// @ User Base Class
class User {
public:
    /* Constructor */

    User(const string &name, const string &cnicNumber, string password) : name(name),
                                                                                          cnicNumber(cnicNumber),
                                                                                          password(password) {}
    User() {
        this->name = name;
        this->cnicNumber = "";
        this->password = "";
    }

    /* Getter &  Setter's */

    string getName() const { return name; }
    void setName(const string &name) { this->name = name;}
    string getCnicNumber() const { return cnicNumber;}
    void setCnicNumber(const string &cnicNumber) { this->cnicNumber = cnicNumber;}
    string getPassword() const { return password;}
    void setPassword(const string &password) { this->password = password;}
    void setAdmin (bool state){this->isAdmin = state;}
    bool IsAdmin () const {return this->isAdmin;}

    /* Virtual Functions */

protected:
    string name;
    string cnicNumber;
    string password;
    bool isAdmin = false;
};

#endif //USER_H
