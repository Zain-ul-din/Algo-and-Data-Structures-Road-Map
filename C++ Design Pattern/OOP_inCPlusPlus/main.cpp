#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<chrono>

#include<map>

// Hello world in c++

// Modern c++
// C++ 2020 :-)

#include "HTML.h"

using std::cin;
using std::cout;
using std::string;
using std::stringstream;
using std::vector;
using std::map;

using namespace std;
using namespace chrono;




int main(){
    int itr=0;
    bool midFound = false;
   // MakeFile("index.text");
   vector<string> rawData = ReadFile("index.text");
   vector<string> HTMLData = ToHtml(rawData);
  for(auto i : HTMLData){
      IndentCode(itr);
      if(itr > 6) midFound = true;
      if(itr == 1) midFound = false;

      itr = (midFound) ? --itr : ++itr;
      cout<<i<<std::endl;
  }
}



// 98 > a start 65 > A start

// if in 0 or 10 then Number

// > 0 symbol