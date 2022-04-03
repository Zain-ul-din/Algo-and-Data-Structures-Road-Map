//
// Created by Zain_uldin on 10/02/2022.
//


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
              std::cout <<"-"<< __str<<"-";
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

using namespace Randoms;

class Data : public SaveSystem{
public:
    Data(int id, const std::string &name) : id(id), name(name) {
    	std::cout << id << " " << name << " \n";
        Save();
    }

    void Save(){
        this->ToString(id ,name);
    }


private:
    int id;
    std::string name;
};

class Container : public IIterator{
public:
    void ForEach(std::function<void(SaveSystem &)> function) override {
           for(int i =0 ; i <newData.size(); i++){
           	   
               function(static_cast<SaveSystem&>(newData[i]));
           }
    }
    std::vector<Data> newData;
};

int main (){

    Container container;
    container.newData.push_back(Data{2, "Name"});
    container.newData.push_back(Data{25, "Name1"});
    container.newData.push_back(Data{22, "Name2"});
    container.newData.push_back(Data{24, "Name3"});
    container.newData.push_back(Data{23, "Name4"});

    SaveData("MyFile.text" , container);
}

