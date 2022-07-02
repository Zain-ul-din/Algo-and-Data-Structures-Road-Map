//
// Created by 97152 on 04/06/2022.
//

#ifndef PAIDPROJECT_PAYMENT_H
#define PAIDPROJECT_PAYMENT_H

#include "../Helpers/Input.h"
#include "./Patient.h"

class Payment {
public:

    static double ReChargeAccount () {
            int choice = 0;
            double returnAmount = 0;
            for (; choice != 3 ;)
        {
            cout << "\n -- Select Payment Method \n";
            cout << "\n  - Bank Transfer  - 0\n";
            cout << "\n  - E-Transaction  - 1\n";
            cout << "\n  - Exit           - 3\n";
            choice = GetInput<int>("Enter choice _ ");
            switch(choice )
           {
               case 0:
                   return BankTransfer();
               case 1:
                   return ETransaction();
               case 3:
                   cout << " -- Exit \n";
               case 4:
                   PrintError("Invalid Choice");
           }
        }
        cout << "\n -- " << returnAmount << " Rs . Has been Charged to you're account \n";
        return returnAmount;
    }

private:
       static double BankTransfer () {
           cout << "\n -- Bank Transfer \n";
           cout << "\n  - PayPak    - 0 \n";
           cout << "\n  - Union Pay - 1 \n";
           cout << "\n  - Exit      - 2 \n";
           int choice = GetInput<int> ("Enter Choice : ");
           string accNum  , zipCode  , name , securityCode;
           double amount = 0;
           switch (choice) {
               case 0:
                   cout << "\n Welcome to PayPak \n";
                   name = GetString("Enter name on card : ");
                   accNum = GetAccountNumber("Enter PayPak 11 digits Account Number : " , 11);
                   zipCode = GetInput<string>("Enter Zip Code : ");
                   securityCode = GetString("Enter Security Code : ");
                   amount = GetInput<double>("Enter Amount : ");
                   break;
               case 1:
                   cout << "\n Welcome to Union Pay \n";
                   name = GetString("Enter name on card : ");
                   accNum = GetAccountNumber("Enter PayPak 11 digits Account Number : " , 11);
                   zipCode = GetInput<string>("Enter Zip Code : ");
                   securityCode = GetString("Enter Security Code : ");
                   amount = GetInput<double>("Enter Amount : ");
                   break;
               case 2:
                   cout << "\n -- Exit \n";
                   break;
               default:
                   PrintError("Invalid Choice !!");
           }
           return amount;
       }

    static double ETransaction () {
        cout << "\n -- E-Transaction  \n";
        cout << "\n  - Jazz-Cash   - 0\n";
        cout << "\n  - Easy-Paisa   - 1\n";
        cout << "\n  - Exit        - 2\n";
        int choice = GetInput<int>("Enter Choice : ");
        string acc_number ;
        double amount = 0 ;
        int pin;
        switch(choice) {
            case 0:
                cout << "\n Welcome to Jazz Cash \n";
                acc_number = GetAccountNumber("Enter Jazz Account Number 11 digit : " , 11);
                pin = GetInputInRange(10000 , 99999 , "Enter pin : " , "Invalid pin");
                amount = GetInput<double>("Enter Amount : ");
                break;
            case 1:
                cout << "\n Welcome to Jazz Cash \n";
                acc_number = GetAccountNumber("Enter Jazz Account Number 11 digit : " , 11);
                pin = GetInputInRange(10000 , 99999 , "Enter pin : " , "Invalid pin");
                amount = GetInput<double>("Enter Amount : ");
                break;
            case 2:
                cout << "\n -- Exit \n";
            break;
            default:
                PrintError("Invalid Choice !!");
        }
        return amount;
    }
};

#endif //PAIDPROJECT_PAYMENT_H
