//
// Dependencies : Validator
//

#ifndef EMAIL_VALIDATOR_H
#define EMAIL_VALIDATOR_H

#include "./Validator.h"

// Email Validator

/*  API'S  */

/* Validates Emails
    @ Params : std::string & email , std::string match
    @ Returns : Boolean */
bool ValidateEmail (std::string& , std::string );

/*
 TODOS:
        validate email
*/

/*
 * PRIVATE
 */
namespace _EmailValidator {     using namespace _Validator;
    class LengthValidator;
    class EmailValidator;
}

// @ Email Length Validator
class _EmailValidator::LengthValidator : public _Validator::IValidator {
public:
    LengthValidator(int matchLen , int minLen) : matchLen(matchLen) , minLen(minLen) {}
    bool Validate(std::string &email) override {
        int len = email.length() -  matchLen;
        return len >= minLen;
    }
private:
    unsigned int matchLen  ,  minLen;
};

// @ Email Validator
class _EmailValidator::EmailValidator : public _Validator::Decorator {
public:
    EmailValidator(IValidator *validator , std::string match) : Decorator(validator)
    {this->match = match;}

    virtual bool Validate(std::string &email) override {
        if (!Decorator::Validate(email)) return false;
        return EmailValidator_Helper(email , this->match);
    }

private:
    std::string match;
    static bool EmailValidator_Helper (std::string& email , std::string match) {
       int emailIdx = email.length()  , matchIdx = match.length();
       while (matchIdx--) {
            emailIdx -= 1;
           if (email[emailIdx] != match[matchIdx]) return false;
       }
       return true;
    }
};

/* Validates Emails
    @ Params : std::string & email , std::string match
    @ Returns : Boolean */
bool ValidateEmail (std::string& email, std::string match) { using namespace _EmailValidator ;
     const int minEmailLen = 2;

     IValidator* emailValidator =
     new EmailValidator(
     new LengthValidator(match.length() , minEmailLen)
      , match);

     bool res = emailValidator->Validate(email);
     delete emailValidator;
     return res;
}

#endif //EMAIL_VALIDATOR_H
