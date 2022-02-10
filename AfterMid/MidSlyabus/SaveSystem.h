//
// Created by Zain_uldin on 10/02/2022.
//

/*
  How to use ?
  -> Inherit custom class from base class SaveSystem 
  -> Pass all data members of custom class to SaveSystem::ToString()
  -> Make Container that's implement Interface IIterator and overider the function of base class
  -> Use SaveData (that's take fileName , IIterator) function to save to file  
*/

#ifndef MIDSLYABUS_SAVESYSTEM_H
#define MIDSLYABUS_SAVESYSTEM_H

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <functional>
#include <fstream>
#include <iterator>
#include <algorithm>

namespace Randoms {
    class IIterator;
    class SaveSystem;
    void SaveData(const char[] , IIterator& );

    // Save System Base Class ( derive your're Class from Base class)
    class SaveSystem {
    public:
          // Pass All child class members to it
          template<class... Params>
          void ToString(Params... params){
              std::stringstream ss;
              ([&](auto& data){
                  ss << data << _separator;
              }(params),...);
              __str = ss.str();
              __str.pop_back();
              __FilterString(__str);
          }

        // string format of data
        char _separator = '~';
        char _space = '_';

        friend void SaveData(const char[], IIterator&);

    private:
        std::string __str;

        //@ Private

        std::string __FilterString(std::string &  str){
            if(str.empty())
                return "UNKNOWN_TYPE";
            std::string filterString (str);
            for(auto itr : filterString)
                filterString.push_back(itr == ' ' ? _space : itr);
            return filterString;
        }

    }; // Save System

    //@ Interface
    class IIterator{
      public:
            virtual void ForEach(std::function<void(SaveSystem& obj)>) = 0;
    };

    // Save System
    void SaveData(const char fileName[] , IIterator& container){

        std::ofstream out;
        out.open(fileName,std::ios::out);
        container.ForEach([&](SaveSystem& obj){
         out << obj.__str << "\n";
        });
        out.close();
    }
}

#endif //MIDSLYABUS_SAVESYSTEM_H
