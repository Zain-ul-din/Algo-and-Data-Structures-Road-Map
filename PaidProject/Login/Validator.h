//
// Dependencies : NONE
//

#ifndef VALIDATOR_H
#define VALIDATOR_H

#include "../Helpers/Input.h"
#include "../Helpers/Algorithm.h"
#include "../Helpers/Time.h"


/*
 * Valid CNIC or email, Password validations, re-enter the password, successfully identified Registration
   data members signup details, data operation from files
   Question 1:
 */

bool ValidatePassword(string &, const int);
bool ValidateEmail(string &, string);
bool ValidateCnic(string &);
bool ValidateContactNumber (string&);
bool ValidateAccountNumber (string& , const int);

string GetPassword(const char *, bool);
string GetEmail(const char *);
string GetCnic(const char *);
string GetContactNumber (const char*);
string GetAccountNumber (const char* , int );
Time GetTime (const char* , const char*);

/* Validates Password
   @ Params : std::string & pass , const int len
   @ Returns : Boolean */
bool ValidatePassword(string &password, const int length) {
    bool isValid = false;
    // Length Validator
    if (password.length() < length) return false;

    //  Digit Validator
    const std::string NUMBERS = "0123456789";
    for (int i = 0; i < password.length(); i += 1)
        for (int idx = 0; idx < NUMBERS.length(); idx += 1)
            if (password[i] == NUMBERS[idx]) isValid = true;

    if (!isValid) return false;
    isValid = false;

    // Case Validator
    bool hasUpperCase = false, hasLowerCase = false;
    const string albet_l = "abcdefghijklmnopqrstuvwxyz";
    const string albet_u = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; i < password.length(); i += 1)
        for (int idx = 0; idx <= 26; idx += 1) {
            if (password[i] == albet_l[idx]) hasLowerCase = true;
            if (password[i] == albet_u[idx]) hasUpperCase = true;
        }
    isValid = hasLowerCase && hasUpperCase;

    if (!isValid) return false;
    isValid = false;

    // Symbol Validator
    const string SYMBOLS = "!@#$%^&*(){}[]?<>_";
    for (int i = 0; i < password.length(); i += 1)
        for (int idx = 0; idx < SYMBOLS.length(); idx += 1)
            if (password[i] == SYMBOLS[idx]) isValid = true;

    for (int  i = 0 ; i < password.length() ; i += 1)
        if (password[i] == ' ') isValid = false;

    return isValid;
}


/* Validates Emails
@ Params : std::string & email , std::string match
@ Returns : Boolean */
bool ValidateEmail(string &email, string match) {
    const int minEmailLen = 2;
    bool isValid = false;

    // Blank Space Validator
    for (int  i = 0 ; i < email.length() ; i += 1)
        if (email[i] == ' ') return false;

    // Length Validator
    int len = email.length() - match.length();
    isValid = len >= minEmailLen;

    if (!isValid) return false;
    isValid = false;

    // match Validator
    int emailIdx = email.length(), matchIdx = match.length();
    while (matchIdx--) {
        emailIdx -= 1;
        if (email[emailIdx] != match[matchIdx]) return false;
    }

    // email Body Validator
    int symbolCount = 0;
    const string SYMBOLS = "!#$%^&*(){}[]?<>";
    for (int i = 0; i < email.length(); i += 1) {
        for (int idx = 0; idx < SYMBOLS.length(); idx += 1)
            if (email[i] == SYMBOLS[idx]) return false;
        if (email[i] == '@') symbolCount += 1;
    }

    isValid = symbolCount == 1;
    return isValid;
}

/*
 Validates Cnic Number
  @ Params : std::string cnic
  @ Returns : Boolean
*/
bool ValidateCnic(string &cnic) {
    bool isValid = false;

    // Length Validator
    if (cnic.length() != 13) return false;

    // Numbers Validator
    const std::string NUMBERS = "0987654321";
    for (int i = 0; i < cnic.length(); i += 1) {
        bool isFound = false;
        for (int idx = 0; idx < NUMBERS.length(); idx += 1)
            if (cnic[i] == NUMBERS[idx]) isFound = true;
        if (!isFound) return false;
    }

    isValid = NUMBERS[0] != cnic[0];
    return isValid;
}

/* Validates Contact Number
   @ Params : std::string & pass
   @ Returns : Boolean */
bool ValidateContactNumber(string &contactNumber) {
    if (contactNumber.length() != 11) return false;

    const string NUMBER = "0987654321";
    bool isValid ;
    for (int  i = 0  ; i < contactNumber.length() ; i += 1) {
        isValid = false;
        for (int idx = 0; idx < NUMBER.length(); idx += 1)
            if (contactNumber[i] == NUMBER[idx]) isValid = true;
        if (!isValid) break;
    }

    return isValid;
}

/* Returns Valid Password
@ Params : const char* message
@ Returns : string */
string GetPassword(const char *message, bool reCheck = true) {
    string password, reTypePassword;
    bool isValid = false;
    bool isMatch = false;

        do
    {
            do
        {
            password = GetString(message);
            isValid = ValidatePassword(password, 8);
            if (!isValid) PrintError("Invalid Password  ( Example : Qwerty47$ ) \n");
        }
            while (!isValid);

        if (!reCheck) return password;

        reTypePassword = GetString("Retype password : ");
        isMatch = password == reTypePassword;
        if (!isMatch) PrintError("2nd password is not matching with 1st one please retype again");
    }
        while (!isMatch);

    return password;
}

/* Returns Valid Email
   @ Params : const char* message
   @ Returns : string */
string GetEmail(const char *message) {
    string email;
    bool isValid = false;
        do
    {
        email = GetString(message);
        isValid = ValidateEmail(email, "@gmail.com");
        if (!isValid) PrintError("Invalid email address please enter correct one Example : abc123@gmail.com ");
    }
        while (!isValid);
    return email;
}

/* Validates Account Number
   @ Params : std::string & pass , const int len
   @ Returns : Boolean */
bool ValidateAccountNumber(string &accountNumber ,const int len) {
    if (accountNumber.length() != len) return false;
    const string NUMBER = "1234567890";
    bool isFound ;
    for (int  i = 0 ; i < accountNumber.length() ; i += 1) {
        isFound = false;
        for (int idx = 0; idx < NUMBER.length(); idx += 1)
            if (accountNumber[i] == NUMBER[idx]) isFound = true;
        if (!isFound) return false;
    }
    return isFound;
}

/* Returns Valid Account Number
   @ Params : const char* message , int length
   @ Returns : string */
string GetAccountNumber(const char * , int len) {
    bool isValid ;
    string accountNumber ;
    do
    {
        accountNumber = GetString("Enter Account Number : ");
        isValid = ValidateAccountNumber(accountNumber , len);
        if (!isValid) {
            cout << "\n Account number must have " << len << " digits \n";
            PrintError("Invalid account Number ");
        }
    }
    while (!isValid);
    return accountNumber;
}

/* Returns Valid Password
   @ Params : const char* message
   @ Returns : string */
string GetCnic(const char *message) {
    string cnic;
    bool isValid = false;
        do
    {
        cnic = GetString(message);
        isValid = ValidateCnic(cnic);
        if (!isValid) PrintError("Invalid Cnic Number ! cnic should be 13 digits ");
    }
        while (!isValid);
    return cnic;
}

/* Returns Valid Contact Number
@ Params : const char* message
@ Returns : string */
string GetContactNumber(const char * message) {
        string contactNumber ;
        bool isValid ;
        do
    {
        contactNumber = GetString(message);
        isValid = ValidateContactNumber(contactNumber);
        if (!isValid)
            PrintError("Invalid Contact Number (number should be 11 digits) ! \n");
    }
        while (!isValid);
        return contactNumber;
}

/* Returns Valid time
  @ Params : const char* message , const char* err
  @ Returns : Time */
Time GetTime (const char* message , const char* err) {
    Time timeNow , inputTime;
    cout << "\n" << message << "\n";
    do
    {
        cin >> inputTime;
        if (timeNow > inputTime ) {
            cout << "\n Time Now : " << timeNow << "\n";
            PrintError(err);
        }
    }
    while (timeNow > inputTime);
    return inputTime;
}

#endif //VALIDATOR_H
