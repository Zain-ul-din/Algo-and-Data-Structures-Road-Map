//
// Dependencies : NONE
//

#ifndef SAVESYSTEM_H
#define SAVESYSTEM_H

#include <iostream>
#include <fstream>

using namespace std;

bool IsEmptyFile(std::ifstream& pFile) { return pFile.peek() == ifstream::traits_type::eof(); }

#endif //SAVESYSTEM_H


//13-digit CNIC