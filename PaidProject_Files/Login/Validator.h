//
// Dependencies : NONE
//

#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <iostream>
#include <string>

// @ Base abstract class's for all Validation
namespace _Validator {

    // @ Validator Base Class
    class IValidator {
    public:
        virtual bool Validate(std::string &) = 0;
        virtual ~IValidator()  = default;
    };

    // @ Validator Decorator
    class Decorator : public IValidator{
    public:
        explicit Decorator(IValidator *validator)  {this->validator = validator;}
        virtual bool Validate(std::string &str) override { return  validator->Validate(str); }
        ~Decorator() override { delete validator;}
    private:
        IValidator *validator;
    };
}
#endif //VALIDATOR_H
