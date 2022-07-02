//
// Created by 97152 on 04/06/2022.
//

#ifndef PAIDPROJECT_PAYMENT_H
#define PAIDPROJECT_PAYMENT_H

#include "../Helpers/Input.h"

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

                   break;
               case 1:
                   break;
               case 3:
                   cout << " -- Exit \n";
               case 4:
                   PrintError("Invalid Choice");
           }
        }
        cout << "\n" << returnAmount << " Rs . Has been Charged to you're account \n";
        return returnAmount;
    }

private:
       double BankTransfer ();
       double ETransaction ();
};

#endif //PAIDPROJECT_PAYMENT_H
