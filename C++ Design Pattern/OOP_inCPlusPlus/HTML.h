
#ifndef OOP_INCPLUSPLUS_HTML_H
#define OOP_INCPLUSPLUS_HTML_H


#include "HTMLHelper.h"
#include <fstream>
#include<string>
#include <vector>

using std::ofstream;
using std::ifstream;
using std::ios;

std::vector<std::string> ToHtml(std::vector<std::string>& vec ){
    if(vec.empty()) return vec;
    std::vector<std::string> htmlList;
    GetStarterHtml(htmlList , *vec.begin());
    *vec.begin() = "";
   for(auto& line : vec)
      if(line != "") for(auto& str : LinetoHTML(line))
           htmlList.push_back(str);

    GetEndHtml(htmlList);
    return htmlList;
}


void MakeFile(const std::string fileName){
   ofstream out;
   out.open(fileName,ios::out);
    if(out.is_open()) return;
}

std::vector<std::string> ReadFile(const std::string fileName){
    std::vector<std::string> vec;
    ifstream in;
    std::string ss;
    in.open(fileName,ios::in);
    while(!in.eof()){
        while(std::getline(in , ss)){
           vec.push_back(ss);
        }
    }
    return vec;
}

void IndentCode(int count){
    for(int i=0;i<count;++i)std::cout<<" ";
}
#endif //OOP_INCPLUSPLUS_HTML_H
