//
// Dependencies : NONE
//

#ifndef SAVESYSTEM_H
#define SAVESYSTEM_H

#include <iostream>
#include <fstream>

using namespace std;

// @ SaveSystem Base Class
template<class Type>
class ISaveAble  {
public:
    virtual string ToString () = 0;
    virtual Type ToObj (std::string& objStr) = 0;
};

bool IsEmptyFile(std::ifstream& pFile) { return pFile.peek() == ifstream::traits_type::eof(); }

#endif //SAVESYSTEM_H


//13-digit CNIC