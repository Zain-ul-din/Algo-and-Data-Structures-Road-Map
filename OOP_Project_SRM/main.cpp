#include "./Init.h"
#include "./StudentReportManager.h"


using namespace StudentReportManager;

#define CLS system("cls");
#define END_L Input::Print("\n");
#define PAUSE system("pause");

// Driver Code
int main() {
    INIT();
#define RM ReportManager::Instance()
    RM->Init();

do{
    Utilities::Menu menu({
        "\n ~ Admin           : 0\n" ,
        " ~ Update Result   : 1\n" ,
        " ~ Update Students : 2\n" ,
        " ~ Show Result     : 3\n" ,
    });

    int choice = menu.GetChoice("\n >> Enter Choice _ ");
    switch (choice) {
        case 0:
             RM->AdminMenu(); END_L PAUSE CLS
            break;
        case 1:
             RM->ResultReportMenu(); END_L PAUSE CLS
            break;
        case 2:
            RM->StudentReportMenu(); END_L PAUSE CLS
            break;
        case 3:
            RM->PrintResultMenu(); END_L PAUSE CLS
            break;
        default:
            Input::Print(" ... Never Mind :-) \n" ,pink);
    }
}while (!Input::GetChoice("\n >> Do You Want to Exit Y/N _ "));

#undef CLS
#undef END_L
#undef PAUSE
#undef RM
    return 0;
}

// Dependencies
