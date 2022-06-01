//
// Created by 97152 on 31/05/2022.
//

#ifndef OLADOC_H
#define OLADOC_H

#include "./Manager/OldaDoc_Manager.h"

#define MAX 100000

using namespace std;

class OlaDoc {
public:
     OlaDoc() {
         doctors.SignUp();
     }

private:
      Doctors doctors;
};



#endif //OLADOC_H
