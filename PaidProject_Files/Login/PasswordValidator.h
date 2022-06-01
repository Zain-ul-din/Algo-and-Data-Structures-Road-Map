//
// Dependencies : Validator
//

#ifndef PASSWORD_VALIDATOR_H
#define PASSWORD_VALIDATOR_H

#include "./Validator.h"

// Password Validator

/*  API'S  */

/* Validates Password
 @ Params : std::string & pass , const int len
 @ Returns : Boolean */
bool ValidatePassword (std::string& , const int);


/*
 TODOS:
        Password must be 8 characters long and the use of a minimum of one special character,
        uppercase, lowercase, and the numeric digit is a must.
*/

/*
 * @ PRIVATE
 */
namespace _PasswordValidator {
    using namespace _Validator;
    class LengthValidator ;
    class DigitValidator;
    class CaseValidator;
    class SymbolValidator;
}

//@ Password Length Validator
class _PasswordValidator::LengthValidator : public _Validator::IValidator {
public:
    LengthValidator(int length) {this->length = length;}
    virtual bool Validate (std::string& password) override { return password.length() == this->length;}
private:
    int length;
};

//@ Password Digit Validator
class _PasswordValidator::DigitValidator : public  _Validator::Decorator {
public:
    DigitValidator(IValidator* decorator) : Decorator(decorator) {}
    virtual bool Validate (std::string& password) override {
        if(!Decorator::Validate(password)) return false;
        return DigitValidator_Helper(password);
    }
private:

    //@ Helper
    static bool DigitValidator_Helper (std::string& password) {
        const  std::string NUMBERS =  "0123456789";
        for (int i = 0 ; i < password.length() ;  i += 1)
            for (int idx = 0 ; idx < NUMBERS.length() ; idx += 1)
                if (password[i] == NUMBERS[idx]) return true;
        return false;
    }
};

//@ Password Case Validator
class _PasswordValidator::CaseValidator : public _Validator::Decorator{
public:
    CaseValidator(IValidator* decorator) : Decorator(decorator) {}
    virtual bool Validate (std::string& password) override{
        if (!Decorator::Validate(password)) return false;
        return CaseValidate_Helper(password);
    }
private:

#define ALPA_MAX 26
    // @ Helper
    static bool CaseValidate_Helper(std::string &password) {
        bool hasUpperCase = false, hasLowerCase = false;
        const std::string albet_l = "abcdefghijklmnopqrstuvwxyz";
        const std::string albet_u = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

        for (int i = 0; i < password.length(); i += 1)
            for (int idx = 0; idx <= ALPA_MAX; idx += 1) {
                if (password[i] == albet_l[idx]) hasLowerCase = true;
                if (password[i] == albet_u[idx]) hasUpperCase = true;
            }
        return hasLowerCase && hasUpperCase;
    }
#undef ALPA_MAX
};

//@ Password Symbol Decorator
class _PasswordValidator::SymbolValidator : public _Validator::Decorator {
public:
    SymbolValidator(IValidator* decorator) : Decorator(decorator) {}
    virtual bool Validate (std::string& password) override {
        if (!Decorator::Validate(password)) return false;
        return ValidateSymbols_Helper(password);
    }
private:

    //@ Helper
    static bool ValidateSymbols_Helper (std::string& password) {
        const std::string SYMBOLS = "!@#$%^&*(){}[]?<>";
        for (int i =0 ; i < password.length() ; i += 1)
            for (int idx = 0 ; idx < SYMBOLS.length() ; idx += 1) {
                if (password[i] == SYMBOLS[idx])
                    return true;
            }
        return false;
    }
};

    /* Validates Password
    @ Params : std::string & pass , const int len
    @ Returns : Boolean */
    bool ValidatePassword (std::string &password , const int length ) {
        using namespace _PasswordValidator;
        IValidator* passwordValidator =
                  new SymbolValidator(
                  new CaseValidator(
                  new DigitValidator(
                  new LengthValidator( length
        ))));
        bool res = passwordValidator->Validate(password);
        delete passwordValidator;
        return res;
    }

#endif //PASSWORD_VALIDATOR_H
