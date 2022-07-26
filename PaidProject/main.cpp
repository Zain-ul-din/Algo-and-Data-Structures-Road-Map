
/*
 * Project Title : Oladoc HealthCare Clone
 * Language : c++
 * Dependencies : NONE
 */

#define _CRT_SECURE_NO_WARNINGS

#include <ostream>
#include "./OlaDoc.h"

class doc {
    public:
     doc (int number) : number (number) {}
     doc () {this->number = 0;}
     // using namespace std;
    private:
      int number;
};

// Driver Code
int main () {
    OlaDoc olaDoc;
    olaDoc.RunApplication();
    return 0;
}



