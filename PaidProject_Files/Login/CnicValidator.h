//
// Dependencies : PasswordValidator.h => namespace _Validator
//

#ifndef CNICVALIDATOR_H
#define CNICVALIDATOR_H

#include "./Validator.h"

// Cnic Number Validator

/*  API'S  */

/*
 Validates Cnic Number
   @ Params : std::string cnic
   @ Returns : Boolean
 */
bool ValidateCnic (std::string&);


/*
 TODOS:
        Validate CNIC must have 13 digits
*/

/*
 * PRIVATE
 */
namespace _CinicValidator { using namespace _Validator;
    class LengthValidator;
    class CaseValidator;
}

// @ Cnic Length Validator
class _CinicValidator::LengthValidator : public _Validator::IValidator {
public:
       LengthValidator(unsigned int length) {this->length = length;}
       virtual bool Validate (std::string& cnic) override { return cnic.length() == this->length;}
private:
    unsigned int length;
};

// @ Cnic Case Validator
class _CinicValidator::CaseValidator : public _Validator::Decorator {
public:
    CaseValidator (IValidator* decorator) : Decorator(decorator) {}
    virtual bool Validate (std::string &cnic) override {
        if (!Decorator::Validate(cnic)) return false;
        return CaseValidator_Helper(cnic);
    }
private:
    static bool CaseValidator_Helper(std::string& cnic){
        const std::string NUMBERS = "0987654321";
        for (int i = 0 ; i < cnic.length() ; i += 1) {
            bool isFound = false;
            for (int idx = 0; idx < NUMBERS.length(); idx += 1)
                if (cnic[i] == NUMBERS[idx]) isFound = true;
            if (!isFound) return false;
        }

        return cnic[0] != NUMBERS[0];
    }
};

/*
 Validates Cnic Number
   @ Params : std::string cnic
   @ Returns : Boolean
 */
bool ValidateCnic (std::string& cnic) {
    using namespace _CinicValidator;
    IValidator* cnicValidator =
     new CaseValidator(
     new LengthValidator(13)
    );
    bool res = cnicValidator->Validate(cnic);
    delete cnicValidator;
    return res;
}

#endif //CNICVALIDATOR_H
